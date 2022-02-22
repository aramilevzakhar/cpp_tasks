#include <iostream>
#include <sstream>
#include <string>


class T {
	private:
		T* next;
		int value;
	public:
		void addValue(int p) {
			T *new_node = new T;
			new_node->value = p;
			new_node->next = NULL;

			T* current_node = this;
			while (current_node->next != NULL) {
				current_node = current_node->next;
			}
			current_node->next = new_node;
		}

		void show_elements() {
			T* current_node = this;
			
			while (current_node->next != NULL) {
				std::cout << current_node->value << std::endl;
				current_node = current_node->next;

			}
			std::cout << current_node->value << std::endl;


		}
};




int main() {
	using namespace std;
	/*
	ostringstream str1;
	int number = 12313;
	double float_point = 123.234;
	str1 << float_point;
	string s1 = str1.str();
	cout << s1 << endl;
	string three = to_string(3);
	cout << three << endl;
	cout << "My lst" << endl;
	*/
	T* t1 = new T;

	//t1->show();
	t1->addValue(2);
	t1->addValue(3);
	t1->addValue(4);
	t1->show_elements();
	
	return 0;
}
