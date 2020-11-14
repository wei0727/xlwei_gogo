#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int max_power = 0;
        int power;
        char cur_ch;

        cur_ch = s.front();
        power = 0;
        for (const auto &c : s) {
            if (cur_ch != c) {
                max_power = max(max_power, power);
                cur_ch = c;
                power = 1;
            }
            else {
                power += 1;
            }
        }
        max_power = max(max_power, power);

        return max_power;
    }
};

void _1446_consecutive_character(void)
{
    Solution m_sol;
}