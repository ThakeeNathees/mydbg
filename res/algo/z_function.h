#pragma once
#include "include.h"

std::vector<size_t> z_function(const std::string& str) {
	size_t n = str.size();
	std::vector<size_t> z(n);
	z[0] = 0;

	size_t l = 0, r = 0;
	for (size_t i = 1; i < n; i++) {

		if (i >= r) {
			l = r = i;
			while (r < n && str[r - l] == str[r]) r++;
			z[i] = r - l;

		} else {

			if (i + z[i - l] < r) {
				z[i] = z[i - l];
			} else {
				l = i;
				while (r < n && str[r - l] == str[r]) r++;
				z[i] = r - l;
			}
		}
	}
	return z;
}
