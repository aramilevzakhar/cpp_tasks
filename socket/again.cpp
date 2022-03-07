#include <ios>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

int main() {
	using namespace std;
	short b = 5;

	for (int i=0;i<10;i++) {
		cout << i << " " << flush;
		this_thread::sleep_for(chrono::seconds(1));
		//sleep(1);

	}
	// cout << b << " " << (b<<1) << endl;
	// cout << fixed << (unsigned)(~b) << endl; // 11111010 -> 010
	return 0;
}
