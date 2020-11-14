#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp;

        for (int row = 0; row < floor(n / 2.0); row++) {
            for (int col = row; col < (n - row - 1); col++) {
                //cout << row << ", " << col << endl;

                tmp = matrix[row][col];
                matrix[row][col] = matrix[n - col - 1][row];
                matrix[n - col - 1][row] = matrix[n - row - 1][n - col - 1];
                matrix[n - row - 1][n - col - 1] = matrix[col][n - row - 1];
                matrix[col][n - row - 1] = tmp;
            }
        }
    }
};

void _48_rotate_image(void)
{
    Solution m_sol;
    int count;

    for (int n = 3; n < 6; n++) {
        vector<vector<int>> test_case(n, vector<int>(n));

        count = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                test_case[i][j] = count;
                count++;
            }
        }
        print_vector_2d(test_case, "input");
        m_sol.rotate(test_case);
        print_vector_2d(test_case, "output");
    }
}