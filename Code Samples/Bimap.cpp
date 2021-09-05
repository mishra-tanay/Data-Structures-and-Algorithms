template <typename left_T, typename right_T>
class Bimap {
public:
	Bimap() {
	}
	void insert(left_T key, right_T value) {
		left_map[key] = value;
		right_map[value] = key;
	}
	void insert(right_T key, left_T value) {
		right_map[key] = value;
		left_map[value] = key;
	}
	bool isPresentInLeft(left_T key) {
		return left_map.find(key) != left_map.end();
	}
	bool isPresentInRight(right_T key) {
		return right_map.find(key) != right_map.end();
	}

	right_T valueFromLeft(left_T key) {
		return left_map[key];
	}

	left_T valueFromRight(right_T key) {
		return right_map[key];
	}
	void setValueByLeftKey(left_T key, right_T value) {
		eraseKey(key);
		insert(key, value);
	}
	void setValueByRightKey(right_T key, left_T value) {
		eraseKey(key);
		insert(key, value);
	}
	void eraseKey(left_T key) {
		auto left_it = left_map.find(key);
		if (left_it != left_map.end()) {
			auto val = left_map[key];
			auto right_it = right_map.find(val);
			if (right_it != right_map.end()) {
				right_map.erase(right_it);
			}
			left_map.erase(left_it);
		}
	}
	void eraseKey(right_T key) {
		auto right_it = right_map.find(key);
		if (right_it != right_map.end()) {
			auto val = right_map[key];
			auto left_it = left_map.find(val);
			if (left_it != left_map.end()) {
				left_map.erase(left_it);
			}
			right_map.erase(right_it);
		}
	}
	int count() {
		return left_map.size();
	}

private:
	map <left_T, right_T> left_map;
	map <right_T, left_T> right_map;
};