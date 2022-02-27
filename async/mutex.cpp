#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
 
std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;
 
void save_page(const std::string &url, int tmp) {
  // simulate a long page fetch
	std::cout << tmp << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::string result = "fake content";

 
  std::lock_guard<std::mutex> guard(g_pages_mutex);
  g_pages[url] = result;
	g_pages_mutex.lock();
}
 
int main() {
	using namespace std;
	//cout << "run first thread" << endl;
  thread t1(save_page, "http://foo", 1);
	//cout << "run second thread" << endl;
  thread t2(save_page, "http://bar", 2);
  t1.join();
  t2.join();
 
  // safe to access g_pages without lock now, as the threads are joined
  for (const auto &pair : g_pages) {
      cout << pair.first << " => " << pair.second << '\n';
  }
	return 0;
}
