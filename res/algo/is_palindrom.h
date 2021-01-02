#pragma once
#include "include.h"

bool is_palindrom(int n) {
	int reverse = 0;
	int _n = n;
	while (_n > 0) {
		reverse = reverse * 10 + _n % 10;
		_n /= 10;
	}
	return reverse == n;
}

bool is_palindrom(const std::string& s) {
	throw 0; // TODO:
}
