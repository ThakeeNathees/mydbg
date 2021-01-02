#pragma once
#include "include.h"

typedef long long ll;

ll gcd(ll a, ll b) {
	while (a && b) {
		if (a > b) a %= b;
		else b %= a;
	}
	if (a) return a;
	return b;
}


ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}
