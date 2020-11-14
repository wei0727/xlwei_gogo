#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    // O(n)
    /*
        remove leafs, minimim trees is the lastest nodes been removed
    */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> in_degrees(n, 0);
        vector<int> min_trees;
        queue<int> leaf_que;

        if (n == 0) {  
            return min_trees;
        }

        if (n == 1) {
            min_trees.push_back(0);
            return min_trees;
        }

        // initialize adj list
        for (vector<int> e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            in_degrees[e[0]] += 1;
            in_degrees[e[1]] += 1;
        }
        
        for (int i = 0; i < n; i ++) {
            if (in_degrees[i] == 1) {
                leaf_que.push(i);
            }
        }

        while (!leaf_que.empty()) {
            int q_size = leaf_que.size();

            min_trees.clear();
            for (int i = 0; i < q_size; i++) {
                int leaf = leaf_que.front();

                leaf_que.pop();
                min_trees.push_back(leaf);
                for (int neighbor : adj[leaf]) {
                    in_degrees[neighbor] -= 1;
                    if (in_degrees[neighbor] == 1) {
                        leaf_que.push(neighbor);
                    }
                }
            }
        }

        return min_trees;
    }
};

void _310_minimum_height_trees(void)
{
    Solution m_sol;
    vector<vector<int>> test_case = { {3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4} };

    m_sol.findMinHeightTrees(6, test_case);
}