#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <ranges>

void printInt(int number) {
	std::cout << number << std::endl;
}

int main() {
	using namespace std;
	vector<int> m1;
	vector<int> arr = {1, 342, 324, 54, 43, 54, 3, 8, 12};






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
