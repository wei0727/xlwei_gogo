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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // O(n^2)
    // 0+1+2+...+(n-1) = n(n-1)/2 --> O(n^2)
    ListNode* insertionSortList(ListNode* head) {
        ListNode* p_node = head;
        ListNode* p_sorted_list = nullptr;

        while (p_node) {
            ListNode* p_tmp;
            ListNode* p_next = p_node->next;

            if (p_sorted_list == nullptr) {
                p_node->next = nullptr;
                p_sorted_list = p_node;
            }
            else {
                p_tmp = p_sorted_list;
                while (p_tmp) {
                    if (p_tmp->val < p_node->val) {
                        if (p_tmp->next == nullptr ||
                            p_tmp->next->val >= p_node->val) {
                            p_node->next = p_tmp->next;
                            p_tmp->next = p_node;
                            break;
                        }
                    }
                    else {
                        p_node->next = p_sorted_list;
                        p_sorted_list = p_node;
                        break;
                    }
                    p_tmp = p_tmp->next;
                }
            }
            p_node = p_next;
        }

        return p_sorted_list;
    }
};

void _147_insertion_sort_list(void)
{
    Solution m_sol;
    ListNode* p_list = nullptr;
    ListNode* p_back = nullptr;
    int arr[4] = { 4, 2, 1, 3 };
    
    for (int i = 0; i < 4; i++) {
        if (p_list == nullptr) {
            p_list = new ListNode(arr[i]);
            p_back = p_list;
        }
        else {
            p_back->next = new ListNode(arr[i]);
            p_back = p_back->next;
        }
    }

    m_sol.insertionSortList(p_list);

}