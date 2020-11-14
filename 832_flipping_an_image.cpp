#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (vector<int> &row : A) {
            reverse(row.begin(), row.end());
            for (int &pxl : row) {
                pxl ^= 1;
            }
        }

        return A;
    }

    vector<vector<int>> flipAndInvertImage_v2(vector<vector<int>>& A) {
        for (vector<int>& row : A) {
            for (int i = 0; i < row.size(); i++) {
                int j = row.size() - 1 - i;

                if (i > j) {
                    break;
                }

                if (i == j) {
                    row[i] ^= 1;
                    break;
                }
                
                if (row[i] == row[j]) {
                    row[i] ^= 1;
                    row[j] ^= 1;
                }
            }
        }

        return A;
    }
};

void _832_flipping_an_image(void)
{
    Solution m_sol;
}