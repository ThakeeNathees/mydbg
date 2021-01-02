#pragma once
#include "include.h"

// map num to [0...limit) // commented : stack overflow implementation, other one is mine.
// inline ll cycle_range(ll num, ll limit) { return (((num % limit) + limit) % limit); }
inline ll cycle_range(ll num, ll limit) {
	return (num >= 0) ? num % limit : (limit - ((num * -1) % limit)) % limit;
}

struct SwitchIndex {
	int _ind = 0;
	inline int ind() const { return _ind; }
	inline int incr() { int ret = _ind; _ind = (_ind + 1) % 2; return ret; }
	inline int prev() const { return (_ind + 1) % 2; }
};

struct CycleIndex {
	size_t _size; ll _ind = 0;
	CycleIndex(int size) : _size(size) {}
	inline int ind() const { return _ind; }
	inline int incr() { int ret = _ind; _ind = (_ind + 1) % _size; return ret; }
	inline int prev(int x = 1) { return next(-x); }
	inline int next(int x = 1) {
		if (x == 0) return _ind;
		else if (x < 0) { int k = ((-x) / _size) + 1; return (k * _size + x) % _size; } else return (_ind + x) % _size;
	}
};
