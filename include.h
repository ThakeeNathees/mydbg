#pragma once

// HEADERS /////////////////////////////////////////////////////
// needed for debugging.
#include <iostream>
#include <functional>
#include <sstream>
#include <string>
#include <vector>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif


// data_structure : choose wisely.
#if 0
#include <algorithm>
#include <chrono>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#endif

// MACROS //////////////////////////////////////////////////

#define MAIN _main
#define TEST main

#define STR(x) #x
#define TOSTRING(x) STR(x)

#define CHECK(m_exp)                              \
do {                                              \
    printf("LINE [" TOSTRING(__LINE__) "]: ");    \
    if (!(m_exp)) {                               \
        cprint("FAILURE\n", Color::L_RED);        \
    } else {                                      \
        cprint("SUCCESS\n", Color::L_GREEN);      \
    }                                             \
} while (false)

#define CHECK_EQ(m_result, m_expected)                    \
do {                                                      \
    printf("LINE [" TOSTRING(__LINE__) "]: ");            \
    if (m_result != m_expected) {                         \
        cprint("FAILURE\n", Color::L_RED);                \
        /* TODO: implement const char* to_string() method for vector, etc etc*/ \
        /*printf("\tEXPECTED : %s\n", m_expected.c_str());*/ \
        /*printf("\tRESULT   : %s\n", m_result.c_str());  */ \
    } else {                                              \
        cprint("SUCCESS\n", Color::L_GREEN);              \
    }                                                     \
}  while (false)

#ifdef CPP_IMPL
// Yes it's a global variable and I know.
std::string _INPUT_BUFF = R"()";
std::string _OUTPUT_BUFF = R"()";
std::string _EXPECTED_OUTPUT = R"()";

#define REDIRECT()                                   \
class Redirect {									 \
	std::istringstream isstream;					 \
	std::ostringstream osstream;					 \
	std::streambuf* istream_buf;					 \
	std::streambuf* ostream_buf;					 \
public:												 \
	Redirect() {									 \
		istream_buf = std::cin.rdbuf();				 \
		isstream = std::istringstream(_INPUT_BUFF);	 \
		std::cin.rdbuf(isstream.rdbuf());			 \
		ostream_buf = std::cout.rdbuf();			 \
		osstream = std::ostringstream(_OUTPUT_BUFF); \
		std::cout.rdbuf(osstream.rdbuf());			 \
	}												 \
	~Redirect() {									 \
		_OUTPUT_BUFF = strip(osstream.str());	     \
		std::cin.rdbuf(istream_buf);				 \
		std::cout.rdbuf(ostream_buf);				 \
	}												 \
};													 \
Redirect redirect

#define RUN_MAIN(m_input_buff)                       \
	_INPUT_BUFF = strip(m_input_buff);               \
	_OUTPUT_BUFF = "";                               \
	MAIN()

#define TEST_MAIN(m_input_buff, m_output_buff)                   \
	_EXPECTED_OUTPUT = strip(m_output_buff);                     \
	RUN_MAIN(m_input_buff);                                      \
	printf("LINE [" TOSTRING(__LINE__) "]: ");                   \
	if (_OUTPUT_BUFF != _EXPECTED_OUTPUT ) {                     \
	    cprint("FAILURE\n", Color::L_RED);                       \
	    cprint("\tEXPECTED : ", Color::L_YELLOW); printf("%s\n", _EXPECTED_OUTPUT .c_str());  \
	    cprint("\tRESULT   : ", Color::L_YELLOW); printf("%s\n", _OUTPUT_BUFF.c_str());       \
	} else {                                                     \
	    cprint("SUCCESS\n", Color::L_GREEN);                     \
	}

#endif // CPP_IMPL

// DECLARATIONS //////////////////////////////////////////////////

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

std::string strip(const std::string& str);

template <class Type, class... Types>
void print(const Type& arg, const Types&... args) {
    std::cout << arg;
    ((std::cout << " " << args), ..., (std::cout << std::endl));
}

//#define print(x) std::cout << (x) << std::endl
template <typename T>
void print_vector(const std::vector<T>& x) {
    printf("[ ");
    for (int i = 0; i < x.size(); i++) {
        if (i != 0) printf(", ");
        std::cout << (x[i]);
    }
    printf(" ]\n");
}

// CPP_IMPL /////////////////////////////////////////////////////////

#ifdef CPP_IMPL
std::string strip(const std::string& str) {
    size_t begin = 0, end = str.size();

    while (true) {
        if (begin >= str.size()) return "";
        if (str[begin] != ' ' && str[begin] != '\n') {
            break;
        }
        begin++;
    }

    while (true) {
        if (str[end - 1] != ' ' && str[end - 1] != '\n') {
            break;
        }
        end--;
    }
    return str.substr(begin, end - begin);
}
#endif // CPP_IMPL

#ifdef _WIN32

void set_cursor_pos(int column, int line);
void cprint(const char* p_msg, Color p_fg, Color p_bg);

#ifdef CPP_IMPL
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void set_cursor_pos(int column, int line)
{
    // Create a COORD structure and fill in its members.
    // This specifies the new position of the cursor that we will set.
    COORD coord;
    coord.X = column;
    coord.Y = line;

    // Obtain a handle to the console screen buffer.
    // (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
    // in conjunction with the GetStdHandle() to retrieve the handle.)
    // Note that because it is a standard handle, we don't need to close it.
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Finally, call the SetConsoleCursorPosition function.
    if (!SetConsoleCursorPosition(hConsole, coord)) {
        // Uh-oh! The function call failed, so you need to handle the error.
        // You can call GetLastError() to get a more specific error code.
        // ...
    }
}

#define SET_CCOLOR(m_fg, m_bg) SetConsoleTextAttribute(hConsole, (int)m_bg << 4 | (int)m_fg)
void cprint(const char* p_msg, Color p_fg, Color p_bg = Color::BLACK)
{
    SET_CCOLOR(p_fg, p_bg);
    printf(p_msg);
    SET_CCOLOR(Color::L_WHITE, Color::BLACK);
}

#endif // CPP_IMPL

#else
void set_cursor_pos(int column, int line) {  // only works in ANSI compatible terminal.
    printf("\033[%d;%dH", column + 1, line + 1);
}
#endif


