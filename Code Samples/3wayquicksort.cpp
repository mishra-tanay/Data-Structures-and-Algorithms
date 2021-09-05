void getPartition(vector<int>& arr, int l, int h, int &left, int &right) {
	int low = l;
	int mid = l;
	int high = h;
	int pivot = arr[high];
	left = -1;
	right = -1;
	while (mid <= high) {
		if (arr[mid] < pivot) {
			swap(arr[mid], arr[low]);
			low++;
			mid++;
		} else if (arr[mid] == pivot) {
			mid++;
		} else {
			swap(arr[mid], arr[high]);
			high--;
		}
	}
	for (int k = l; k <= h; k++) {
		if (arr[k] == pivot) {
			right = k;
			if (left == -1) {
				left = k;
			}
		}
	}
	left--;
	right++;
}

void quickSort(vector<int> &arr, int start, int end) {
	if (start >= end) {
		return ;
	}
	int i, j;
	// assert(start >= 0 && start < arr.size());
	// assert(end >= 0 && end < arr.size());
	getPartition(arr, start, end, i, j);
	i = max(i, 0);
	j = min(j, (int)arr.size() - 1);
	if (j != end)
		quickSort(arr, start, j);
	if (i != start)
		quickSort(arr, i, end);
}