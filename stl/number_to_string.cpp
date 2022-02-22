#include <iostream>
#include <sstream>
#include <string>


class T {
	private:
		T* next;
		int value;


	public:


		
		T() {
			this->next = NULL;
		}
		T(int p) {
			this->next = NULL;
			this->value = p;

		}
		
		void addValue(int p) {
			T *new_node = new T(p);

			T* current_node = this;

			while (current_node->next != NULL) {
				current_node = current_node->next;

			}

			current_node->next = new_node;


		}

		void show_elements() {
			T* current_node = this;
			
			while (current_node->next != NULL) {
				std::cout << "node value:\t" << current_node->value << "\nnode address:\t" << current_node << "\nnode next:\t" << current_node->next << "\n\n";
				current_node = current_node->next;

			}
			std::cout << "node value:\t" << current_node->value << "\nnode address:\t" << current_node << "\nnode next:\t" << current_node->next << "\n\n";

		}
		std::size_t length() {
			T* current_node = this;
			size_t length = 1;
			while (current_node->next != NULL) {
				current_node = current_node->next;
				length++;
			}
			return length;
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
	T* t1 = new T(3);
	T t2(1);

	//t1->show();
	t1->addValue(2);
	t1->addValue(3);
	t1->addValue(4);
	t1->show_elements();
	cout << t1->length() << "\n";
	cout << endl;

	t2.addValue(34);
	t2.addValue(44);
	t2.addValue(54);
	t2.addValue(64);
	t2.show_elements();
	cout << t2.length() << "\n";
	
	return 0;
}
