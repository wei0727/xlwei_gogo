#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    int m_binary_search(vector<int>& nums, int target, int l, int r) {
        int k = floor((l + r) / 2.0);

        while (l <= r) {
            if (nums[k] == target) {
                return k;
            }

            if (nums[k] > target) {
                r = k - 1;
            }
            else {
                l = k + 1;
            }
            k = floor((l + r) / 2.0);
        }

        return -1;
    }

    int find_left_most(vector<int>& nums, int target, int l, int r) {
        int l_init = l;
        int k = floor((l + r) / 2.0);

        while (l <= r) {
            if (k < r) {
                if (nums[k] != target && nums[k + 1] == target) {
                    return (k + 1);
                }
            }

            if (k > l) {
                if (nums[k] == target && nums[k - 1] != target) {
                    return k;
                }
            }

            if (nums[k] != target)
                l = k + 1;
            else
                r = k - 1;
            k = floor((l + r) / 2.0);
        }

        return l_init;
    }

    int find_right_most(vector<int>& nums, int target, int l, int r) {
        int r_init = r;
        int k = floor((l + r) / 2.0);

        while (l <= r) {
            if (k < r) {
                if (nums[k] == target && nums[k + 1] != target) {
                    return k;
                }
            }

            if (k > l) {
                if (nums[k] != target && nums[k - 1] == target) {
                    return (k - 1);
                }
            }

            if (nums[k] != target)
                r = k - 1;
            else
                l = k + 1;
            k = floor((l + r) / 2.0);
        }

        return r_init;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int k;
        int l_idx;
        int r_idx;
        vector<int> rt;

        k = m_binary_search(nums, target, 0, nums.size() - 1);
        cout << "find " << target << " at " << k << endl;

        if (k != -1) {
            l_idx = (k == 0) ? k : find_left_most(nums, target, 0, k);
            r_idx = (k == nums.size() - 1) ? k : find_right_most(nums, target, k, nums.size() - 1);
            cout << l_idx << " " << r_idx << endl;
        }
        else {
            l_idx = -1;
            r_idx = -1;
        }

        rt.push_back(l_idx);
        rt.push_back(r_idx);

        return rt;
    }
};

void _34_search_range(void)
{
    int test_case[] = {5, 7, 7, 8, 8, 10};
    vector<int> test_input;
    Solution m_sol;

    test_input = vector<int>(test_case, test_case + 6);
    print_vector(test_input, "test_input");
    m_sol.searchRange(test_input, 8);

    for (int i = 0; i < 5; i++) {
        cout << (i + 5 - 1) / 2 << endl;
    }
}