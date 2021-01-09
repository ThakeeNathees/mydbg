/*
   MIT License
   Copyright (c) 2020 Thakee Nathees
*/

#ifdef __USAGE__ //////////////////////////////////////////////////////////////////////////

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

	println("input");

	/* your code */

	return 0;
}

/* --------------------------------------------- */
#ifdef DBG_IMPLEMENT
int TEST() {
	// TEST_MAIN(R"()", R"()");
	//CHECK(, );
}
#endif

#endif // __USAGE__ ///////////////////////////////////////////////////////////////////////

#ifndef DBG_H
#define DBG_H

#ifndef __CODE_FOLD1__

#include <bits/stdc++.h>

#define MAIN _main
#define TEST main

#define STRING(x) #x
#define STRINGIFY(x) STRING(x)

#define CHECK(m_result, m_expected)                                  \
do {                                                                 \
	printf("TEST (line:" STRINGIFY(__LINE__) "): ");                 \
	if (m_result != m_expected) {                                    \
		cprint("FAILURE\n", Color::L_RED);                           \
		printf("\tEXPECTED : %s\n", _to_string(m_expected).c_str()); \
		printf("\tRESULT   : %s\n", _to_string(m_result).c_str());   \
	} else {                                                         \
		cprint("SUCCESS\n", Color::L_GREEN);                         \
	}                                                                \
}  while (false)

#define TIMER_START() TesterGlobals::timer_line = __LINE__, TesterGlobals::timer_t0 = std::chrono::steady_clock::now()
#define TIMER_END()                                                                             \
	printf("TIMER (line:%i): ", TesterGlobals::timer_line),                                     \
	TesterGlobals::timer_duration = std::chrono::steady_clock::now() - TesterGlobals::timer_t0, \
	cprint(_to_string(TesterGlobals::timer_duration.count() * 1000).append(" ms\n").c_str(), Color::L_SKYBLUE)


#define REDIRECT()                                                       \
	class Redirect {									                 \
		std::istringstream isstream;					                 \
		std::ostringstream osstream;					                 \
		std::streambuf* istream_buf;					                 \
		std::streambuf* ostream_buf;					                 \
	public:												                 \
		Redirect() {									                 \
			istream_buf = std::cin.rdbuf();				                 \
			isstream = std::istringstream(TesterGlobals::_INPUT_BUFF);	 \
			std::cin.rdbuf(isstream.rdbuf());			                 \
			ostream_buf = std::cout.rdbuf();			                 \
			osstream = std::ostringstream(TesterGlobals::_OUTPUT_BUFF);  \
			std::cout.rdbuf(osstream.rdbuf());			                 \
		}												                 \
		~Redirect() {									                 \
			TesterGlobals::_OUTPUT_BUFF = strip(osstream.str());		 \
			std::cin.rdbuf(istream_buf);				                 \
			std::cout.rdbuf(ostream_buf);				                 \
		}												                 \
	};													                 \
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); Redirect redirect

#define TEST_MAIN(m_input_buff, m_output_buff)                             \
	TesterGlobals::_EXPECTED_OUTPUT = strip(m_output_buff);                \
	TesterGlobals::_INPUT_BUFF = strip(m_input_buff);                      \
	TesterGlobals::_OUTPUT_BUFF = "";                                      \
	MAIN();                                                                \
	printf("LINE [" STRINGIFY(__LINE__) "]: ");                            \
	if (TesterGlobals::_OUTPUT_BUFF != TesterGlobals::_EXPECTED_OUTPUT ) { \
		cprint("FAILURE\n", Color::L_RED);                                 \
		cprint("\tEXPECTED : ", Color::L_YELLOW); printf("%s\n", TesterGlobals::_EXPECTED_OUTPUT .c_str());  \
		cprint("\tRESULT   : ", Color::L_YELLOW); printf("%s\n", TesterGlobals::_OUTPUT_BUFF.c_str());       \
	} else {                                                               \
		cprint("SUCCESS\n", Color::L_GREEN);                               \
	}

enum class Color {
	BLACK = 0,

	L_BLUE = 1,
	L_GREEN = 2,
	L_SKYBLUE = 3,
	L_RED = 4,
	L_PINK = 5,
	L_YELLOW = 6,
	L_WHITE = 7,
	L_GRAY = 8,

