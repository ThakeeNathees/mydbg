
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

// Solution ///////////////////////////////////////////////////

class Solution {
    int ans = 0;
    vector<vector<bool>> visited;
    int squire = 2;
    //dbgvec2d<int>* dbgv;

    void travel(vector<vector<int>>& grid, int x, int y, int len) {
        if (visited[x][y]) return;

        //dbgv->add_color(x, y, Color::D_SKYBLUE);
        //TesterGlobals::print_pause = false;
        //dprint((*dbgv)(x,y));
        //printf("ans = %i\n", ans);
        //getchar();

        visited[x][y] = true; len++;
        if (grid[x][y] == 2) {
            if (len == squire) ans++;
        } else {
            if (x > 0) travel(grid, x - 1, y, len);
            if (y > 0) travel(grid, x, y - 1, len);
            if (x < grid.size() - 1) travel(grid, x + 1, y, len);
            if (y < grid[0].size() - 1) travel(grid, x, y + 1, len);
        }
        visited[x][y] = false;
        //dbgv->remove_color(x, y);
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        //dbgv = new dbgvec2d<int>(grid);

        int x = 0, y = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) squire++;
                else if (grid[i][j] == 1) x = i, y = j;
                else if (grid[i][j] == -1) visited[i][j] = true;
            }
        }


        travel(grid, x, y, 0);
        return ans;
    }
};

// Main ///////////////////////////////////////////////////////

template<typename... T> void read(T&... args) { ((std::cin >> args), ...); }
template<typename T> void read(vec<T>& arr) { FOR(i, arr.size()) { std::cin >> arr[i]; } }
#define KICK_START() input(T); for (int t = 1; t <= T; t++) { std::cout << "Case #" << t << ": "; KickStart(); }
// void KickStart() {}

void KickStart() {
	//input(N);
}

int MAIN() {
	REDIRECT();
	//KICK_START();

	return 0;
}


// Tests ////////////////////////////////////////////////////////
#ifdef _TESTING
int TEST() {

    ivec2d arr = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    Solution().uniquePathsIII(arr);
	// TEST_MAIN(R"()", R"()");
	return 0;
}
#endif // _TESTING

