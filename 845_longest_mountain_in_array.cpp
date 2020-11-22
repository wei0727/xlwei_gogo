#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;


class Solution {
public:
    int longestMountain(vector<int>& A) {
        int left = 0;
        int res = 0;
        enum {
            START = 0,
            UP,
            DOWN,
        } cur_sts;

        cur_sts = START;
        for (int i = 1; i < A.size(); i++) {
            switch (cur_sts) {
            case START:
                if (A[i] <= A[i - 1]) {
                    // end of mountain
                    left = i;
                    continue;
                }
                else {
                    cur_sts = UP;
                }
                break;

            case UP:
                if (A[i] == A[i - 1]) {
                    // end of mountain
                    left = i;
                    cur_sts = START;
                    continue;
                }
                else {
                    if (A[i] < A[i - 1]) {
                        cur_sts = DOWN;
                    }
                }
                break;

            case DOWN:
                if (A[i] >= A[i - 1]) {
                    // end of mountain
                    res = max(res, (i - left));

                    if (A[i] == A[i - 1]) {
                        left = i;
                    }
                    else {
                        left = i - 1;
                        i = i - 1;
                    }
                    cur_sts = START;
                    continue;
                }
                break;
            }

            if (cur_sts == DOWN && i == A.size() - 1) {
                cout << left << " " << i << endl;
                res = max(res, (i - left + 1));
            }
        }
        return (res < 3) ? 0 : res;
    }

    int longestMountain_v2(vector<int>& A) {
        int left = 0;
        int res = 0;

        while (left < A.size()) {
            // find go up
            int k = left;
            while ((k + 1) < A.size() && A[k + 1] > A[k]) {
                k++;
            }
            if (k == left) {
                left = k;
                continue;
            }

            // find go down
            int r = k;
            while ((r + 1) < A.size() && A[r + 1] < A[r]) {
                r++;
            }
            if (r == k) {
                left = r;
                continue;
            }

            res = max(res, (r - left + 1));
        }
        return res;
    }
};

void _673_longest_mountain_in_array(void)
{
    Solution m_sol;

}