#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "leetcode.h"
using namespace std;

class TREE_NODE
{
public:
	TREE_NODE(int val) {
		this->val = val;
		this->parent = NULL;
		this->l_child = NULL;
		this->r_child = NULL;
		height = 1;
	}
	TREE_NODE* parent;
	TREE_NODE* l_child;
	TREE_NODE* r_child;
	int height;
	int val;
};

class AVL_TREE
{
public:
	AVL_TREE();
	int add(int val);
	int del(int val);
	int print_bfs_order(void);
	
private:
	TREE_NODE* root;

	int right_rotate(TREE_NODE* pivot);
	int left_rotate(TREE_NODE* pivot);
	bool is_balance(TREE_NODE* p_node);

	/* update height from node by dfs */
	int update_height_top_down(TREE_NODE* p_node);

	/* udpate height from node trace back to root */
	int update_height_bottom_up(TREE_NODE* p_node);
};

AVL_TREE::AVL_TREE()
{
	this->root = NULL;
}

bool AVL_TREE::is_balance(TREE_NODE* p_node)
{
	int height_diff = 0;

	if (p_node->l_child && p_node->r_child) {
		height_diff = abs(p_node->l_child->height - p_node->r_child->height);
	}
	else if (p_node->l_child && (p_node->r_child == NULL)) {
		height_diff = p_node->l_child->height;
	}
	else if ((p_node->l_child == NULL) && p_node->r_child) {
		height_diff = p_node->r_child->height;
	}
	
	return (height_diff < 2);
}

int AVL_TREE::right_rotate(TREE_NODE* pivot)
{
	TREE_NODE* parent = NULL;
	TREE_NODE* x = NULL;
	TREE_NODE* T1 = NULL;
	TREE_NODE* T2 = NULL;
	TREE_NODE* T3 = NULL;

	parent = pivot->parent;
	x = pivot->l_child;
	if (x) {
		T1 = x->l_child;
		T2 = x->r_child;
	}
	else {
		return -1;
	}
	T3 = pivot->r_child;

	// rotate
	x->parent = parent;
	x->r_child = pivot;
	pivot->parent = x;
	pivot->l_child = T2;

	if (T2) {
		T2->parent = pivot;
	}

	if (parent) {
		if (parent->l_child == pivot) {
			parent->l_child = x;
		}
		else {
			parent->r_child = x;
		}
	}

	if (pivot == this->root) {
		this->root = pivot->parent;
	}

	return 0;
}

int AVL_TREE::left_rotate(TREE_NODE* pivot)
{
	TREE_NODE* parent = NULL;
	TREE_NODE* y = NULL;
	TREE_NODE* T1 = NULL;
	TREE_NODE* T2 = NULL;
	TREE_NODE* T3 = NULL;

	parent = pivot->parent;
	y = pivot->r_child;
	if (y) {
		T2 = y->l_child;
		T3 = y->r_child;
	}
	else {
		return -1;
	}
	T1 = pivot->r_child;

	y->parent = parent;
	y->l_child = pivot;
	pivot->parent = y;
	pivot->r_child = T2;

	if (T2) {
		T2->parent = pivot;
	}

	if (parent) {
		if (parent->l_child == pivot) {
			parent->l_child = y;
		}
		else {
			parent->r_child = y;
		}
	}

	if (pivot == this->root) {
		this->root = pivot->parent;
	}

	return 0;
}

int AVL_TREE::update_height_top_down(TREE_NODE* p_node = NULL)
{
	stack<TREE_NODE*> stk;
	stack<int> stk_sts;

	stk.push(this->root);
	stk_sts.push(0);
	while (!stk.empty()) {
		int& status = stk_sts.top();

		p_node = stk.top();
		if (status == 0) {
			if (p_node->l_child) {
				stk.push(p_node->l_child);
				stk_sts.push(0);
			}
		}
		else if (status == 1) {
			if (p_node->r_child) {
				stk.push(p_node->r_child);
				stk_sts.push(0);
			}
		}
		else {
			if (p_node->l_child && p_node->r_child) {
				p_node->height = max(p_node->l_child->height, p_node->r_child->height) + 1;
			}
			else if (p_node->l_child && (p_node->r_child == NULL)) {
				p_node->height = p_node->l_child->height + 1;
			}
			else if ((p_node->l_child == NULL) && p_node->r_child) {
				p_node->height = p_node->r_child->height + 1;
			}
			else {
				p_node->height = 1;
			}
			stk.pop();
			stk_sts.pop();
			//cout << p_node->val << endl;
		}
		status += 1;
	}

	return 0;
}

int AVL_TREE::update_height_bottom_up(TREE_NODE* p_node)
{
	int tmp_height;

	while (p_node != NULL) {
		if (p_node->l_child && p_node->r_child) {
			tmp_height = max(p_node->l_child->height, p_node->r_child->height) + 1;
		}
		else if (p_node->l_child && (p_node->r_child == NULL)) {
			tmp_height = p_node->l_child->height + 1;
		}
		else if ((p_node->l_child == NULL) && p_node->r_child) {
			tmp_height = p_node->r_child->height + 1;
		}
		else {
			/* leaf node, no need to update height */
			p_node = p_node->parent;
			continue;
		}
		
		if (tmp_height != p_node->height) {
			p_node->height = tmp_height;
			p_node = p_node->parent;
		}
		else {
			break;
		}
	}

	return 0;
}

