vi tree;

void modify(int i, int v) {
    i += tree.size()/2;
    tree[i] = v;
    for (i /= 2; i >= 1; i /= 2) tree[i] = tree[2*i] + tree[2*i+1];
}

int query(int a, int b) {
    a += tree.size() / 2; b += tree.size() / 2;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b++];
        a /= 2; b /= 2;
    }
    return s;
}