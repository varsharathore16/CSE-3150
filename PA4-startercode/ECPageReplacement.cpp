//
//  ECPageReplacement.cpp
//  
//
//  Created by Yufeng Wu on 5/25/23.
//  Implement popular page replacement algorithms

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include "ECPageReplacement.h"
using namespace std;

//*****************************************************************************

// Global variables definitions for the virtual memory
// YW: it is not such a good idea to use global variables; it would be better to place these as private data members of a class. But we haven't learned classes yet, so...

// Your code goes here 

// Global variables to represent virtual memory and main memory
int capacity;
set<int> mainMemory; // Set to store pages in main memory
map<int, int> pageAccessTime; // Map to store page access times
int accessCounter = 0;


//*****************************************************************************
// Now implement the functions for virtual memory here

// Initialize the main memory
void ECPagingInit(int _capacity) {
    capacity = _capacity;
    mainMemory.clear();
    pageAccessTime.clear();
}

// Dump Memory Status (for debugging, not used in grading)
void ECPagingDump() {
    cout << "Main Memory: ";
    for (int page : mainMemory) {
        cout << page << " ";
    }
    cout << endl;
}

// Check if accessing pageCurrent results in a page miss
bool ECPagingIsMiss(int pageCurrent) {
    return mainMemory.find(pageCurrent) == mainMemory.end();
}

// Check if requesting pageRequest would lead to page replacement
bool ECIsPageReplacing(int pageRequest) {
    return (int)mainMemory.size() == capacity && ECPagingIsMiss(pageRequest);
    // normmal return type of size() is unsigned integer, the (int) is a precuationary measure in case of subtracting 1 from 0, gives 2 billion something
    // gives a seg fault so if used with NULL, adding 1 gives 1 but subtracting 1 gives the seg fault bc of 2 billion #
}

// Optimal Page Replacement Algorithm
void ECPageReplacementOpt(const vector<int> &listAllPageRequests, int indexPageRequest) {
    if (mainMemory.size() < capacity) {
        // Memory is not full, just add the page
        mainMemory.insert(listAllPageRequests[indexPageRequest]);
    } else {
        // Find the page with the furthest access time in the future
        int pageToReplace = -1;
        int furthestAccessTime = -1;

        for (int page : mainMemory) {
            int futureAccess = -1;
            for (int i = indexPageRequest + 1; i < listAllPageRequests.size(); ++i) {
                if (listAllPageRequests[i] == page) {
                    futureAccess = i;
                    break;
                }
            }
            
            if (futureAccess == -1) {
                // Page will not be accessed in the future, so it's the furthest
                pageToReplace = page;
                break;
            } else if (futureAccess[page] > furthestAccessTime) {
                    furthestAccessTime = futureAccess[page];
                    pageToReplace = page;
            }
        }

        // Remove the page with the furthest access time
        mainMemory.erase(pageToReplace);
        
        // Add the requested page
        mainMemory.insert(listAllPageRequests[indexPageRequest]);
    }

    // Update the access time for the requested page
    pageAccessTime[listAllPageRequests[indexPageRequest]] = indexPageRequest;
}

// Access Page (LRU)
void ECPageAccessLRU(int pageCurrent) {
    // Update the access time for the page
    pageAccessTime[pageCurrent] = accessCounter++; // Assuming lower values mean more recent access
}

// LRU Page Replacement Algorithm
void ECPageReplacementLRU(int pageCurrent) {
    if (mainMemory.size() >= capacity) {
        // Find the least recently used page
        int pageToReplace = -1;
        int maxAccessTime = -1;

        for (const auto& entry : pageAccessTime) {
            if (entry.second < maxAccessTime) {
                maxAccessTime = entry.second;
                pageToReplace = entry.first;
            }
        }

        // Remove the least recently used page
        mainMemory.erase(pageToReplace);
    }

    // Add the requested page
    mainMemory.insert(pageCurrent);
    // Update the access time for the requested page
    ECPageAccessLRU(pageCurrent);
}

// int main() {
//     ECPagingInit(3); // Initialize main memory with a capacity of 3 pages

//     vector<int> pageRequests = {1, 2, 3, 4, 1, 2, 5, 1, 2};
    
//     for (int i = 0; i < pageRequests.size(); ++i) {
//         int page = pageRequests[i];
//         if (ECIsPageReplacing(page)) {
//             ECPageReplacementOpt(pageRequests, i); // Use optimal page replacement
//         }
//         ECPagingDump(); // Dump memory status (for debugging)
//     }

//     return 0;
// }

