#include <iostream>
#include <sstream>
#include <string>


int main() {
	using namespace std;
	ostringstream str1;
	int number = 12313;
	double float_point = 123.234;
	str1 << float_point;
	string s1 = str1.str();
	cout << s1 << endl;
	string three = to_string(3);
	cout << three << endl;
	
	return 0;
}
