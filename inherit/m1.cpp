#include <iostream>
#include <time.h>

#include "aaa.h"

class Anime {
	private:
		int x;
		int y;
		int z;
		int f;
		int speed;

	public:
		void set(int x, int y, int z);
		void set_x(int x);
		void set_y(int y);
		void set_z(int z);
		void set_f(int f);
		void set_speed(int speed);
		void show() {
			std::cout << x << "\n";
			std::cout << y << "\n";
			std::cout << z << "\n";
		}
	protected:
		int z1;
		int z2;
		size_t z3;
		size_t z4;
		size_t z5;


	friend void function(Anime, int, int, int);
	friend void function(Anime*, int, int, int);

};


class Govno : public Anime {

};


void function(Anime* Ac, int p1, int p2, int p3) {
	Ac->x = p1;
	Ac->y = p2;
	Ac->z = p3;
}

void Anime::set(int x, int y, int z) {
	this->x = x;
	this->y = x;
	this->z = z;

}

void Anime::set_y(int y) {

}

void Anime::set_z(int z) {

}

void Anime::set_speed(int speed) {

}

void Anime::set_f(int f) {


}

int main() {
	srand(time(NULL));
	using namespace std;
	Govno p;
	Govno* p1;
	p1 = new Govno[120];
	p.set(1,1,1);
	p.show();



	for (int i = 0; i < 120; i++) {
		p1[i].set(3, 3, 3);
		p1[i].show();
	}

	int b = 3;
	cin >> b;
	
	cout << "factorial: " << func(b) << endl;

	for (int i = 1; i < 10; i++) {
		cout << func1(i) << endl;

	}




	return 0;
}
