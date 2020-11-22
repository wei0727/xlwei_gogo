#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;


class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    /*
        reflect whole square
        find k*q = n*p
    */
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        p /= g;
        p %= 2;
        q /= g;
        q %= 2;

        if (p == 1 && q == 1) return 1;
        return (p == 1) ? 0 : 2;
    }
};

void _858_mirror_reflection(void)
{
    Solution m_sol;

}