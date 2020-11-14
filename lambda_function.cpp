#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "leetcode.h"
using namespace std;

void lambda_func_demo()
{
	char str[] = "Hello World, HAHA";
	int x = 10;
	auto fx = [x]() mutable {
		x = 20;
		cout << "fx: " << x << endl;
	};
	auto fy = [&x]() {
		x = 20;
		cout << "fy: " << x << endl;
	};
	auto fz = [](int& x) {
		x = 30;
		cout << "fz: " << x << endl;
	};

	for_each(str, str + sizeof(str), [](char c) {
		cout << c << endl;
	});

	cout << x << endl;
	fx();
	cout << x << endl;
	fy();
	cout << x << endl;
	fz(x);
	cout << x << endl;
}