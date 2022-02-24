#include <iostream>
#include <list>
#include <vector>



int main() {
	using namespace std;
	vector<int>a = {12, 321, 321};
	list<int>b = {1, 2, 3};

	for (auto obj : a) {
		cout << obj << endl;
	}
	a.assign(7, 100);
	cout << endl;
	for (auto obj : a) {
		cout << obj << endl;
	}
















	return 0;
}



