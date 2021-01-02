#pragma once
#include "include.h"


inline bool ends_with(const std::string& str, const std::string& what) {
	return (str.find(what, str.size() - what.size()));
}

inline bool begins_with(const std::string& str, const std::string& what) {
	if (what.size() > str.size()) return false;
	for (int i = 0; i < (int)what.size(); i++) {
		if (str[i] != what[i]) return false;
	}
	return true;
}