int AVL_TREE::add(int val)
{
	TREE_NODE* cur_node = this->root;
	TREE_NODE* new_node = new TREE_NODE(val);
	string back_trace;

	if (cur_node == NULL) {
		this->root = new_node;
		return 0;
	}

	while (cur_node != NULL) {
		if (new_node->val < cur_node->val) {
			if (cur_node->l_child) {
				cur_node = cur_node->l_child;
			} else {
				new_node->parent = cur_node;
				cur_node->l_child = new_node;
				cur_node = NULL;
			}
		}
		else {
			if (cur_node->r_child) {
				cur_node = cur_node->r_child;
			}
			else {
				new_node->parent = cur_node;
				cur_node->r_child = new_node;
				cur_node = NULL;
			}
		}
	}
	this->update_height_bottom_up(new_node);

	// adjust tree for balance
	cur_node = new_node->parent;
	if (cur_node->l_child == new_node) {
		back_trace += 'L';
	}
	else {
		back_trace += 'R';
	}

	while (cur_node != NULL) {
		if (!is_balance(cur_node)) {
			std::cout << "cur_node val = " << cur_node->val << endl;
			std::cout << "new_node val = " << new_node->val << endl;

			if (back_trace == "LL") {
				AVL_TREE::right_rotate(cur_node);
			}
			else if (back_trace == "LR") {
				AVL_TREE::left_rotate(cur_node->l_child);
				AVL_TREE::right_rotate(cur_node);
			}
			else if (back_trace == "RR") {
				AVL_TREE::left_rotate(cur_node);
			}
			else if (back_trace == "RL") {
				AVL_TREE::right_rotate(cur_node->r_child);
				AVL_TREE::left_rotate(cur_node);
			}
			else {
				cout << "unknown back_trace type: " << back_trace << endl;
				return -1;
			}
			cur_node = NULL;
		}
		else {
			if (cur_node->parent) {
				if (cur_node->parent->l_child == cur_node) {
					back_trace.insert(back_trace.begin(), 'L');
				}
				else {
					back_trace.insert(back_trace.begin(), 'R');
				}
				if (back_trace.length() > 2) {
					back_trace.pop_back();
				}
			}
			cur_node = cur_node->parent;
		}
	}

	// update height from root
	this->update_height_top_down();

	return 0;
}

int AVL_TREE::del(int val)
{
	// find val
	TREE_NODE* cur_node = this->root;

	while (cur_node != NULL) {
		if (val < cur_node->val) {
			cur_node = cur_node->l_child;
		}
		else if (val > cur_node->val) {
			cur_node = cur_node->r_child;
		}
		else {
			break;
		}
	}

	if (cur_node == NULL) {
		cout << "find no val" << endl;
		return -1;
	}

	if (cur_node->l_child && cur_node->r_child) {
		if (cur_node->l_child->height > cur_node->r_child->height) {
			cur_node->l_child->parent = cur_node->parent;
			
		}
	}
}

int AVL_TREE::print_bfs_order(void)
{
	queue<TREE_NODE*> que;
	TREE_NODE* p_node;

	que.push(this->root);
	while (!que.empty()) {
		p_node = que.front();
		que.pop();

		std::cout << "val: " << p_node->val << ", \theight: " << p_node->height << endl;
		if (p_node->l_child)
			que.push(p_node->l_child);
		if (p_node->r_child)
			que.push(p_node->r_child);
	}
	std::cout << "---- print end ----" << endl;

	return 0;
}

void tree_class_demo()
{
	AVL_TREE demo_tree_root;

	demo_tree_root.add(10);
	demo_tree_root.add(5);
	demo_tree_root.add(15);
	demo_tree_root.print_bfs_order();

	demo_tree_root.add(2);
	demo_tree_root.print_bfs_order();

	demo_tree_root.add(1);
	demo_tree_root.print_bfs_order();

	demo_tree_root.add(3);
	demo_tree_root.print_bfs_order();

	demo_tree_root.add(4);
	demo_tree_root.print_bfs_order();
	demo_tree_root.add(7);
	demo_tree_root.print_bfs_order();
	demo_tree_root.add(12);
	demo_tree_root.print_bfs_order();

	demo_tree_root.add(20);
	demo_tree_root.print_bfs_order();
	/*
		val: 5,         height: 4
		val: 2,         height: 3
		val: 10,        height: 3
		val: 1,         height: 1
		val: 3,         height: 2
		val: 7,         height: 1
		val: 15,        height: 2
		val: 4,         height: 1
		val: 12,        height: 1
		val: 20,        height: 1
		---- print end ----
	*/
}
