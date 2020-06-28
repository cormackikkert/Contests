struct DSU {
    vi p; void init(int n) {p = vi (n, -1);}
    int findSet(int x) { return p[x] < 0 ? x : findSet(p[x]);}
    bool sameSet(int a, int b) { return findSet(a) == findSet(b); }
	int size(int x) { return -p[findSet(x)]; }
	bool joinSet(int x, int y) { // union-by-rank
		x = findSet(x), y = findSet(y); if (x == y) return 0;
		if (p[x] > p[y]) swap(x,y);
		p[x] += p[y]; p[y] = x; return 1;
	}
};