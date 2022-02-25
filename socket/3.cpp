#include <iostream>
#include <tuple>
#include <thread>
#include <time.h>
#include <unistd.h>

template<class... T>
void print(std::tuple<T...>) {


}


void print_line(int i) {
	using namespace std;
	sleep(rand() % 10);
	cout << i << endl;
}

int main() {
	srand(time(NULL));
	using namespace std;

	tuple<int, int, int, int> tuple1;
	tuple<int, int, int, int> tuple2;
	tuple<int, int, int, int, int, int, int, int> tuple3;

	tuple<int, double, float, string> tuple4;

	thread thArr[10];
	for (int i = 0; i < 10; i++) {
		thArr[i] = thread(print_line, i);
	}

	int a = 3, b, c, d;
	tuple1 = {3, 3, 3, 3};
	tuple2 = {3, 3, 3, 3};
	tuple3 = tuple_cat(tuple1, tuple2);

	cout << "tuple3: " << get<0>(tuple3) << endl;



	tie(a,b,c,d);

	// cout << tuple1 << endl << tuple2 << endl << tuple3 << endl;

	for (int i = 0; i < 10; i++) {
		thArr[i].join();
	}



	return 0;
}
