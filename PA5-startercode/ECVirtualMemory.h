//
//  ECVirtualMemory.h
//  
//
//  Created by Yufeng Wu on 8/30/23.
//  Port the page replacement code to the ECVirtualMemory class 

#ifndef ECVirtualMemory_h
#define ECVirtualMemory_h

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

//*****************************************************************************
// Virtual memory: consists of memory pages and a main memory with limited capacity
// Page: represented by an integer; main memory can hold up to K pages
// Page replacement: when the main memory reaches its limit (i.e., having K pages) 
// and a new page (not currently in memory) is to be add, 
// then need to swap out one current page to make room for this new page
// This class: use LRU algorithm

class ECVirtualMemory
{
public:
    // Capacity: max # of pages in main memory 
    ECVirtualMemory(int capacity) : memCapacity(capacity), lastPageAccessTime(0), numPageFaults(0) {}

    // Access a page in memory
    void AccessPage(int page);

    // Return the number of page faults if optimal page replacement algorithm is run 
    // (for all the page requests that have been accessed so far)
    // Caution: this would erase previous run of LRU; you need to re-initialize to run
    // to get proper results
    int RunOpt();

    // Return the number of pages in main memory
    int GetNumPagesInMainMemory() const;

    // Return the number of page faults so far (for LRU algorithm)
    int GetNumPageFaults() const;

    bool ECPagingIsMiss(int page);
    bool ECIsPageReplacing(int page);

    void ECPageAccessLRU(int page);
    void ECPageReplacementLRU(int page);
    void ECPageReplacementOpt(int page);

private:
    std::set<int> memory;

    int memCapacity;
    int lastPageAccessTime;

    std::map<int, int> mapPageLastAccessTime;
    std::map<int, int> mapLastAccessTimePage;

    int numPageFaults;
    
    std::vector<int> listPageRequests;
};


#endif /* ECVirtualMemory_h */
