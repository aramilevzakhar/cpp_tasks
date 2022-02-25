#include <iostream>
#include <list>
#include <vector>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

void print_1() {
	using namespace std;
	cout << "print 1" << endl;
}

//template <typename... Args, std::enable_if_t<
void print_2() {
	using namespace std;
	cout << "print 2" << endl;
}

template<typename... Args, std::enable_if_t<sizeof...(Args) == 0, int> = 0>
void print(const std::tuple<Args...>& t)
{
    std::cout << "()\n";
}
 
template<typename... Args, std::enable_if_t<sizeof...(Args) != 0, int> = 0>
void print(const std::tuple<Args...>& t)
{
    std::cout << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    std::cout << ")\n";
}




int main() {
	using namespace std;
	vector<int>a = {12, 321, 321};
	list<int>b = {1, 2, 3};
	int a1 = 0;

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



