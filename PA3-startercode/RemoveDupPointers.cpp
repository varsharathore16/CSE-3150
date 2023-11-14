//
//  RemoveDupPointers.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <string>
#include <vector>
using namespace std;

//
void RemoveDupPointers(vector<string *> &arrayPtrs)
{
    // arrayPtrs: STL vector of pointers to strings
    // remove pointers that are pointed to identical strings in the array
    // Your code goes here...

    // vector<string*>::iterator new_end;
    // for (int i = 0; i < arrayPtrs.size(); i++){
    //     new_end = remove(arrayPtrs.begin(), arrayPtrs.end(), *arrayPtrs[i]);
    // }
    // vector<string*> toRemove;
    int inner_counter = 0;
    int outer_counter = 0;
    // for (int i = 0; i < arrayPtrs.size(); i++){
    while(outer_counter < arrayPtrs.size()){
        // if (arrayPtrs.size() == 2){
        //     if (*arrayPtrs[0] == *arrayPtrs[1] || arrayPtrs[0] == arrayPtrs[1]){
        //         arrayPtrs.erase(arrayPtrs.begin());
        //     }
        // }
        string base = *arrayPtrs[outer_counter];
        while(inner_counter < arrayPtrs.size()){
            if (inner_counter == outer_counter){
                inner_counter += 1;
                continue;
            }
            if (base == *arrayPtrs[inner_counter]){
                arrayPtrs.erase(arrayPtrs.begin() + inner_counter);
            }
            else{
                inner_counter += 1;
            }
                // toRemove.push_back(arrayPtrs[j]);
        }
        inner_counter = 0;
        outer_counter += 1;
    }
    // for (string* x : toRemove){
    //     cout << x << endl;
    // }
    // for (int i = 0; i < toRemove.size(); i++){
    //     remove(arrayPtrs.begin(), arrayPtrs.end(), toRemove[i]);
    // }
}