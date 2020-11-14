#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    static bool intervals_cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> rst;
        int cur_idx = 0;

        sort(intervals.begin(), intervals.end(), intervals_cmp);
        //print_vector_2d(intervals, "sorted ");

        for (int i = 0; i < intervals.size(); i++) {
            if (i == 0) {
                rst.push_back(intervals[i]);
                continue;
            }

            if (intervals[i][0] <= rst[cur_idx][1]) {
                //merge
                rst[cur_idx][1] = max(intervals[i][1], rst[cur_idx][1]);
            } else {
                //add
                rst.push_back(intervals[i]);
                cur_idx += 1;
            }
        }

        return rst;
    }
};

void _56_merge_intervals(void)
{
    Solution m_sol;
    int test_arr[4][2] = {
        {1, 3}, {8, 10}, {2, 6}, {15, 18}
    };
    vector<vector<int>> test;

    for (int i = 0; i < 4; i++) {
        vector<int> tmp = vector<int>(test_arr[i], test_arr[i] + 2);
        test.push_back(tmp);
    }

    print_vector_2d(test, "input ");
    test = m_sol.merge(test);
    print_vector_2d(test, "output ");
}