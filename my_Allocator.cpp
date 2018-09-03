#include "Allocator.hpp"
// #define DEBUG
#ifdef DEBUG
#include <cstdio>
#endif


#ifndef ALIGN
#define ALIGN(x , a) (((x) + (a) - 1) & ~((a) - 1))
#endif
Fc::Allocator::Allocator(size_t page_size, size_t block_size, size_t align_size)
    :pagelist(nullptr), blocklist(nullptr){
        reset(page_size, block_size, align_size);


}

void Fc::Allocator::reset(size_t _page_size, size_t _block_size, size_t _align_size){
    free_all();
    page_size = _page_size;
    block_size = _block_size;
    align_size = _align_size;
    size_t min_size = block_size > sizeof(BlockHeader)? block_size: sizeof(BlockHeader);
    min_size = ALIGN(min_size, align_size);
    block_size = min_size;
    page_per_blocks = (_page_size - sizeof(PageHeader)) / block_size;
    page_cnts = block_cnts = free_block_cnts = 0;
    #ifdef DEBUG
    printf("%lu \n", block_size);
    #endif
}

void Fc::Allocator::get_new_page(){
    PageHeader* tmp_pagelist = reinterpret_cast<PageHeader*>(new uint8_t[page_size]);
    tmp_pagelist->next = pagelist;
    pagelist = tmp_pagelist;
    page_size++;
    block_cnts += page_per_blocks;
    free_block_cnts += page_per_blocks;
    BlockHeader *tmp = pagelist->block();
    for(int i = 0; i < page_per_blocks - 1; i++){
        tmp->next = Next(tmp);
        tmp = Next(tmp);
    }
    tmp->next = blocklist;
    blocklist = pagelist->block();

}

Fc::BlockHeader* Fc::Allocator::Next(Fc::BlockHeader* now){
    #ifdef DEBUG
    // printf("%p %lu\n",now, block_size);
    #endif
    return reinterpret_cast<BlockHeader*>(reinterpret_cast<uint8_t*>(now) + block_size);

}

void *Fc::Allocator::allocate(){
    if(!free_block_cnts){
        get_new_page();
    }
    free_block_cnts--;
    BlockHeader* ret = blocklist;
    blocklist = blocklist->next;
    return ret;
}

void Fc::Allocator::free(void *ptr){
    BlockHeader *tmp = reinterpret_cast<BlockHeader*>(ptr);
    tmp->next = blocklist;
    blocklist = tmp;
    free_block_cnts++;
}
void Fc::Allocator::free_all(){
    PageHeader *tmp = pagelist;
    while(tmp){
        PageHeader* now = tmp;
        tmp = tmp->next;
        delete[] reinterpret_cast<uint8_t*>(now);
    }
    pagelist    = nullptr;
    blocklist   = nullptr;

    page_cnts       = 0;
    block_cnts      = 0;
    free_block_cnts = 0; 

}
Fc::Allocator::~Allocator(){
    free_all();
}