#pragma once
#include <cstddef>
#include <cstdint>

namespace Fc{

struct BlockHeader{
    BlockHeader *next;
};
struct PageHeader{
    PageHeader *next;
    BlockHeader* block(){
        return reinterpret_cast<BlockHeader*>(this + 1);
    }
};

class Allocator{
private:
    size_t page_size;
    size_t block_size;
    size_t align_size;
    PageHeader* pagelist;
    BlockHeader* blocklist;
    uint32_t page_per_blocks;
    uint32_t page_cnts;
    uint32_t block_cnts;
    uint32_t free_block_cnts;
public:
    void reset(size_t page_size, size_t block_size, size_t align_size);
    Allocator(size_t page_size, size_t block_size, size_t align_size);
    virtual ~Allocator();
    void free(void *);
    void free_all();
    void* allocate();
private:
    void get_new_page();
    BlockHeader* Next(BlockHeader *);
};



}