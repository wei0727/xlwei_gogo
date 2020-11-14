#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>
#include "leetcode.h"
using namespace std;

/**
 * Definition for a binary tree node.

*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
     pair<int, int> dfs_minmax(TreeNode* root, int& res) {
        pair<int, int> l, r, minmax;

        // leaf check
        if (root == nullptr) {
            return make_pair(numeric_limits<int>::max(), numeric_limits<int>::min());
        }

        l = dfs_minmax(root->left, res);
        r = dfs_minmax(root->right, res);
        minmax.first = min(l.first, r.first);
        minmax.second = max(l.second, r.second);
        
        if (root->left || root->right) {
            res = max(res, abs(root->val - minmax.first));
            res = max(res, abs(root->val - minmax.second));
        }

        minmax.first = min(root->val, minmax.first);
        minmax.second = max(root->val, minmax.second);

        return minmax;
    }

    int maxAncestorDiff(TreeNode* root) {
        int res = 0;

        dfs_minmax(root, res);

        return res;
    }
};

void _1026_maximum_difference_between_node_and_ancestor(void)
{
    Solution m_sol;
}