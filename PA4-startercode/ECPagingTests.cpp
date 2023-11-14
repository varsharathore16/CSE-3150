#include "ECPageReplacement.h"
#include <algorithm>
using namespace std;

// Test utility
template<class T>
void ASSERT_EQ(T x, T y)
{
  if( x == y )
  {
    cout << "Test passed: equal: " << x << "  " << y << endl;
  }
  else
  {
    cout << "Test FAILED: equal: " << x << "  " << y << endl;
  }
}

// Run LRU algorithm on a list of page requests
static void RunLRU(int *listPageRequests, int numPageRequests, int memoryCapacity, int numPageFaultsExpected)
{
    // Memory capacity = 4
    ECPagingInit(memoryCapacity);

    // Now run LRU
    int numPageFaults = 0;
    for(int i=0; i<numPageRequests; ++i)
    {
      if( ECPagingIsMiss(listPageRequests[i]) )
      {
        ++numPageFaults;
        cout << "Page miss: [" << i << "]: " << listPageRequests[i] << endl;
      }

      if( ECIsPageReplacing(listPageRequests[i]) )
      {
        // perform replacement
        ECPageReplacementLRU(listPageRequests[i]);
      }
      else
      {
        // access it
        ECPageAccessLRU(listPageRequests[i]);
      }
    }
    //cout << "Number of page faults: " << numPageFaults << endl;
    // Replacement miss at the first four pages plus 5, 1, 6 2 page access
    ASSERT_EQ( numPageFaults, numPageFaultsExpected);
}

// Run optimal algorihtm
static void RunOpt(int *listPageRequests, int numPageRequests, int memoryCapacity, int numPageFaultsExpected)
{
    vector<int> pageListVec;
    for(int i=0; i<numPageRequests; ++i)
    {
        pageListVec.push_back( listPageRequests[i] );
    }
    
    ECPagingInit(memoryCapacity);
    int numPageFaults = 0;
    for(int i=0; i<numPageRequests; ++i)
    {
      if( ECPagingIsMiss(listPageRequests[i]) )
      {
        ++numPageFaults;
        cout << "Page miss: [" << i << "]: " << listPageRequests[i] << endl;
      }
      // access it
      ECPageReplacementOpt(pageListVec, i);
    }
    // Replacement miss at the first four pages plus 5, 6 page access
    ASSERT_EQ( numPageFaults, numPageFaultsExpected);
}

// Test case 1
static void Test()
{
    //
    int pageList[12] = {1, 2, 3, 4, 5, 1, 3, 1, 6, 3, 2, 3};
    RunLRU( pageList, 12, 4, 8  );

    // find the optimal missing
    cout << "Now run the optimal algorithm...\n";
    RunOpt(pageList, 12, 4, 6);
}

// Test case 2
static void Test2()
{
    cout << "******** Test2...\n";
    //
    int pageList[12] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
    RunLRU( pageList, 10, 3, 6  );

    // find the optimal missing
    cout << "Now run the optimal algorithm...\n";
    RunOpt(pageList, 10, 3, 5);
}

// Test case 3 ( this is taken from UConn's course lecture notes) https://cps.cse.uconn.edu/wp-content/uploads/sites/2687/2019/04/paging-in-real-world.pdf)
static void Test3()
{
    cout << "******** Test3...\n";
    //
    int pageList[22] = {7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
    RunLRU( pageList, 22, 3, 12 );

    // find the optimal missing
    cout << "Now run the optimal algorithm...\n";
    RunOpt(pageList, 22, 3, 9);
}

// Test case 4
static void Test4()
{
    cout << "******** Test4...\n";
    //
    int pageList[12] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2, 3, 4};
    RunLRU( pageList, 12, 3, 10 );

    // find the optimal missing
    cout << "Now run the optimal algorithm...\n";
    RunOpt(pageList, 12, 3, 7);
}

// Test case 5
static void Test5()
{
    cout << "******** Test5...\n";
    //
    int pageList[10] = {3, 1, 4, 2, 5, 2, 1, 2, 3, 4};
    RunLRU( pageList, 10, 4, 7 );

    // find the optimal missing
    cout << "Now run the optimal algorithm...\n";
    RunOpt(pageList, 10, 4, 6);
}

// Test case 6
static void Test6()
{
    cout << "******** Test6...\n";
    //
    int pageList[20] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};

    // now small memory: 3 pages
    RunLRU( pageList, 20, 3, 15 );

    // find the optimal missing
    cout << "Now run the optimal algorithm...\n";
    RunOpt(pageList, 20, 3, 11);
    
    // now large memory: 5 pages
    RunLRU( pageList, 20, 5, 8 );

    // find the optimal missing
    cout << "Now run the optimal algorithm...\n";
    RunOpt(pageList, 20, 5, 7);
    
    // now use larger memory: 7 pages
    RunLRU( pageList, 20, 7, 7 );

    // find the optimal missing
    cout << "Now run the optimal algorithm...\n";
    RunOpt(pageList, 20, 7, 7);
}

int main()
{
    try
    {
        Test();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
    }
    catch(string ex)
    {
        cout << "Exception: " << ex << endl;
    }
}

