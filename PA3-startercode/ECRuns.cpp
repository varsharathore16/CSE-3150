

//
//  ECRuns.cpp
//  
//
//  Created by Yufeng Wu on 08/22/23.
//
//
#include <iostream>
#include <string>

using namespace std;

// Return the number of runs, and the list of starting positions of runs in the passed in array (which you can assume it is large enough)
int ECRuns(const string &str, int *pListPositions)
{
    if(str.size()==0){return 0;}

    int a=1;
    pListPositions[0] = 0;
    for(int i=0; i<str.size()-1; i++){
        if(str[i]!=str[i+1]){
            pListPositions[a] = i+1;
            a+=1;
        }}
    return a;
}