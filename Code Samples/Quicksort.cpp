int getPartition(vector<int>& arr, int low, int high) {
	int i = (low - 1);
	int pivot = arr[high];
	for (int j = low ; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[i], arr[high]);
	return i;
}

void quickSort(vector<int> &arr, int start, int end) {
	if (start >= end) {
		return ;
	}
	auto mid = getPartition(arr, start, end);
	quickSort(arr, start, mid - 1);
	quickSort(arr, mid + 1, end);
}