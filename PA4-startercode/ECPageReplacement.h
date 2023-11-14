//
//  ECPageReplacement.h
//  
//
//  Created by Yufeng Wu on 5/25/23.
//

#ifndef ECPageReplacement_h
#define ECPageReplacement_h

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>


//*****************************************************************************
// Page: represented by an integer; memory can hold up to K pages
// Page replacement: when the memory reaches its limit (i.e., having K pages) and a new page (not currently in memory) is to be add, then need to swap out one current page to make room for this new page
// Memory: a collection of pages 
// There are many different page replacement algorithms.


//*****************************************************************************
// Initialize the virtual memory
// capacity: main memory capacity

void ECPagingInit(int capacity);

//*****************************************************************************
// Dump out memory and related info
// useful for debugging

void ECPagingDump();

//*****************************************************************************
// Is the page access a miss?
// pageCurrent: current page to access

bool ECPagingIsMiss(int pageCurrent);

//*****************************************************************************
// Decide if we need to perform page replacement
// pageRequest: the new page to access

bool ECIsPageReplacing(int pageRequest );

//*****************************************************************************
// Optimal page replacement algorithm: swap out the page whose next access is FURTHEST from the current time
// For testing purpose, if there is a tie, choose the page with the SMALLEST number to swap out
// Precondition: memory has reached its capacity and the current page is not in the memory
// listAllPageRequests: list of all page requests (ordered by request time)
// indexPageRequest: the index of the current page that is being accessed (you can assume this page is not currently in memory)
// After the function returns, memory is updated with one page swapped out and the page listAllPageRequests[indexPageRequest] is placed in the memory

void ECPageReplacementOpt( const std::vector<int> &listAllPageRequests, int indexPageRequest );

//*****************************************************************************
// Access a page that is either already in the memory or the memory is not full yet
// Precondition: memory has NOT reached its capacity or and the current page IS in the memory
// pageCurrent: current page to access (which is in memory)

void ECPageAccessLRU( int pageCurrent );

//*****************************************************************************
// The LRU page replacement algorithm: swap out the page which is least recently used
// Precondition: memory has reached its capacity, and the current page is not in the memory
// pageCurrent: current page to access (which is not in memory)
// After the function returns, memory is updated with one page swapped out and pageCurrent is placed in the memory

void ECPageReplacementLRU( int pageCurrent );


#endif /* ECPageReplacement_h */
