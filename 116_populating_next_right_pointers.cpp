#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include "leetcode.h"
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> bfs_queue;
        Node* p_left = nullptr;
        int visited_num = 0;
        int cur_level = 0;

        if (root == nullptr)
            return root;

        bfs_queue.push(root);
        while (!bfs_queue.empty()) {
            Node* p_cur = bfs_queue.front();

            bfs_queue.pop();
            if (p_cur->left && p_cur->right) {
                bfs_queue.push(p_cur->left);
                bfs_queue.push(p_cur->right);
            }

            visited_num++;
            if (visited_num == (1 << cur_level)) {
                p_left = p_cur;
                cur_level += 1;
            }
            else {
                if (p_left) {
                    p_left->next = p_cur;
                    p_left = p_cur;
                }
            }
        }

        return root;
    }

    Node* connect_v2(Node* root) {
        Node* m_root = root;

        while (m_root) {
            Node* cur = m_root;

            while (cur) {
                if (cur->left) {
                    cur->left->next = cur->right;
                    cur->right->next = (cur->next) ? cur->next->left : nullptr;
                }
                cur = cur->next;
            }
            m_root = m_root->left;
        }
        return root;
    }
};

void _116_populating_next_right_pointers(void)
{
    Solution m_sol;

}