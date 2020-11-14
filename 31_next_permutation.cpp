#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "leetcode.h"
using namespace std;

/* my first solution */
void nextPermutation(vector<int>& nums) 
{
	//cout << "next permuation" << endl;
	bool is_find = false;
	int i, j;
	int* p_candidate;

	for (auto k = nums.begin(); k != nums.end(); k++) {
		cout << *k;
	}
	cout << endl;

    for (i = nums.size() - 2; i >= 0; i--) {
        p_candidate = NULL;
        for (j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                if (p_candidate == NULL) {
                    p_candidate = &nums[j];
                }
                else {
                    if (nums[j] < *p_candidate) {
                        p_candidate = &nums[j];
                    }
                }
            }
        }

        if (p_candidate) {
            int tmp;

            tmp = nums[i];
            nums[i] = *p_candidate;
            *p_candidate = tmp;
            is_find = true;
            sort(nums.begin() + i + 1, nums.end());
            break;
        }
    }

	if (!is_find) {
		sort(nums.begin(), nums.end());
	}

	for (auto k = nums.begin(); k != nums.end(); k++) {
		cout << *k;
	}
	cout << endl;
}

/* better solution */
void nextPermutation_2(vector<int>& nums)
{
    //cout << "next permuation" << endl;
    int i;
    int j;
    int tmp;

    i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        for (j = nums.size() - 1; j > i; j--) {
            if (nums[j] > nums[i])
                break;
        }
        
        tmp = nums[j];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    reverse(nums.begin() + i + 1, nums.end());
}