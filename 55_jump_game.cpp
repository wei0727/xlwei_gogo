#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    /* over time limit */
    bool canJump(vector<int>& nums) {
        /*
            0: not visit yet
            1: visitable
            2: visited
        */
        vector<int> status(nums.size(), 0);

        if (nums.size() == 0)
            return false;

        if (nums.size() == 1)
            return true;

        status[0] = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (status[i] == 1) {
                for (int j = 1; j <= nums[i]; j++) {
                    int idx = i + j;

                    if (idx < nums.size() && status[idx] == 0) {
                        status[idx] = 1;

                        if (idx == nums.size() - 1)
                            return true;
                    }
                }
                status[i] = 2;

                //print_vector(status, "sts");
            }
        }
        
        return false;
    }

    /* passed, can be speed up? */
    bool canJump_2(vector<int>& nums) {
        int cur = 0;
        int max_reach = 0;

        while (cur <= max_reach) {
            max_reach = max(max_reach, nums[cur] + cur);
            cur += 1;
            if (max_reach >= nums.size() - 1)
                return true;
        }

        return false;
    }
};

void _55_jump_game(void)
{
    Solution m_sol;
    int test_case[5] = { 2,3,1,1,4 };
    int test_case_2[5] = { 3, 2, 1, 0, 4 };
    vector<int> test_input;

    test_input = vector<int>(test_case, test_case + 5);
    cout << m_sol.canJump_2(test_input) << endl;

    test_input = vector<int>(test_case_2, test_case_2 + 5);
    cout << m_sol.canJump_2(test_input) << endl;
}