	D_BLUE = 9,
	D_GREEN = 10,
	D_SKYBLUE = 11,
	D_RED = 12,
	D_PINK = 13,
	D_YELLOW = 14,
	D_WHITE = 15,
};

class TesterGlobals { // a static class for globals.
public:
	// timer variables
	static int timer_line;
	static std::chrono::steady_clock::time_point timer_t0;
	static std::chrono::duration<double> timer_duration;

	// IO variables
	static std::string _INPUT_BUFF;
	static std::string _OUTPUT_BUFF;
	static std::string _EXPECTED_OUTPUT;
};

std::string strip(const std::string& str);
void clear_console();
void set_cursor_pos(int column, int line);
void cprint(const char* p_msg, Color p_fg, Color p_bg = Color::BLACK);


template<class T> struct is_vector {
	static bool const value = false;
};
template<class T> struct is_vector<std::vector<T> > {
	static bool const value = true;
};

template<class T> struct is_map {
	static bool const value = false;
};

template<class T1, class T2> struct is_map<std::map<T1, T2> > {
	static bool const value = true;
};

template <typename T>
std::string _to_string(const T& value) {
	if constexpr (std::is_same<T, bool>::value) {
		return value ? "true" : "false";
	} else if constexpr (std::is_arithmetic<T>::value) {
		return std::to_string(value);
	} else if constexpr (std::is_same<T, std::string>::value || std::is_same<T, const std::string&>::value) {
		return value;

	} else if constexpr (std::is_same<T, std::vector<bool>>::value) {
		std::string ret = "[ ";
		for (size_t i = 0; i < value.size(); i++) {
			if (i != 0) ret += ", ";
			ret += (value[i]) ? "true" : "false";
		}
		return ret + " ]";
	} else if constexpr (is_vector<T>::value) {
		std::string ret = "[ ";
		for (size_t i = 0; i < value.size(); i++) {
			if (i != 0) ret += ", ";
			ret += _to_string(value[i]);
		}
		return ret + " ]";

	} else if constexpr (is_map<T>::value) {
		auto it = value.begin();
		std::string ret = "[ ";
		while (it != value.end()) {
			if (it != value.begin()) ret += ", ";
			ret += _to_string(it->first) + " : " + _to_string(it->second);
			it++;
		}
		return ret + " ]";
	} else if constexpr (std::is_same<T, const char*>::value) {
		return value;
	}
	// don't return anything here as it may throw compiler error if any type were missed.
}

#endif // __CODE_FOLD1__

#ifndef  __CODE_FOLD2__
#if defined(DBG_IMPLEMENT)

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#else
#include <unistd.h>
#endif

int TesterGlobals::timer_line;
std::chrono::steady_clock::time_point TesterGlobals::timer_t0;
std::chrono::duration<double> TesterGlobals::timer_duration;

std::string TesterGlobals::_INPUT_BUFF = R"()";
std::string TesterGlobals::_OUTPUT_BUFF = R"()";
std::string TesterGlobals::_EXPECTED_OUTPUT = R"()";


std::string strip(const std::string& str) {
	size_t begin = 0, end = str.size();
	while (true) {
		if (begin >= str.size()) return "";
		if (str[begin] != ' ' && str[begin] != '\n') break;
		begin++;
	}

	while (true) {
		if (str[end - 1] != ' ' && str[end - 1] != '\n') break;
		end--;
	}
	return str.substr(begin, end - begin);
}


#ifdef _WIN32
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void set_cursor_pos(int column, int line) {
	COORD coord; coord.X = column; coord.Y = line;
	if (!SetConsoleCursorPosition(hConsole, coord)) { /*ERROR*/ }
}

void cprint(const char* p_msg, Color p_fg, Color p_bg) {
#define SET_CCOLOR(m_fg, m_bg) SetConsoleTextAttribute(hConsole, (int)m_bg << 4 | (int)m_fg)
	SET_CCOLOR(p_fg, p_bg);
	printf(p_msg);
	SET_CCOLOR(Color::L_WHITE, Color::BLACK);
}

void clear_console() {
	system("cls");
}

#else
void set_cursor_pos(int column, int line) {  // only works in ANSI compatible terminal.
	printf("\033[%d;%dH", column + 1, line + 1);
}

void cprint(const char* p_msg, Color p_fg, Color p_bg) { /* TODO: implement */ }

void clear_console() {
	system("clear");
}
#endif


#endif
#endif // __CODE_FOLD2__

#endif // DBG_H