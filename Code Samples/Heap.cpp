template <typename T>
class Heap {
public:
	Heap(vector<T> &arr, bool is_max_heap) {
		d_arr = arr;
		d_is_max_heap = is_max_heap;
		d_size = arr.size();
		for (int i = d_size / 2 - 1; i >= 0 ; i--) {
			heapify(i);
		}
	}
	void heapify(int index) {
		auto curr_val = d_arr[index];
		if (d_is_max_heap) {
			int max_val_index = index;
			if (2 * index < d_size && d_arr[2 * index] >= curr_val) {
				max_val_index = 2 * index;
				curr_val = d_arr[2 * index];
			}
			if (((2 * index) + 1) < d_size && d_arr[(2 * index) + 1] >= curr_val) {
				max_val_index = 2 * index + 1;
				curr_val = d_arr[2 * index + 1];
			}
			if (max_val_index != index) {
				swap(d_arr[max_val_index], d_arr[index]);
				heapify((max_val_index - 1) / 2);
			}
		} else {
			int min_value_index = index;
			if (2 * index < d_size && d_arr[2 * index] < curr_val) {
				min_value_index = 2 * index;
				curr_val = d_arr[2 * index];
			}
			if (2 * index + 1 < d_size && d_arr[2 * index + 1] < curr_val) {
				min_value_index = 2 * index + 1;
				curr_val = d_arr[2 * index + 1];
			}
			if (min_value_index != index) {
				swap(d_arr[min_value_index], d_arr[index]);
				heapify(min_value_index);
			}
		}
	}
	void insertUtil(int index) {
		int parent = (index / 2);
		if (d_is_max_heap) {
			if (d_arr[parent] < d_arr[index]) {
				swap(d_arr[parent], d_arr[index]);
				insertUtil(parent);
			}
		} else {
			if (d_arr[parent] > d_arr[index]) {
				swap(d_arr[parent], d_arr[index]);
				insertUtil(parent);
			}
		}
	}
	void insert(T val) {
		if (d_arr.size() == d_size) {
			cout << "a ";
			d_arr.push_back(val);
		} else {
			d_arr[d_size - 1] = val;
		}
		d_size++;
		insertUtil(d_size - 1);
	}
	void eraseRoot() {
		swap(d_arr[0], d_arr[d_size - 1]);
		d_size--;
		heapify(0);
		d_arr.pop_back();
	}
	T getTop() {
		return d_size > 0 ? d_arr[0] : -1;
	}
	bool isEmpty() {
		return d_size == 0;
	}
	int getSize() {return d_size;}

private:
	int d_size;
	vector<T> d_arr;
	bool d_is_max_heap;
};