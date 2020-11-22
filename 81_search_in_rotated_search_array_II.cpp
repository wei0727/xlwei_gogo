#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int k = (l + r) >> 1;
            if (nums[k] == target)
                return true;

            if (nums[k] == nums[l]) {
                l = l + 1;
                continue;
            }

            //cout << l << " " << k << " " << r << endl;

            int mid_in_f = (nums[l] <= nums[k]);
            int tar_in_f = (nums[l] <= target);

            // mid, target in different side
            if (mid_in_f ^ tar_in_f) {
                if (mid_in_f) {
                    l = k + 1;
                }
                else {
                    r = k - 1;
                }
            }
            else {
                if (target < nums[k]) {
                    r = k - 1;
                }
                else {
                    l = k + 1;
                }
            }
        }
        return false;
    }
};

void _81_search_in_rotated_sorted_array_II(void)
{
    Solution m_sol;
    int test_case[4] = { 1, 2, 3, 4 };
    vector<int> test_input;
}