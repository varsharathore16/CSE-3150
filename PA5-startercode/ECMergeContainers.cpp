// Created by Y. Wu, Jan 31, 2023
// Merge lists (of any STL container type) into a single sorted list (of any STL container type)
// Duplicates allowed unless the output doesn't take duplicates (e.g., a map)
// Note: you should make your code as flexible as possible: you should allow all kinds of outputs: vector, set, etc 
// Make your code short: at most 10 lines of code (LOC) 

// now defiine ECMergeContainers ...

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
template <class Container, class OutputCon>
void ECMergeContainers(const Container &listOfLists, OutputCon &output){
    for (const auto &list:listOfLists){
        copy(list.begin(), list.end(), back_inserter(output));}
    sort(output.begin(), output.end());
}