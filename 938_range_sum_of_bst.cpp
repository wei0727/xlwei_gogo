#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

/**
 * Definition for a binary tree node.

*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        
        if (root->val < low) {
            return dfs(root->right, low, high);
        }
        
        if (root->val > high) {
            return dfs(root->left, low, high);
        }
        
        return root->val + dfs(root->left, low, high) + dfs(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};

void _938_range_sum_of_bst(void)
{
    Solution m_sol;
}