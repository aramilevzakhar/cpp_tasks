#include <cstdarg>
#include <iostream>
  
double average(int count, ...) {
	using namespace std;
	va_list list;
	va_start(list, count);
	double avg = 0.0;
	//for (int i = 0; i < 100; i++) {
	cout << static_cast<double>(va_arg(list, int)) << endl;
	cout << static_cast<double>(va_arg(list, int)) << endl;
	cout << static_cast<double>(va_arg(list, int)) << endl;
	cout << static_cast<double>(va_arg(list, int)) << endl;
			//avg += static_cast<double>(va_arg(list, int)) / count;
	//}
	va_end(list);
	return avg;
}

int main() {
	using namespace std;
	double avg = average(6, 1, 2, 3, 4, 5, 6);
	cout << "Average is " << avg;
	return 0;
}
