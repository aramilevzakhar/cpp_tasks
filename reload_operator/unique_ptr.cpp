#include <iostream>
#include <list>
#include <time.h>
#include <random>




template<typename T>
void print(T const & xs)
{
    std::cout << "[ ";
    for(auto const & x : xs) {
        std::cout << x << ' ';
    }
    std::cout << "]\n";
}

int main() {
	srand(time(NULL));
	using namespace std;
	list<int> array = {};

	cout << "Список пуст?: " << array.empty() << endl;
	for (int i = 0; i < 10; i++) {
		array.push_back(rand() % 10);
	}
	/*
	for (auto l=array.begin(); l != array.end(); l++) {
		cout << *l << endl;

	}
	*/

	print(array);
	cout << "Список пуст?: " << array.empty() << endl;
	array.pop_back();
	print(array);

	array.pop_front();
	print(array);
	array.insert(array.begin(), 2, 10);
	print(array);
	array.insert(array.begin(), 20, 10);
	array.insert(array.begin(), 123, 123);
	print(array);





	//array.erase(array.begin());

	
	return 0;
}
