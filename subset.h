#ifndef SUBSET_H
#define SUBSET_H

///////////////////////////////////////////////////////////////////////////////
// subsetsum.hpp
//
// Definitions for an algorithm that solve the subset sum problem using
// dynamic programming.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <iostream>
using namespace std;

// Solve the subset sum problem: return subset of universe that adds
// up to exactly target. If no such subset exists, return an empty optional.
// In the special case that target is zero, return an empty vector.
// universe must not be empty.
// This uses a dynamic programming search algorithm that takes pseudopolynomial
// time.

struct node{
    bool occupied;
    node* prev;
    int* universePtr;

    node(bool occupied, node* prev, int* universePtr){
        this->occupied = occupied;
        this->prev = prev;
        this->universePtr = universePtr;
    }
};

bool isNone(const vector<int> &v){
    bool result = false;

    if (v.at(0) <0){
        return true;
    }
    else {
        return result;
    }
}

vector<int> remove0s (const vector<int> &v){
    int temp;
    vector<int> result;
    for(int i=0; i< v.size(); i++){
        temp = v.at(i);

        if (temp>=0 && i!=0){
            result.push_back(temp);
        }
    }
    return result;
}



vector<int> subset_sum_dp(const vector <int>& universe, unsigned target) {

    assert(!universe.empty());

    int n = universe.size();
    int t = target;

    //array of vectors
    vector<int> T[n+1][t+1];
    vector<int> empty = {0};
    vector<int> NONE = {-1};

    //init array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            T[i][j] = NONE;
        }
    }

    cout << "PRINTING INIT ARRAY should be all -1\n\n";

    for (int i=0; i<= n; i++){
        for (int j=0; j<= t; j++){
            cout << T[i][j].at(0) << "\t";
        }
        cout << endl;
    }

    cout << "outside of init array\n";


    // set first column to true if target/ sum = {0}
    for (int i = 0; i <= n; i++) {
        T[i][0] = empty;
    }

    cout << "PRINTING ARRAY AFTER EMPTY should be all -1\n\n";

    for (int i=0; i<= n; i++){
        for (int j=0; j<= t; j++){
            cout << T[i][j].at(0) << "\t";
        }
        cout << endl;
    }

    //algorithm
    for (int i = 1; i <= n; i++) {
        int x = universe[i-1];

        for (int j = 0; j <= t; j++) {
            if (!isNone(T[i-1][j])){
                T[i][j] = T[i - 1][j];
            }
            else if(!isNone(T[i-1][j-x])){
                T[i][j] =  T[i-1][j - x];
                T[i][j].push_back(x);

            }
            else{

                T[i][j] = NONE;

            }
        }
    }

    return remove0s(T[n][t]);
}



#endif // SUBSET_H
