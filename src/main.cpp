
#define DBG_IMPLEMENT
#include "dbg.h"

/* --------------------------------------------- */
#include <bits/stdc++.h>
#ifndef DBG_IMPLEMENT
#define MAIN main
#define REDIRECT() std::ios::sync_with_stdio(false); std::cin.tie(nullptr)
#endif
#define input(m_type, m_name) m_type m_name; std::cin >> m_name
#define print(m_what)  std::cout << (m_what)
#define println(m_what) std::cout << (m_what) << std::endl
#define FOR(i, N) for (size_t i = 0; i < N; i++)
using namespace std;
#define KICK_START() input(int, T); for (int t = 1; t <= T; t++) { std::cout << "Case #" << t << ": "; KickStart(); }
void KickStart() {}

int MAIN() {
	REDIRECT();
	/* your code */

	return 0;
}

/* --------------------------------------------- */
#ifdef DBG_IMPLEMENT
int TEST() {
	//TEST_MAIN(R"()", R"()");
	//CHECK(ecpected, result);
}
#endif
