// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <iomanip>
#include <boost/io/ios_state.hpp> 
#include <fstream>

//#include <format>

using namespace std;
  
/*
#if __has_include(<format>)
#include <format>
#endif

#ifdef __cpp_lib_format
// Code with std::format
#else
// Code without std::format, or just #error if you only
// want to support compilers and standard libraries with std::format
#endif
*/


int main()
{
	//boost::io::ios_flags_saver ifs(os);
  vector<int> g1;
	//cout << std.format("afdsfda {}", 123) << endl;
	


  for (int i = 1; i <= 5; i++)
    g1.push_back(i);


	cout << fixed << endl;
	cout << g1.size() << endl;
	cout << g1.max_size() << endl; // get 
	cout << std::setw(10) << 12 << endl; // move a number 
	cout << pow(2, 64) << endl;
	cout << pow(2, 64) << endl;
	cout << pow(2, 64) << endl;

  //ofstream outfile;
  //ifstream outfile;
	fstream outfile;


	string str1;
	char c1;
  //outfile.open("test.txt", std::ios::app | std::ios::binary); // append instead of overwrite
  outfile.open("test.txt", ios::out); //| ios::binary); // append instead of overwrite
	outfile >> c1;
	//outfile.write("helllo world", 11);
	outfile.close();
  //outfile << "Data";




  cout << "Output of begin and end ";
  for (auto i = g1.begin(); i != g1.end(); ++i) {
		// *i = 3;
    cout << *i << " ";
	}

	// const 
  cout << "\nOutput of cbegin and cend: ";
  for (auto i = g1.cbegin(); i != g1.cend(); ++i) {
		//*i = 31; // error
    cout << *i << " ";
	}



  cout << "\nOutput of rbegin and rend: ";
  for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) {
      cout << *ir << " ";
	}

	// const
  cout << "\nOutput of crbegin and crend : ";
  for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir) {
      cout << *ir << " ";
	}

  return 0;
}
