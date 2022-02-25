#include <iostream>
#include <numeric>
#include <vector>
#include <string>
// #include <format>
#include <fmt/core.h>




int main() {
	using namespace std;
	vector<int> v1;
	v1 = {1, 2, 3, 4, 5, 6};
	int sum = accumulate(v1.begin(), v1.end(), 0);
	cout << fmt::format("string v1 {}", sum) << endl;





	return 0;
}
