#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rst;
        int row = 0;
        int col = 0;
        int row_dir = 0;
        int col_dir = 1;
        int row_min = 0;
        int row_max = 0;
        int col_min = 0;
        int col_max = 0;

        row_max = matrix.size();
        if (row_max == 0)
            return rst;

        col_max = matrix[0].size();
        if (col_max == 0)
            return rst;

        while (1) {
            //cout << row << " " << col << endl;
            rst.push_back(matrix[row][col]);

            row += row_dir;
            col += col_dir;
            if (row < row_min || row >= row_max || col < col_min || col >= col_max) {
                // change direction
                row -= row_dir;
                col -= col_dir;
                if (row_dir == 1) {
                    //down to left
                    row_dir = 0;
                    col_dir = -1;
                    col_max -= 1;
                }
                else if (col_dir == 1) {
                    //right to down
                    row_dir = 1;
                    col_dir = 0;
                    row_min += 1;
                }
                else if (row_dir == -1) {
                    //top to right
                    row_dir = 0;
                    col_dir = 1;
                    col_min += 1;
                }
                else if (col_dir == -1) {
                    //left to top
                    row_dir = -1;
                    col_dir = 0;
                    row_max -= 1;
                }
                else {
                    cout << "wtf" << endl;
                }
                row += row_dir;
                col += col_dir;

                //cout << matrix[row][col] << ": " << row_min << " " << row_max << " " << col_min << " " << col_max << endl;
            }

            if (row_min >= row_max || col_min >= col_max)
                break;
        }

        //print_vector(rst, "result");
        return rst;
    }
};

void _54_spiral_matrix(void)
{
    Solution m_sol;
    int count;

    for (int n = 3; n < 6; n++) {
        for (int m = 3; m < 6; m++) {
            vector<vector<int>> test_case(n, vector<int>(m));

            count = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    test_case[i][j] = count;
                    count++;
                }
            }
            print_vector_2d(test_case, "input");
            m_sol.spiralOrder(test_case);
        }
    }
}