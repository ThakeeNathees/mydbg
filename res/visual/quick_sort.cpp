
VecPrinter* vp;

int _partition(ivec & arr, int l, int r) {
	int pivot = arr[r - 1];
	int pivot_ind = l;
	vp->add_color(pivot_ind, Color::D_YELLOW);

	for (int i = l; i < r - 1; i++) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[pivot_ind++]);
			vp->remove_color(pivot_ind-1);
			vp->add_color(pivot_ind, Color::D_YELLOW);
		}

		dbprint((*vp)(l, r, i));
	}
	swap(arr[pivot_ind], arr[r - 1]);
	dbprint(vp->add_color(pivot_ind, Color::D_GREEN)(pivot_ind));
	
	if (r == l + 2) vp->add_color(l, Color::D_GREEN), vp->add_color(l + 1, Color::D_GREEN);

	return pivot_ind;
}

void quick_sort(ivec & arr, int l = -1, int r = -1) {
	if (l == -1 && r == -1) l = 0, r = arr.size();
	if (l > r - 2) {
		vp->add_color(l, Color::D_GREEN);
		return;
	}

	dbprint((*vp)(l, r));

	int pivot_index = _partition(arr, l, r);
	quick_sort(arr, l, pivot_index);
	quick_sort(arr, pivot_index + 1, r);
}

// ivec arr; FOR(i, 20) arr.push_back(rand() % 100);
// vp = new VecPrinter(&arr);
// quick_sort(arr);
// dbprint(vp);
