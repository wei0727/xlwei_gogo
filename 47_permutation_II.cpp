#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    /* failed, need to remove duplicate case */
    vector<vector<int>> permuteUnique_ng(vector<int>& nums) {
        vector<vector<int>> res;
        int cur_len = 0;

        for (int n : nums) {
            if (cur_len == 0) {
                res.push_back(vector<int>(1, n));
                cur_len = 1;
                continue;
            }

            int size = res.size();
            for (int j = 0; j < size; j++) {
                vector<int> node = res[j];
                
                // add n to every possible position
                for (int i = 0; i <= node.size(); i++) {
                    vector<int> tmp = vector<int>(node);
                    tmp.insert(tmp.begin() + i, n);
                    res.push_back(tmp);

                    while (i < node.size() && n == node[i]) {
                        //move to last same number
                        i++;
                    }

                    if (i == node.size() && n == node[i - 1]) {
                        break;
                    }
                }
            }

            res.erase(res.begin(), res.begin() + size);
        }

        return res;
    }

    // DFS solution
    void dfs_permutation(map<int, int>& n_map, vector<int>& cur_permutation, int size, vector<vector<int>> &res) {
        if (cur_permutation.size() == size) {
            res.push_back(vector<int>(cur_permutation));
            return;
        }

        for (auto &kv : n_map) {
            if (kv.second) {
                cur_permutation.push_back(kv.first);
                kv.second -= 1;
                dfs_permutation(n_map, cur_permutation, size, res);
                cur_permutation.pop_back();
                kv.second += 1;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> n_map;
        vector<vector<int>> res;
        vector<int> cur_permutation;

        for (int n : nums) {
            n_map[n]++;
        }

        dfs_permutation(n_map, cur_permutation, nums.size(), res);

        return res;
    }
};

void _47_permutation_II(void)
{
    Solution m_sol;
    vector<int> testcase{ 1, 2, 1, 2 };

    m_sol.permuteUnique(testcase);
}