
///////////////////////////////////////////////////////////////////////////////
// subsetsum.hpp
//
// Definitions for an algorithm that solve the subset sum problem using
// dynamic programming.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <optional>
#include <vector>
#include <iostream>
#include <iomanip>


//#include <experimental>

using namespace std;
int const NONE = -1;
int const EMPTY = -2;
///int const TRUE = 1;

// Solve the subset sum problem: return subset of universe that adds
// up to exactly target. If no such subset exists, return an empty optional.
// In the special case that target is zero, return an empty vector.
// universe must not be empty.
// This uses a dynamic programming search algorithm that takes pseudopolynomial
// time.

vector<int> subset_sum(const std::vector<int>& universe, int target) {

    assert(!universe.empty());
    int n = universe.size() ;
    int t = target;
    int T[n+1][t+1];


    // initialize array to 0
    for (int i=0; i<= n; i++){
        for (int j=0; j<=t; j++){
            T[i][j] = NONE;
        }
    }



    // set first column to true if target/ sum = {0}
    for(int i =0; i <= n; i++){
        T[i][0] = 1;
    }


    //algorithm
    for(int i = 1; i <= n; i++) {
        int x = universe[i - 1];

        //  print statement
        cout << "x  " << x << endl;

        for(int j = 0; j <= target; j++){
            cout << "j-x  " << j-x << endl;

            if(T[i-1][j] != NONE){
                cout << "inside if \n";
                T[i][j] = T[i-1][j];
            }


            else if(T[i-1][j-x]!= NONE){
                cout << "inside elif \n";
                T[i][j] = T[i-1][j - x] + x;
            }


            else{
                cout << "else \n";

                T[i][j] = NONE;
            }

            cout << "\n\n========================= PRINTING ARRAY =========================\n\n";
            for(int x = 0; x <= n; x++){
                for (int y = 0; y <= t; y++) {


                    cout << T[x][y] << "\t";
                }
                cout << endl;
            }


        }
    }

    cout << "\n\n========================= PRINTING ARRAY =========================\n\n";
    for(int i = 0; i <= n; i++){
        for (int j = 0; j <= t; j++) {


            cout << T[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    // TODO: Rewrite the body of this function so that it actually works. That
    // includes rewriting the return statement. After you do that, delete this
    // comment.

    return T[n][t];
}




