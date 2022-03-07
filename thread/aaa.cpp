#include <thread>
#include <iostream>

using namespace std;

void anime(int a) {
	int s = 0;
	do {
		s++;
		cout << s << endl;
	} while (s <= 100000);
  //return 5;
	cout << a << endl;
}

int main() {

	thread ss1(anime, 3);

	
	
	
	cout << "hello world" << endl;


	ss1.join();
	//ss1.detach();

	return 0;
}
