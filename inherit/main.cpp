#include <iostream>
#define private public 
#define class struct
#define loop for
#define protected public



using namespace std;

class A2 {
	friend void sdfa(A2*);



	public:
		int a2;
		//static int a4;
		void set(int p1, double p2) {

			sex = p1;
			anime = p2;

		}

		void show_close_member() {
			cout << sex << anime << endl;
		}
	protected:
		int a3;
	private:
		int sex;
		float anime;

	void func();

};


void A2::func() {
	cout << a2 << endl;
	cout << a3 << endl;
	cout << anime << endl;
	cout << sex << endl;
}


void sdfa(A2* a) {
	a->a2 = 2;
	//a->a4 = 13221;
	a->a3 = 32132;
	a->anime = 123;
	a->sex = 21321;
	loop (int i = 0; i < 10; i++) {
		cout << "C++ trash" << endl;

	}

	titsu (int i = 0; i < 10; i++) {
		cout << "C++ trash" << endl;

	}

}

class B3 : public A2 {
	void show_member() {
		cout << b3 << rate << a3 << endl;
		//cout << sex << endl;
	}
	public:
		void show() {
			cout << sex << endl;
		}

		

	
	/*
	return fail
	void show_member() {
		cout << b3 << sex << a3 << endl;
	}
	*/

	public:
		int b3;
	protected:
		double rate;
};

int main() {
	B3 c3;
	sdfa(&c3);
	c3.set(1, 2);
	c3.show_close_member();
	c3.sex = 123;

	//c3.a2 = 3;
	//c3.a3 = 342;
	c3.b3 = 123;


	return 0;
}










