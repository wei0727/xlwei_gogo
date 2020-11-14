#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    unsigned long long accumulate(vector<int>& nums, int divisor) {
        unsigned long long sum = 0;
        for (int n : nums) {
            sum += (n + (divisor - 1)) / divisor;
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int divisor = 0;
        int ub, lb;
        int smallest;
        unsigned long long sum;

        lb = 1;

        divisor = threshold - nums.size();
        if (divisor == 0) {
            divisor += 1;
        }
        ub = (accumulate(nums, 1) + (static_cast<unsigned long long>(divisor) - 1)) / divisor;
        smallest = max(lb, ub);
        while (lb <= ub) {
            divisor = (lb + ub) >> 1;
            sum = accumulate(nums, divisor);

            if (sum <= threshold) {
                ub = divisor - 1;
                smallest = min(divisor, smallest);
            }
            else {
                lb = divisor + 1;
            }
        }

        return smallest;
    }

    int accumulate_v2(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int n : nums) {
            sum += (n + (divisor - 1)) / divisor;
        }

        return sum;
    }
    int smallestDivisor_v2(vector<int>& nums, int threshold) {
        int divisor = 0;
        int ub, lb;
        int smallest;
        int sum;

        lb = 1;
        ub = 1;
        for (int n : nums) {
            ub = max(n, ub);
        }
        smallest = max(lb, ub);
        while (lb <= ub) {
            divisor = (lb + ub) >> 1;
            sum = accumulate_v2(nums, divisor);

            if (sum <= threshold) {
                ub = divisor - 1;
                smallest = min(divisor, smallest);
            }
            else {
                lb = divisor + 1;
            }
        }

        return smallest;
    }
};

void _1283_find_the_smallest_divisor_given_a_threshold(void)
{
    Solution m_sol;
    vector<int> test_case = { 2, 2, 2, 2 };

    m_sol.smallestDivisor(test_case, 4);
}