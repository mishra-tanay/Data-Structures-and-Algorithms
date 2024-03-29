class Graph {
public:
	Graph(const vector <vector<int>> &adj, int n, int m) {
		d_adj = adj;
		d_count = n;
		d_edges = m;
		calculateInOutDegree();
		calculateInOutTime();
	}
	void calculateInOutDegree() {
		d_in.resize(d_count + 1, 0);
		d_out.resize(d_count + 1, 0);
		for (int i = 1; i <= d_count; i++) {
			for (auto it : d_adj[i]) {
				d_in[it]++;
			}
			d_out[i] = d_adj[i].size();
		}
	}
	void calculateInOutTime() {
		d_arrival.resize(d_count + 1);
		d_departure.resize(d_count + 1);
		vector < bool > vis(d_count + 1, false);
		for (int i = 1; i <= d_count; i++) {
			if (!vis[i]) {
				computeDepartureArrival(i, vis, -1);
			}
		}
	}
	vector <int> getTopologicalSort()  {
		if (!d_topological.empty()) {
			return d_topological;
		}
		vector <int> result;
		vector < int> in = d_in;
		queue < int> q;
		for (int i = 1; i <= d_count; i++) {
			if (in[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int u = q.front();
			result.push_back(u);
			q.pop();
			for (auto v : d_adj[u]) {
				in[v]--;
				if (in[v] == 0) {
					q.push(v);
				}
			}
		}
		d_topological = result;
		return d_topological;
	}
	void computeDepartureArrival(int src, vector <bool>& vis, int par = -1)  {
		vis[src] = true;
		d_arrival[src] = ++d_time;
		for (auto v : d_adj[src]) {
			if (!vis[v]) {
				computeDepartureArrival(v, vis, src);
			}
		}
		d_departure[src] = ++d_time;
	}
	bool hasCycle() const {
		for (int u = 1; u <= d_count; u++) {
			// check if `(u, v)` forms a back-edge.
			for (int v : d_adj[u]) {
				if (d_departure[u] <= d_departure[v]) {
					return true;
				}
			}
		}
		return false;
	}
	void debugGraph() {
		cout << "---GRAPH---\n";
		for (int i = 1; i <= d_count; i++) {
			cout << "Vertex " << i << ": [ ";
			for (auto it : d_adj[i]) {
				cout << it << ' ';
			}
			cout << "]" << '\n';
		}
		cout << "***GRAPH***";
	}
public:
	vector<vector<int>> d_adj;
	int d_count;
	int d_edges;
	vector <int> d_arrival;
	vector <int> d_departure;
	vector <int> d_topological;
	vector <int> d_in;
	vector <int> d_out;
	int d_time = -1;
};