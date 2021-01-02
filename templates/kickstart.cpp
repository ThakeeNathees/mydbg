
// Headers and Macros ////////////////////////////////////////
#include <bits/stdc++.h>
#ifndef _TESTING
#define MAIN main
#define REDIRECT() std::ios::sync_with_stdio(false); std::cin.tie(nullptr)
#define dbreak(cond) // debug break
#define dbg(exp)     // debug print
#endif

#define input(...) int __VA_ARGS__; read(__VA_ARGS__)
#define print(m_what)  std::cout << (m_what)
#define println(m_what) std::cout << (m_what) << std::endl
#define FOR(i, N) for (size_t i = 0; i < N; i++)

using namespace std;
template <typename T> using vec = vector<T>;
typedef long long ll;
typedef vec<int> ivec; typedef vec<ll> llvec;
typedef vec<ivec> ivec2d;

// Main ///////////////////////////////////////////////////////

template<typename... T> void read(T&... args) { ((std::cin >> args), ...); }
template<typename T> void read(vec<T>& arr) { FOR(i, arr.size()) { std::cin >> arr[i]; } }
#define KICK_START() input(T); for (int t = 1; t <= T; t++) { std::cout << "Case #" << t << ": "; KickStart(); }
// void KickStart() {}

void KickStart() {
	
	

}

int MAIN() {
	REDIRECT();
	KICK_START();
	return 0;
}


// Tests ////////////////////////////////////////////////////////
#ifdef _TESTING
int TEST() {


	// TEST_MAIN(R"()", R"()");
	return 0;
}
#endif // _TESTING

