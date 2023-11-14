//
//  ECVirtualMemory.cpp
//  
//
//  Created by Yufeng Wu on 8/30/23.
//  Implement popular page replacement algorithms

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include "ECVirtualMemory.h"
using namespace std;


//*****************************************************************************
// Virtual memory: consists of memory pages and a main memory with limited capacity
// Page: represented by an integer; main memory can hold up to K pages
// Page replacement: when the main memory reaches its limit (i.e., having K pages) 
// and a new page (not currently in memory) is to be add, 
// then need to swap out one current page to make room for this new page
// This class: use OPT or LRU algorithm

// Your code here

bool ECVirtualMemory::ECPagingIsMiss(int page){
    return memory.find(page) == memory.end();
}

bool ECVirtualMemory::ECIsPageReplacing(int page){
    return GetNumPagesInMainMemory() == memCapacity && memory.find(page) == memory.end();
}

void ECVirtualMemory::AccessPage(int page){
    listPageRequests.push_back(page);
    
    if (ECPagingIsMiss(page)){
        ++numPageFaults;
    }

    if (ECIsPageReplacing(page)){
        ECPageReplacementLRU(page);
    } else {
        ECPageAccessLRU(page);
    }
}

void ECVirtualMemory::ECPageAccessLRU(int page){
    ++lastPageAccessTime;

    bool fIn = true;
    if (memory.find(page) == memory.end()){
        memory.insert(page);
        fIn = false;
    }
    
    if (fIn == true){
        int tmLast = mapPageLastAccessTime[page];
        mapLastAccessTimePage.erase(tmLast);
    }
    
    mapLastAccessTimePage[lastPageAccessTime] = page;
    mapPageLastAccessTime[page] = lastPageAccessTime;
}

void ECVirtualMemory::ECPageReplacementLRU(int page){
    int pageSwap = mapLastAccessTimePage.begin()->second;
    
    if (memory.find(pageSwap) == memory.end() || mapPageLastAccessTime.find(pageSwap) == mapPageLastAccessTime.end()){
        throw std::string("Bad page");
    }
    
    mapLastAccessTimePage.erase(mapLastAccessTimePage.begin());
    mapPageLastAccessTime.erase(pageSwap);
    memory.erase(pageSwap);
    
    ++lastPageAccessTime;
    memory.insert(page);
    
    mapLastAccessTimePage[lastPageAccessTime] = page;
    mapPageLastAccessTime[page] = lastPageAccessTime;
}

int ECVirtualMemory::RunOpt(){
    numPageFaults = 0;
    lastPageAccessTime = 0;
    mapPageLastAccessTime.clear();
    mapLastAccessTimePage.clear();
    memory.clear();

    for (int i = 0; i < listPageRequests.size(); ++i){
        if (ECPagingIsMiss(listPageRequests[i])){
            cout << "Page: " << listPageRequests[i] << endl;
            ++numPageFaults;
        }
        
        ECPageReplacementOpt(i);
    }
    
    return numPageFaults;
}

void ECVirtualMemory::ECPageReplacementOpt(int page){
    if ((int)memory.size() < memCapacity){
        memory.insert(listPageRequests[page]);
        return;
    }
    
    if (memory.find(listPageRequests[page]) != memory.end()){
        return;
    }

    set<int> pagesNotYetSeen = memory;
    
    for (int i = page + 1; i < (int)listPageRequests.size(); ++i){
        if (pagesNotYetSeen.size() == 1){
            break;
        }
        
        pagesNotYetSeen.erase(listPageRequests[i]);
    }
    
    int pageSwap = *pagesNotYetSeen.begin();
    memory.erase(pageSwap);
    memory.insert(listPageRequests[page]);
}

int ECVirtualMemory::GetNumPagesInMainMemory() const{
    return memory.size();
}

int ECVirtualMemory::GetNumPageFaults() const{
    return numPageFaults;
}