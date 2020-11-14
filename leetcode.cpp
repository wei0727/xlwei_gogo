// leetcode.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <iomanip>
#include "leetcode.h"
using namespace std;

void print_vector(std::vector<int>& nums, std::string title)
{
    if (title != "")
        cout << title << ": ";

    for (auto i = nums.begin(); i != nums.end(); i++)
        cout << setw(4) << *i << " ";
    cout << endl;
}

void print_vector_2d(std::vector<vector<int>>& nums, std::string title)
{
    if (title != "")
        cout << title << ": " << endl;
    for (int i = 0; i < nums.size(); i++) {
        print_vector(nums[i], "");
    }
    cout << endl;
}


int main()
{
    string sel;

    _47_permutation_II();

    cout << "enter mode" << endl;
    while (cin >> sel) {
        if (sel.compare("q") == 0) {
            cout << "exit" << endl;
            break;
        }

        if (sel.compare("leetcode") == 0) {
            cout << "enter selection" << endl;
            cin >> sel;
            if (sel.compare("33") == 0) {
                _33_search_in_a_rotated_sorted_array();
            }
            else if (sel.compare("34") == 0) {
                _34_search_range();
            }
            else if (sel.compare("48") == 0) {
                _48_rotate_image();
            }
            else if (sel.compare("54") == 0) {
                _54_spiral_matrix();
            }
            else if (sel.compare("55") == 0) {
                _55_jump_game();
            }
            else if (sel.compare("56") == 0) {
                _56_merge_intervals();
            }
            else if (sel.compare("673") == 0) {
                _673_longest_increasing_subsequence();
            }
        }
        else if (sel.compare("demo") == 0) {
            lambda_func_demo();
        }
        else {
            cout << "unknown mode" << endl;
        }
    }

    return 0;
}
