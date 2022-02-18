#include <iostream>

using namespace std;
 
class Complex {
	private:
    int real, imag;
	public:
    Complex(int r = 0, int i = 0) {
			real = r;   
			imag = i;
		}
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
      Complex res;
		  cout << "real: " << real << " ";
		  cout << "imag: " << imag << " ";

		  cout << "obj.real: " << obj.real << " ";
		  cout << "obj.imag: " << obj.imag << " ";
		  cout << endl;

      res.real = real + obj.real;
      res.imag = imag + obj.imag;
      return res;
    }


    //friend Complex operator + (Complex const &obj1, Complex const &obj2);
    void print() { 
			cout << real << " + i" << imag << '\n'; 
		}
};

/*
Complex operator + (Complex const &obj1, Complex const &obj2) {
	Complex res;
	cout << "real1.real: " << obj1.real << " ";
	cout << "imag1.imag: " << obj1.imag << " ";

	cout << "obj2.real: " << obj2.real << " ";
	cout << "obj2.imag: " << obj2.imag << " ";
	cout << endl;

	//res.real = obj1.real + obj2.real;
	//res.imag = obj1.imag + obj2.imag;
	return Complex(obj1.real + obj2.real, obj1.imag + obj1.imag);
}
*/
 
class A1 {
	private:
		int x, y;
	public:
		A1 (int a=0, int b=0){
			x = a;
			y = b;
		}
		void show() {
			cout << x << " " << y << endl;
		}
		void set(int a=0, int b=0) {
			x = a;
			y = b;
		}

};

class CCC3 : public A1 {
	using A1::A1;
	private:
		int ss1;
		int ss2;

	
	

};

class CCC1 : public A1 {
	private:
		int x;
		int y;
	public:
		// only explicit conversion
		explicit CCC1(int a = 0, int b = 0) {
			x = a;
			

			y = b;
		}
		void show() {
			cout << x << " " << y << endl;
		}

};

class A {
	public:
		virtual void f() {
			cout << "Hello A" << endl;
		}
};

class B : public A {
	public:
		void f() {
			cout << "Hello B" << endl;
		}
};

int main()
{
	
	A ca1;
	B ba1;

	ca1.f();
	ba1.f();

	A& ar = ca1;
	A& br = ba1;

	ar.f();
	br.f();


	A* ap = &ca1;
	A* bp = &ba1;

	ap->f();
	bp->f();

	// CCC1 b(9, 9);
	// b.show();
	// b = 10; // error
	// b.show();

	/*
	A1 b(3, 6);
	CCC3 b(3, 6);
	b.show();
	b = 10;

	b.show();

  Complex c1(10, 5), c2(2, 4);
  Complex c3 = c1 + c2;
  c3.print();
	*/
	return 0;
}
