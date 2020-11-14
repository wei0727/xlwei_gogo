#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    // x pigs can generate 2^x state in one test
    // 3^x state in two test ...
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest / minutesToDie;
        int x = ceil(log(buckets) / log(T + 1));
        return x;
    }
};

void _48_rotate_image(void)
{
    Solution m_sol;
}