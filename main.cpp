#include <iostream>
#include "subset.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
//#include "backtracking.h"

using namespace std;

std::vector<int> universe = {1, 2, 3};

int main() {

vector<int> res = subset_sum_dp(universe,6);

for(int i=0; i< res.size(); i++){
    cout << res.at(i) << "\t";
}



}
