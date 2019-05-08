#ifndef BACKTRACKING_H
#define BACKTRACKING_H
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

    node(){
        this->occupied = false;
        this->prev = nullptr;
        this->universePtr = nullptr;
    }

    node operator = (const node& right){
        cout << "in operator\n";
        node result;
        result.prev = right.prev;
        result.occupied = right.occupied;
        result.universePtr = right.universePtr;
        return result;
    }

    void print(){
        cout << "occuped: " << this->occupied << endl;
        cout << "prev: "; this->prev;
        cout << "universe ptr: " << *this->universePtr << endl;
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



vector<int> subset_sum_dp(vector <int> universe, unsigned target) {

    assert(!universe.empty());

    int n = universe.size();
    int t = target;


    //array of vectors
    node T [n+1][t+1];

    //init array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            T[i][j].occupied = false;
            T[i][j].universePtr = &universe.at(0);
        }
    }


    // set first column to true if target/ sum = {0}
    for (int i = 0; i <= n; i++) {
        T[i][0].occupied = true;
    }

    //algorithm
    for (int i = 1; i <= n; i++) {
        int x = universe[i-1];

        for (int j = 0; j <= t; j++) {

            if(T[i-1][j].occupied == true){
                T[i][j] = T[i - 1][j];
                T[i][j].prev = & T[i - 1][j];
            }

            else if(T[i-1][j].occupied == true){
                T[i][j] =  T[i-1][j - x];
                T[i][j].universePtr += (i-1);
                T[i][j].prev = &T[i-1][j];

            }
            else{

                T[i][j].occupied = false;

            }
        }
    }

    node *temp = &(T[n][t]);
    vector<int> result;
    while(temp!=nullptr){
        result.push_back(*(temp->universePtr));
        temp = temp->prev;
    }

    return result;




}

#endif // BACKTRACKING_H
