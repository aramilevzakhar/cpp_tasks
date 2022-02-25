#include <iostream>
#include <vector>

int main() {
	using namespace std;
	vector<int> v1;


	cout << &v1 << endl;
	v1.push_back(12);
	cout << &v1 << endl;
	v1.push_back(12);
	cout << &v1 << endl;
	v1.push_back(12);
	cout << &v1 << endl;
	v1.push_back(12);
	cout << &v1 << endl;
	v1.push_back(12);

	for (auto &s : v1) {
		cout << s << " ";
	}



	return 0;
}
