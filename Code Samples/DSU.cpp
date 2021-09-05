class DSU {
public:
	DSU(int n) {
		d_count = n;
		d_dsu.resize(n + 1);
		d_size.resize(n + 1, 0);
		for (int i = 0; i <= d_count; i++) {
			d_dsu[i] = i;
			d_size[i] = 1;
		}
	}
	int getRoot(int u) {
		while (d_dsu[u] != u) {
			d_dsu[u] = d_dsu[d_dsu[u]];
			u = d_dsu[u];
		}
		return u;
	}
	void combine(int u, int v) {
		int root_1 = getRoot(u);
		int root_2 = getRoot(v);
		if (root_1 == root_2) {
			return ;
		}
		if (d_size[root_1] > d_size[root_2]) {
			swap(root_1, root_2);
		}
		assert("combining on smaller component" && d_size[root_1] <= d_size[root_2]);
		d_size[root_1] += d_size[root_2];
		d_size[root_2] = 0;
		d_dsu[root_2] = d_dsu[root_1];
	}
	int getComponentSize(int u) {
		int root = getRoot(u);
		return d_size[root];
	}
	void debugComponent() {
		cout << "**DEBUG**" << '\n';
		for (int i = 1; i <= d_count; i++) {
			cout << "[" << i << " has root " << getRoot(i) << " and size = " << getComponentSize(i) << " ]\n";
		}
		cout << "--DEBUG--" << '\n';
	}
private:
	int d_count;
	vector <int> d_dsu;
	vector <int> d_size;
};
