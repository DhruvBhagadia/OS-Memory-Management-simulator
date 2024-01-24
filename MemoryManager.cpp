#include <cstdint>
#include <iostream>

/*
Classes: 
1. Memory Manager
2. TLB
3. Page Table

structs: 
1. virtual address
2. physical address

typedef struct VirtualAddress {



} VirtualAddress;


class MemoryManager {
TLB obj;
PageTable obj;

PhysicalAdd getPhysicalAddress (VirtualAdd virtual_add) {
// logic to use TLB and PageTable
}

};

*/

// Designing and implementing TLB:  

class VirtualAddress {
    public:

    VirtualAddress(uint32_t add): address(add) {};

    uint32_t getPageNumber() {
        return ((address & page_no_mask) >> 12);
    }

    uint32_t getOffset() {
        return (address & offset_mask);
    }

    static constexpr uint32_t page_no_mask = 0xFFFFF000; //1111.....000
    static constexpr uint32_t offset_mask = 0x00000FFF; //000...1111

    private: 

    uint32_t address; //20 bit page number, 12 bit offset
};

bool testVirtualAddrGen() {
    uint32_t page_num = 200;
    uint32_t offset = 20;
    uint32_t address = (page_num << 12) | offset;

    VirtualAddress vaddr(address);

    return (vaddr.getPageNumber() == page_num) && (vaddr.getOffset() == offset);
}

int main() {
    std::cout << testVirtualAddrGen() << std::endl;
    return 0;
}
