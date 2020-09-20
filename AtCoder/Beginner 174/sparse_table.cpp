vi logs;
void buildLogs(int n) {
	logs.resize(n+1);
	logs[1] = 0;
	for (int i = 2; i <= n; ++i) logs[i] = logs[i/2] + 1;
}

template<class T> struct SparseTable {
	T combine(T a, T b) { return min(a, b); } // must be idempotent 
	int n; vector<vector<T>> table;
	void init(vector<T> & arr) {
		n = arr.size();
		table.assign(logs[n]+1, vector<T> (n));
		for (int i = 0; i <= logs[n]; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0) table[i][j] = arr[j];
				else table[i][j] = combine(table[i-1][j], table[i-1][j+(1<<(i-1))]);
			}
		}
	}

	T query(int l, int r) {
		int power = logs[r-l+1];
		return combine(table[power][l], table[power][r-(1<<power)+1]);
	}
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, Q; cin >> N >> Q;
	buildLogs(N);
}