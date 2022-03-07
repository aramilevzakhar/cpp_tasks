#include <iostream>
#include "aaa.h"


int func(int a) {
	if (a == 1) return 1;
	return a * func(a - 1);

}

int func1(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}


	return func1(n - 1) + func1(n - 2);
}
