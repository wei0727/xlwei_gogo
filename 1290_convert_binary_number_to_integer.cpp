#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // O(n)
    int getDecimalValue(ListNode* head) {
        ListNode* p_node = head;
        int dec_num = 0;
        
        while (p_node) {
            dec_num = dec_num << 1 | p_node->val;
            p_node = p_node->next;
        }

        return dec_num;
    }
};

void _1290_convert_binary_number_to_integer(void)
{
    Solution m_sol;
}