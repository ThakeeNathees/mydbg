
// Headers and Macros ////////////////////////////////////////
#include <bits/stdc++.h>
#ifndef _TESTING
#define MAIN main
#define REDIRECT() std::ios::sync_with_stdio(false); std::cin.tie(nullptr)
#define dbreak(cond) // debug break
#define dbg(exp)     // debug print
#endif

#define FOR(i, N) for (size_t i = 0; i < N; i++)

using namespace std;
template <typename T> using vec = vector<T>;
typedef long long ll;
typedef vec<int> ivec; typedef vec<ll> llvec;
typedef vec<ivec> ivec2d;

// Solution ///////////////////////////////////////////////////
class Solution {
public:

};

// Tests ////////////////////////////////////////////////////////
#ifdef _TESTING
// "[10,9,2,5,3,7,101,18]" -> {10, 9, ...}
ivec& to_arr(const char* arr) {
	static ivec ret; // to return as reference
	arr += 1; // skip '['
	ret.clear(); string num;
	while (true) {
		if (*arr == ',' || *arr == ']') {
			ret.push_back(std::stoi(num));
			num = "";
			if (*arr++ == ',') continue;
			else return ret;
		}
		num += *arr++;
	}
}

int TEST() {

	//CHECK();
	return 0;
}
#endif // _TESTING

