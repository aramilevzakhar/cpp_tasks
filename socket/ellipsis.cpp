#include <cstdarg>
#include <iostream>
  
double average(int count, ...) {
	using namespace std;
	va_list list;
	va_start(list, count);

	double avg = 0.0;
	for (int i = 0; i < count; i++) {
		avg += static_cast<double>(va_arg(list, int)) / count;
	}

	return avg;
}

int main() {
	using namespace std;
	// this is use to dangerous
	double avg = average(100, 1, "Hello all around world", 3, 4, 5, 6);
	cout << "Average is " << avg;
	return 0;
}
