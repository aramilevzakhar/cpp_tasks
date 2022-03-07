#include <sstream>
#include <thread>
#include <unistd.h>
#include <locale>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <chrono>
#include <map>





namespace used {
	class B {
		int a;
		size_t b;

	};

};

namespace function_function {
	void function(int& p) {
		using namespace std;

		cout << p << endl;
		int i = 0;
		while (true) { cout << i++ << endl; }
	}

}







int main() {
	using namespace std;
	int a = 10; int c = 10; int d = 10;
	cout << "start program! " << endl;
	chrono::system_clock::time_point timePt = chrono::system_clock::now() + chrono::seconds(60);
	//this_thread::sleep_until(timePt);

	time_t timeStamp = chrono::system_clock::to_time_t(timePt);
	cout << ctime(&timeStamp) << endl;



	cout << "end program! " << endl;
	return 0;
  // boolalpha output
	//istringstream ppp("100 101 110 111");
	//int n1, n2, n3;
	//using namespace used;
	//B a;



	/*
	//this_thread::sleep_until(chrono::seconds())
	cout << resetiosflags(ios_base::dec) << setiosflags(ios_base::hex | ios_base::uppercase | ios_base::showbase) << 34 << '\n';

	thread newThr;

	newThr = thread(function, ref(a));


	//newThr.join();
	newThr.detach();
	*/


	using namespace std;
	thread b[100];
	for (int i=0;i<100;i++) {
		//cout << i << " " << flush;
		b[i] = thread(system, "urxvt");
		usleep(1000000);
	}


	for (int i=0;i<100;i++) {
		cout << "detach starting" << endl;
		b[i].detach();
	}
















	/*
	ppp >> oct >> n1 >> n2 >> n3;
	cout << "n1: " << n1 << "\nn2: " << n2 << "\nn3: " << n3 << endl;

	ppp >> hex >> n1 >> n2 >> n3;
	cout << "n1: " << n1 << "\nn2: " << n2 << "\nn3: " << n3 << endl;
	
	ppp >> dec >> n1 >> n2 >> n3;
	cout << "n1: " << n1 << "\nn2: " << n2 << "\nn3: " << n3 << endl;
	*/

	/*
  cout << boolalpha 
            << "boolalpha true: " << true << '\n'
            << "boolalpha false: " << false << '\n'
            << "noboolalpha true: " << true << '\n'
            << "noboolalpha false: " << false << '\n';
		
	cout << resetiosflags(ios_base::basefield)
            << "boolalpha false: " << false << '\n'
            << "noboolalpha true: " << true << '\n'
            << "noboolalpha false: " << false << '\n';
	cout << flush;
	*/

  //cout << noboolalpha 
  //cout << noboolalpha 
  // boolalpha parse
  bool b1, b2;
  istringstream is("true false");
  is >> boolalpha >> b1 >> b2;
  cout << '\"' << is.str() << "\" parsed as " << b1 << ' ' << b2 << '\n';
}
