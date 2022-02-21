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
	//cout << std.format("afdsfda {}", 123) << endl;
  vector<int> g1;

  for (int i = 1; i <= 5; i++)
    g1.push_back(i);

  //g1.insert()


	cout << fixed << endl;
	cout << g1.size() << endl;
	cout << g1.max_size() << endl; // get 
	cout << std::setw(10) << 12 << endl; // move a number 
	cout << pow(2, 64) << endl;
	cout << pow(2, 64) << endl;
	cout << pow(2, 64) << endl;
	fstream outfile;
	string str1 = "Hello world";
	char c1;
	string myText;
  //outfile.open("test.txt", std::ios::app | std::ios::binary); // append instead of overwrite
  outfile.open("test.txt", ios::out | ios::app); //| ios::binary); // append instead of overwrite
	while (getline (outfile, myText)) {
		// Output the text from the file
		cout << "myText: " << myText << "\n";
	}
	outfile << str1;
	//outfile.write("helllo world", 11);
	outfile.close();
  //outfile << "Data";
	cout << "----" << endl;
	for (int i = 0; i < g1.size(); i++) {
		cout <<g1[i] << endl;
	}
  cout << "Output of begin and end ";
  for (auto i = g1.begin(); i != g1.end(); ++i) {
		// *i = 3;
    cout << *i << " ";
	}
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




	cout << "--- map" << endl;
	map<char, double> dictinary = {};

	map<string, int> m { {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
	m.insert( pair<string, int>("a", 100) );

	cout << endl;
	for (auto &el : m) {
		cout << el.first << " " << el.second << endl;
	}
	cout << endl;


	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;

	}







  return 0;
}
