#include <iostream>
//#include "subset.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include "backtracking.h"

using namespace std;

std::vector<int> universe = {1, 2, 3};

int main() {



    vector <node> v1;

    for (int i=0; i< universe.size(); i++){
        v1.push_back(node());
    }

    cout << "fine\n";

    for (int i=0; i< universe.size(); i++){
        v1.at(i).universePtr = &(universe.at(i));
    }

    cout << "fine\n";

    v1.at(1).prev = &v1.at(0);
    v1.at(2).prev = &v1.at(1);

    cout << "fine\n";

    node* temp2 = &v1.at(2);

    cout << "testing copy cstr\n";
    node temp3 = v1.at(2);
    temp3.print();
    cout << "after testing copy cstr\n";


    while(temp2!= nullptr){
        temp2->print();
        temp2 = temp2->prev;
    }

    return 0;





    vector<int> res;
    res = subset_sum_dp(universe,3);
    cout << "back in main\n";

    for (int i=0; i< res.size(); i++){
        cout << res.at(i) << "\t";
    }

}
