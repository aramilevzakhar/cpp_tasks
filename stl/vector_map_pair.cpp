#include <ios>
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <strstream>


template<class T>
void print(T const &xs)
{
    std::cout << "[ ";
    for(auto const & x : xs) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    std::cout << "]\n";
}

int main() {
	using namespace std;
	map<int, string> m1l = {};

	m1l.insert(pair<int, string>(1, "Hello friend  1  !"));
	m1l.insert(pair<int, string>(2, "Hello friend  1  !"));
	m1l.insert(pair<int, string>(3, "I miss you very much!"));
	m1l.insert(pair<int, string>(5, "Hello friend  5  !"));


	cout << "count --- " << m1l.count(3) << endl;
	strstream a;

	for (int i=0;i<10;i++) {
		a<<i<<endl;
	}

	// warning
	cout << "__________________________" << endl;
	cout << a.str() << endl;
	cout << a.pcount() << endl;
	cout << "__________________________" << endl;






	for (auto it = m1l.begin(); it != m1l.end(); it++) {

		cout << it->first << " " << it->second << endl;
	}
	cout << "****************************************" << endl;
	cout << fixed << "hello my new ... " << endl;
	cout << m1l.max_size() << endl;
	cout << "****************************************" << endl;

	// equally
	// m1l.erase(3); 

	//auto it = m1l.find(3);
	//m1l.erase(it);

	auto it = m1l.find(3);
	m1l.erase(it, m1l.end());
	cout << "****************************************" << endl;
	map<int, int> myMap = {};

	//m1l.clear();
	for (auto it = m1l.rbegin(); it != m1l.rend(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	cout << "****************************************" << endl;
	map<int, string>::iterator res = m1l.find(3);
	//map<int, string>::iterator res = m1l.begin();
	cout << "run .. run .. run ..." << endl;
	if (res != m1l.end() && cout << "search result" << endl) {
		cout << res->first << " " << res->second << endl;
	}
	cout << "****************************************" << endl;
	map<char, int> first;
	map<char, int> second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;







	


	/*
	for (map<char, int>::iterator it = first.begin(); it != first.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	*/
	cout << "1****************************************" << endl;
	print(first);
	cout << first.count(2) << endl;
	cout << "1****************************************" << endl;


	second = first;
	first = map<char, int>();
	m1l.clear();
	m1l.insert(pair<int, string>(1, "123123"));
	m1l.insert({1, "1233123"});

	cout << "2***************************************2" << endl;
	print(m1l);
	cout << "2***************************************2" << endl;


	pair<char, int> mqwe1;

	cout << mqwe1.first;
	cout << mqwe1.second;


  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';
	m1l.clear();
	/*
	while (res != m1l.end()) {
		cout << res->second << " " << res->first << endl;
		res++;
	}
	*/
	return 0;
}
