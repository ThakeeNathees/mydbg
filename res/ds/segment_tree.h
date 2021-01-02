#pragma once
#include "include.h"

struct SegmentTree_Sum {
	ivec tree;

	SegmentTree_Sum(const ivec& arr) {
		const int N = arr.size();
		tree = ivec(2 * N);
		for (int i = 0; i < N; i++) {
			tree[N + i] = arr[i];
		}
		for (int i = N - 1; i >= 1; i--) {
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}
	}

	void update(int index, int value) {
		int ind = tree.size() / 2 + index;
		tree[ind] = value;

		while (ind > 1) {

			// ind ^ 1 => (ind is odd) ? ind -1 : ind + 1;
			tree[ind / 2] = tree[ind] + tree[ind ^ 1];
			ind /= 2;
		}
	}

	int query(int l, int r) { // [l, r)
		const int N = tree.size() / 2;
		l += N, r += N;

		int ret = 0;
		while (l < r) {

			// if left odd
			if (l & 1) ret += tree[l++];

			// if right odd
			if (r & 1) ret += tree[--r];

			l /= 2;
			r /= 2;
		}
		return ret;
	}
};
