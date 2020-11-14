#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

class Solution {
public:
    void print_vector(string title, vector<int>& nums) {
        cout << title;
        for (auto n = nums.begin(); n != nums.end(); n++)
            cout << *n << " ";
        cout << endl;
    }

    int sort_rotated_arr(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int k = floor((l + r) / 2);

        // special case, already sorted array
        if (nums[r] > nums[k] && nums[k] > nums[l]) {
            return 0;
        }

        while (nums[k] < nums[k + 1]) {
            if (nums[l] > nums[k] && nums[r] > nums[k]) {
                r = k;
                k = floor((l + r) / 2);
            }
            else if (nums[k] > nums[l] && nums[k] > nums[r]) {
                l = k;
                k = floor((l + r) / 2);
            }
        }
        rotate(nums.begin(), nums.begin() + k + 1, nums.end());
        return (k + 1);
    }

    int find_idx_of_max_num(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int k = floor((l + r) / 2);

        // special case, already sorted array
        if (nums[r] > nums[k] && nums[k] > nums[l]) {
            return r;
        }

        while (nums[k] < nums[k + 1]) {
            if (nums[l] > nums[k] && nums[r] > nums[k]) {
                r = k;
                k = floor((l + r) / 2);
            }
            else if (nums[k] > nums[l] && nums[k] > nums[r]) {
                l = k;
                k = floor((l + r) / 2);
            }
        }

        return k;
    }

    int m_binary_search(vector<int>& nums, int target, int l, int r) {
        int k = ceil((l + r) / 2);

        if ((r - l) < 2) {
            if (nums[l] == target)
                return l;
            if (nums[r] == target)
                return r;
            return -1;
        }

        while (nums[k] != target) {
            if (l == k || r == k) {
                k = -1;
                break;
            }

            if (nums[k] > target) {
                r = k;
                k = floor((double)(l + r) / 2);

                //cout << "case1: " << l << " " << k << " " << r << endl;
            }
            else {
                l = k;
                k = ceil((double)(l + r) / 2);
                
                //cout << "case2: " << l << " " << k << " " << r << endl;
            }
        }

        return k;
    }

    int search(vector<int>& nums, int target) {
        int rotate_n;
        int rt;

        if (nums.size() < 3) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) 
                    return i;
            }
            return -1;
        }

        rotate_n = sort_rotated_arr(nums);
        rt = m_binary_search(nums, target, 0, nums.size()-1);

        cout << "rotate n " << rotate_n << endl;
        if (rt != -1) {
            rt = (rt + rotate_n) % nums.size();
        }

        return rt;
    }

    int search_2(vector<int>& nums, int target) {
        int k;
        int rt;

        k = find_idx_of_max_num(nums);

        if (nums[0] > target) {
            rt = m_binary_search(nums, target, k, nums.size() - 1);
        }
        else {
            rt = m_binary_search(nums, target, 0, k);
        }
        return rt;
        
    }
};

void _33_search_in_a_rotated_sorted_array(void)
{
    Solution m_sol;
    int test_case[4] = { 1, 2, 3, 4 };
    vector<int> test_input;

    test_input = vector<int>(test_case, test_case + 3);
    for (int i = 0; i < 3; i++) {
        rotate(test_input.begin(), test_input.begin() + i, test_input.end());
        m_sol.print_vector("test input: ", test_input);
        for (int j = 0; j <= 3; j++) {
            vector<int> test_input_tmp = test_input;
            
            cout << j << " " << m_sol.search_2(test_input_tmp, j) << endl;
        }
    }

    test_input = vector<int>(test_case, test_case + 4);
    for (int i = 0; i < 4; i++) {
        rotate(test_input.begin(), test_input.begin() + i, test_input.end());
        m_sol.print_vector("test input: ", test_input);

        for (int j = 0; j <= 4; j++) {
            vector<int> test_input_tmp = test_input;

            cout << j << " " << m_sol.search_2(test_input_tmp, j) << endl;
        }
    }
}