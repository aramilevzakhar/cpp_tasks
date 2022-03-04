#include <ios>
#include <iostream>
#include <utility>
#include <string.h>
#include <map>


template <class abc>
class A {
	typename abc::iterator a;
	public:
		void print() { 
			std::cout << a << std::endl; }

};


template<class T> 
void print_hello(T p) {
	using namespace std;

	cout << p << endl;
}

template<class T> 
void print_start() {
	using namespace std;
	T p = 23;

	cout << p << endl;

}

int 
main() {
	using namespace std;
	// A<map<int, int>> a1;
	// a1.print();
	// cout << fixed << endl;
	// print_hello<double>(4);
	// print_hello<string>("hello");
	print_start<int>();


	return 0;
}
