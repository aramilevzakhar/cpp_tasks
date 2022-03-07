#include <iostream>
#include <thread>

#include <list>
#include <time.h>
#include <random>




template<class T>
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

	//cout << "Список пуст?: " << array.empty() << endl;
	for (int i = 0; i < 10; i++) {
		array.push_back(rand() % 10);
	}
	/*
	for (auto l=array.begin(); l != array.end(); l++) {
		cout << *l << endl;

	}
	*/

	/*
	print(array);
	cout << "Список пуст?: " << array.empty() << endl;
	array.pop_back();
	print(array);
	*/

	/*
	array.pop_front();
	print(array);

	array.insert(array.begin(), 2, 10);
	print(array);

	array.insert(array.begin(), 20, 10);
	array.insert(array.begin(), 123, 123);

	*/
	auto a = array;
	a.push_back(3);

	print(a);
	print(array);

	vector <double> d3 = {};
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d3.push_back(5);
	d3.push_back(6);
	d3.push_back(7);


	print(d3);
	cout << d3.capacity() << endl;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	print(d3);
	cout << d3.capacity() << endl;
	d3.push_back(4);
	d3.push_back(5);
	d3.push_back(6);
	d3.push_back(7);
	print(d3);
	cout << d3.capacity() << endl;
	//list <double> i3 = {};
	int a342 = 20432;
	int b243 = 12;
	try {

		if (b243 == 123) {
			cout << "" << endl;
		} else {
			throw (a342);
		}
	} catch(int mmmm) {
		cout << "buthert" << endl;
		cout << mmmm << endl;

	}
	


	//i3.unique();

	






/*
	print(array);
	array.unique();
	print(array);
	array.sort();
	print(array);
	*/
	//array.erase(array.begin(), array.end());
/*
	array.erase(array.begin(), array.end());
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);
	array.push_back(7);
	array.erase(array.begin(), next(array.begin(), 3));
	array.clear();
	cout << "Happening erase().. " << endl;
	print(array);
*/
	//array.erase(array.begin());

	
	return 0;
}
