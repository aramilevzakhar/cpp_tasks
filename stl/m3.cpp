#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <ranges>

template<class T>
void printInt(T* arr) {
	std::cout << "[ ";
	for (auto element : *arr) {
		std::cout << element << " ";
	}
	std::cout << " ]\n";
}

int main() {
	using namespace std;
	vector<int> m1;
	vector<int> arr = {1, 234, 23, 12, 1, 342, 324, 54, 43, 54, 3, 8, 12};
	vector<int>::iterator it = find(arr.begin(), arr.end(), 8);
	cout << "iterator: " << *it << endl;
	arr.insert(it, 122112213);
	reverse(arr.begin(), arr.end()); // reverse

	vector<int>::iterator first;
	vector<int>::iterator last;
	
	first = arr.begin();
	last = arr.end();
	cout << "distance = " << distance(first, last) << endl;

	for (auto it = arr.end() - 1; it != arr.begin() - 1; --it) {
		cout << *it << " ";
	}


	cout << endl;

	printInt(&arr);
	cout << arr.size() << endl;
	arr.reserve(10);

	cout << arr.size() << endl;
	printInt(&arr);

	cout << "even/ocasional: " << m1.capacity() << endl;
	for (int i = 0; i < 10; i++) {
		m1.push_back(i);
	}
	
	cout << "even/ocasional: " << m1.capacity() << endl;
	vector<int> qu;
	qu.push_back(1);
	qu.push_back(2);
	qu.push_back(3);
	qu.push_back(4);
	qu.push_back(6);
	qu.push_back(6);
	qu[2] = 123;
	deque<double> qu1;
	qu1.push_back(123);
	qu1.push_back(123);
	qu1.push_back(123);
	qu1.push_back(123);
	qu1.push_back(123);
	qu1.push_back(123);
	qu1.push_front(324);
	qu1.push_front(324);
	qu1.push_front(324);
	qu1.push_front(324);
	qu1.push_front(324);
	qu1.push_front(324);
	qu1[4] = 123;

	cout << "deque" << endl;
	for (auto it = qu1.begin(); it != qu1.end(); it++) {
		cout << *it << endl;
	}
	cout << "endl" << endl;



	/*
	cout << " " << endl;
	for (vector<int>::iterator it = m1.begin() + 3; it != m1.end(); it++) {
		cout << *it << endl;

	}
	cout << "wakatta" << endl;
	for_each (m1.begin(), m1.end(), printInt);
	*/
	return 0;
}
