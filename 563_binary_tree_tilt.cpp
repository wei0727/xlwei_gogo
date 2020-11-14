#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
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
    /* 
        number of node [0, 10^4]
        -1000 <= node.val <= 1000
    */
    int findTilt(TreeNode* root) {
        set<TreeNode*> visited;
        stack<TreeNode*> dfs_stack;
        TreeNode* p_cur;
        int tilt_sum = 0;

        if (root == nullptr) {
            return tilt_sum;
        }

        dfs_stack.push(root);
        while (!dfs_stack.empty()) {
            p_cur = dfs_stack.top();
            if (p_cur->left && (visited.count(p_cur->left) == 0)) {
                dfs_stack.push(p_cur->left);
            }
            else if (p_cur->right && (visited.count(p_cur->right) == 0)) {
                dfs_stack.push(p_cur->right);
            }
            else {
                int l = 0;
                int r = 0;

                dfs_stack.pop();
                visited.insert(p_cur);

                if (p_cur->left) {
                    l = p_cur->left->val;
                }
                if (p_cur->right) {
                    r = p_cur->right->val;
                } 
                p_cur->val += l + r;
                tilt_sum += abs((l - r));
            }
        }

        return tilt_sum;
    }

    int findTilt_map(TreeNode* root) {
        map<TreeNode*, bool> visited;
        stack<TreeNode*> dfs_stack;
        TreeNode* p_cur;
        int tilt_sum = 0;

        dfs_stack.push(root);
        while (!dfs_stack.empty()) {
            p_cur = dfs_stack.top();
            if (p_cur->left && (visited[p_cur->left] != true)) {
                dfs_stack.push(p_cur->left);
            }
            else if (p_cur->right && (visited[p_cur->right] != true)) {
                dfs_stack.push(p_cur->right);
            }
            else {
                int l = 0;
                int r = 0;
                dfs_stack.pop();
                visited[p_cur] = true;

                if (p_cur->left) {
                    p_cur->val += p_cur->left->val;
                    l = p_cur->left->val;
                }
                if (p_cur->right) {
                    p_cur->val += p_cur->right->val;
                    r = p_cur->right->val;
                }
                tilt_sum += abs((l - r));
            }
        }

        return tilt_sum;
    }

    int dfs_sum(TreeNode* root, int& res) {
        int l, r;

        if (root == nullptr) {
            return 0;
        }

        l = dfs_sum(root->left, res);
        r = dfs_sum(root->right, res);
        res += abs(l - r);

        return l + r + root->val;
    }

    int findTilt_recursive(TreeNode* root) {
        int tilt = 0;

        dfs_sum(root, tilt);

        return tilt;
    }
};

void _563_binary_tree_tilt(void)
{
    Solution m_sol;
}