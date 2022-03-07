#include <iostream>
#include <array>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <string>

template<class T>
void print(T* arr) {
	using namespace std;
	cout << " [";
	for (auto &element : *arr) {
		element = rand() % 100;
		cout << element << " ";
	}
	cout << "];\n";


}
int main() {
	srand(time(NULL));
	using namespace std;
	array<int, 100> arr = {}; // = {1, 2, 3, 4, 5};

	//[[ maybe_unused ]] array arr1{1, 2, 3, 4, 5} // C++17


	// fill three
	// arr.fill(3);
	
	print(&arr);

	sort(arr.begin(), arr.end());
	
	print(&arr);

	cout << "Size: " << arr.size() << endl;


	return 0;
}
