#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int sum_odd = 0;
        int sum_even = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] & 1) {
                sum_odd++;
            }
            else {
                sum_even++;
            }
        }
        return min(sum_odd, sum_even);
    }
};

void _1217_minumum_cost_to_move_chips(void)
{
    Solution m_sol;
}