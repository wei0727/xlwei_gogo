#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;


class Solution {
public:
    bool is_orthogonal(vector<int>& l1, vector<int>& l2) {
        return (l1[0] * l2[0] + l1[1] * l2[1]) == 0;
    }
    int length(vector<int>& p1, vector<int>& p2) {
        return ((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
    }
    bool is_square(vector<vector<int>>& points) {
        vector<int> cur_slope(2);
        vector<int> pre_slope(2);
        int len = length(points[0], points[1]);

        if (len == 0)
            return false;

        for (int i = 1; i < points.size(); i++) {
            cur_slope[0] = points[i][0] - points[i - 1][0];
            cur_slope[1] = points[i][1] - points[i - 1][1];

            if (i > 1 && !is_orthogonal(cur_slope, pre_slope)) {
                break;
            }

            if (length(points[i], points[i - 1]) != len) {
                break;
            }

            if (i == points.size() - 1) {
                return true;
            }

            pre_slope[0] = cur_slope[0];
            pre_slope[1] = cur_slope[1];
        }

        return false;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points;

        // 1 -> 2 -> 3 -> 4
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        points.push_back(p1);
        if (is_square(points)) {
            return true;
        }

        // 1 -> 2 -> 4 -> 3
        points.clear();
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p4);
        points.push_back(p3);
        points.push_back(p1);
        if (is_square(points)) {
            return true;
        }

        // 1 -> 3 -> 2 -> 4
        points.clear();
        points.push_back(p1);
        points.push_back(p3);
        points.push_back(p2);
        points.push_back(p4);
        points.push_back(p1);
        if (is_square(points)) {
            return true;
        }

        return false;
    }

    /* sort first */
    bool validSquare_v2(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points{p1, p2, p3, p4};
        vector<vector<int>> square;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        
        // 1 -> 2 -> 4 -> 3
        square.push_back(points[0]);
        square.push_back(points[1]);
        square.push_back(points[3]);
        square.push_back(points[2]);
        square.push_back(points[0]);
        return is_square(square);
    }
};

void _593_valid_square(void)
{
    Solution m_sol;
    vector<int> vp1{ 0, 0 };
    vector<int> vp2{ 1, 1 };
    vector<int> vp3{ 1, 0 };
    vector<int> vp4{ 0, 1 };

    m_sol.validSquare_v2(vp1, vp2, vp3, vp4);
}