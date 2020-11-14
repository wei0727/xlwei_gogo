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
    /* int will overflow*/
    ListNode* addTwoNumbers_overflow(ListNode* l1, ListNode* l2) {
        int n1 = 0;
        int n2 = 0;
        int sum;
        ListNode* p_sum = nullptr;

        while (l1) {
            n1 = (n1 * 10) + l1->val;
            l1 = l1->next;
        }

        while (l2) {
            n2 = (n2 * 10) + l2->val;
            l2 = l2->next;
        }

        sum = n1 + n2;
        if (sum == 0) {
            p_sum = new ListNode(0);
        }
        else {
            while (sum) {
                if (p_sum == nullptr) {
                    p_sum = new ListNode(sum % 10);
                }
                else {
                    p_sum = new ListNode(sum % 10, p_sum);
                }
                sum /= 10;
            }
        }

        return p_sum;
    }

    ListNode* reverseList(ListNode* list) {
        ListNode* p_pre;
        ListNode* p_cur;
        ListNode* p_next;

        p_pre = list;
        p_cur = list->next;
        list->next = nullptr;
        while (p_cur) {
            p_next = p_cur->next;
            p_cur->next = p_pre;
            p_pre = p_cur;
            p_cur = p_next;
        }

        return p_pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rev_l1 = reverseList(l1);
        ListNode* rev_l2 = reverseList(l2);
        ListNode* sum = nullptr;
        int carry = 0;

        while (rev_l1 && rev_l2) {
            carry += rev_l1->val + rev_l2->val;
            sum = new ListNode(carry % 10, sum);
            carry /= 10;

            rev_l1 = rev_l1->next;
            rev_l2 = rev_l2->next;
        }

        if (rev_l1) {
            while (rev_l1) {
                if (carry) {
                    carry += rev_l1->val;
                    sum = new ListNode(carry % 10, sum);
                    carry /= 10;
                }
                else {
                    sum = new ListNode(rev_l1->val, sum);
                }
                rev_l1 = rev_l1->next;
            }
        }
        else if (rev_l2) {
            while (rev_l2) {
                if (carry) {
                    carry += rev_l2->val;
                    sum = new ListNode(carry % 10, sum);
                    carry /= 10;
                }
                else {
                    sum = new ListNode(rev_l2->val, sum);
                }
                rev_l2 = rev_l2->next;
            }
        }
        
        if (carry) {
            sum = new ListNode(carry, sum);
        }

        return sum;
    }

};

void _445_add_two_numbers_II(void)
{
    Solution m_sol;
}