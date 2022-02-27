// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section


namespace werwe {
	void print_block (int n, char c) {
		// critical section (eclusive access to std::cout signaled by locking mtx):
		using namespace std;
		mtx.lock();
		for (int i=0; i<n; ++i) { std::cout << c; }
		cout << '\n';
		mtx.unlock();
	}
};

namespace w1 {
	void print_block (int n, char c) {
		// critical section (eclusive access to std::cout signaled by locking mtx):
		using namespace std;
		mtx.lock();
		for (int i=0; i<n; ++i) { std::cout << c; }
		cout << '\n';
		mtx.unlock();
	}
}
int main () {
	using namespace std;
	using namespace werwe;
	using namespace w1;
  std::thread th1 (werwe::print_block,50,'*');
  std::thread th2 (werwe::print_block,50,'$');

  th1.join();



  th2.join();

  return 0;
}
