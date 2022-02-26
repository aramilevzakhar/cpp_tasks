#include <iostream>
#include <tuple>
#include <string>
 
// helper function to print a tuple of any size

/*
template<class Tuple, std::size_t N>
struct TuplePrinter {
    static void print(const Tuple& t) 
    {
        TuplePrinter<Tuple, N-1>::print(t);
       std::cout << ", " << std::get<N-1>(t);
    }
};
 
template<class Tuple>
struct TuplePrinter<Tuple, 1> {
    static void print(const Tuple& t) 
    {
        std::cout << std::get<0>(t);
    }
};
*/
 
template<typename... Args, std::enable_if_t<sizeof...(Args) == 0, int> = 0>
void print(const std::tuple<Args...>& t) {
	using namespace std;
	std::cout << "()\n";

	cout << "zero" << endl;

}
 
template<typename... Args, std::enable_if_t<sizeof...(Args) == 3, int> = 0>
void print(const std::tuple<Args...>& t) {
	using namespace std;
	std::cout << "(";
	//TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	cout << "not zero" << endl;
		
	std::cout << ")\n";
}

 
int main() {
	using namespace std;

	double a11 = 43;
	decltype(a11) b;
	cout << b << endl;

  std::tuple<int, std::string, float> t1(10, "Test", 3.14);
  int n = 7;
  auto t2 = std::tuple_cat(t1, std::make_tuple("Foo", "bar"), t1, std::tie(n));
  n = 42;
	tuple<int, int, int> n1; // = {0, "Hello", 2, 3, 4, 5};
  print(n1);
	return 0;
} 
