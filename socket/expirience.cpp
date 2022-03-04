#include <iostream>
#include <vector>

template<typename T0 = void, typename T1, typename T2>
T0 print_somowhat(T1 a1, T2 a2) {
	using namespace std;
	// cout << sizeof(T0) << endl;
	cout << sizeof(T1) << endl;
	cout << sizeof(T2) << endl;
	return a1+a2;

}



void print_message(...) {
	using namespace std;
	cout << "Hello new message! " << endl;

}

template<class T> 
void print_answer(T* m) {
	using namespace std;
	cout << m << endl;

}


int main() {
	using namespace std;
	vector<int> v1;
	//print_somowhat<double, double, double>(1, 3);
	//int number = 101;
	//int *num_ptr = &number;
	//print_answer<int>(num_ptr);
	//print_answer<int>(&number);
	print_message(234, 123);



	cout << endl;
	//print_somowhat<int, int, int>(1, 3);





	/*
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
	*/



	return 0;
}
