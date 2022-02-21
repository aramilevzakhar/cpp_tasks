#include <iostream>
#include <map>
#include <utility>

int main() {
	using namespace std;
	map<int, string> m1l = {};

	m1l.insert(pair<int, string>(1, "Hello friend  1  !"));
	m1l.insert(pair<int, string>(2, "Hello friend  1  !"));
	m1l.insert(pair<int, string>(3, "Hello friend  3  !"));
	m1l.insert(pair<int, string>(4, "Hello friend  4  !"));
	m1l.insert(pair<int, string>(5, "Hello friend  5  !"));



	for (auto it = m1l.begin(); it != m1l.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << "**not*end****" << endl;
	//m1l.clear();
	for (auto it = m1l.rbegin(); it != m1l.rend(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << "**end****" << endl;



	//map<int, string>::iterator res = m1l.find(3);
	//map<int, string>::iterator res = m1l.begin();

	/*
	if (res != m1l.end() && cout << "H" << endl) {
		cout << res->first << " " << res->second << endl;
	}
	*/


	cout << "******" << endl;
	m1l.clear();
	/*
	while (res != m1l.end()) {
		cout << res->second << " " << res->first << endl;
		res++;
	}
	*/





	return 0;
}
