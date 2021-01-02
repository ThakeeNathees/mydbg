#pragma once
#include "include.h"

int64_t fib(int64_t n) {
	double phi = (1 + sqrt(5)) / 2;
	return (int64_t) (round(pow(phi, n) / sqrt(5)));
}
