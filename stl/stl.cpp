#include <map>
#include <iostream>
#include <deque>

template<class T>
void print(T const& lst) {
	std::cout << "[ ";
	for (auto &p : lst) {
		std::cout << p << " ";
	}
	std::cout << "] " << std::endl;

}

int main() {
	using namespace std;
	deque<int> queue;

	queue.push_back(1);
	queue.push_back(2);
	queue.push_back(6);

	print(queue);


	queue.push_front(123);
	print(queue);
	cout << "this is empty? " << queue.empty() << endl;

	queue.insert(queue.begin()+2, 10000);
	print(queue);
	queue.shrink_to_fit();
	print(queue);



	return 0;
}


