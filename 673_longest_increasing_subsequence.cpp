#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    // O(n^2)
    int get_list_number(vector<int>& nums) {
        vector<int> dp_lis(nums.size(), 1); // longest suquence length end with nums[i]
        vector<int> dp_cnt(nums.size(), 1); // count of lis end with nums[i]
        int max_lis = 1;
        int max_cnt = 1;

        if (nums.empty())
            return 0;
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if ((dp_lis[j] + 1) > dp_lis[i]) {
                        dp_lis[i] = dp_lis[j] + 1;
                        dp_cnt[i] = dp_cnt[j];
                    }
                    else if ((dp_lis[j] + 1) == dp_lis[i]) {
                        dp_cnt[i] += dp_cnt[j];
                    }
                }
            }
            if (dp_lis[i] > max_lis) {
                max_lis = dp_lis[i];
                max_cnt = dp_cnt[i];
            }
            else if (dp_lis[i] == max_lis) {
                max_cnt += dp_cnt[i];
            }
        }

        return max_cnt;
    }
};

void _673_longest_increasing_subsequence(void)
{
    Solution m_sol;
    vector<int> test_case = {2, 2, 2, 2, 2};
    vector<int> test_case_2 = {1, 2, 8, 7, 6, 5, 10};

    print_vector(test_case, "case_1 : ");
    cout << m_sol.get_list_number(test_case) << endl;

    print_vector(test_case_2, "case_2 : ");
    cout << m_sol.get_list_number(test_case_2) << endl;
}