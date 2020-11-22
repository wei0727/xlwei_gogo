#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
#include <string>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    string decode(string s, int& i) {
        string res;

        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;

                while (isdigit(s[i])) {
                    k = 10 * k + s[i] - '0';
                    i++;
                }

                // s[i] == '['
                i = i + 1;
                
                string tok = decode(s, i);
                while (k > 0) {
                    res += tok;
                    k--;
                }

                i = i + 1;
            }
            else {
                res += s[i];
                i = i + 1;
            }
        }
        
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};

void _394_decode_string(void)
{
    Solution m_sol;

    m_sol.decodeString("3[a]2[bc]");
}