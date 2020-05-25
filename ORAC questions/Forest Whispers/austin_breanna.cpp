#include <bits/stdc++.h>
using namespace std;

/* 
To any poor soul reading my code, I'll save you some trouble and just 
explain what I'm doing. To encode the permutation I convert each edge to a 
transposition and apply it to the original cycle
E.g. Assume I had this tree
1 - 2
  - 3
  - 4 - 5
      - 6
We now need to evaluate (12)(13)(14)(45)(46) (lexicographic to make process reversable)
(12)(13)(14)(15)(45)(46)
(123)(14)(15)(45)(46)
(1234)(45)(46)
(12354)(46)
(123564)
To reverse the process we "peel" off leaves, were a leaf is highest node still in our cycle
(why we inserted lexicographically).
This gives a mapping between cycles and trees. Then we also create a mapping between permutations and cycles
Then after coding the permutation stuff I realised I had to answer queries in nlogn and was 
outta patience so I just googled it.
*/

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int, int>;

template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

template <typename A>
string to_string(pair<int, int> v) {
    return "{" + to_string(v.first) + ", " + to_string(v.second) + "}";
}

vi cycles_to_perm(vector<vi> cycles, int l) {
    vi perm (l);
    F0R(i, l) perm[i] = i;
    for (vi cycle : cycles) {
        F0R(i, cycle.size()) {
            perm[cycle[i]] = cycle[(i+1) % cycle.size()];
        }
    }
    return perm;
}

vi combine(vi A, vi B) {
    if (A.empty()) return B;
    int S = A[0];
    vi newPerm = {S};
    while (true) {
        F0R(i, A.size()) {
            if (A[i] == S) {S = A[(i+1) % A.size()]; break;}
        }
        F0R(i, B.size()) {
            if (B[i] == S) {S = B[(i+1) % B.size()]; break;}
        }
        if (S == newPerm[0]) break;
        newPerm.push_back(S);
    }
    return newPerm;
}

pair<vi, vi> reduce(vi seq) {
    if (seq.size() == 2) return {{}, seq};
    int ind = distance(seq.begin(), max_element(seq.begin(), seq.end()));
    vi t = {seq[(ind + 1) % seq.size()], seq[ind]};
    int S = seq[0];
    vi newPerm;
    F0R(i, ind) newPerm.push_back(seq[i]);
    if (t[0] != newPerm[0]) newPerm.push_back(t[0]);
    FOR(i, ind+2, seq.size()) newPerm.push_back(seq[i]);
    return {newPerm, t};
}

vi austin(int T, int N, int M, vi A, vi B) {
    vector<pii> edges;
    F0R(i, M) edges.push_back({min(A[i], B[i]), max(A[i], B[i])});
    sort(edges.begin(), edges.end());
    vi connections (N, -1);
    vector<vi> forests;
    int curComponent = 0;
    F0R(i, M) {
        vi t = {edges[i].first, edges[i].second};
        if (connections[t[0]] == -1 && connections[t[1]] == -1) {
            forests.push_back(t); 
            connections[t[0]] = curComponent;
            connections[t[1]] = curComponent;
            ++curComponent;
        } else {
            int ind = (connections[t[0]] != -1) ? connections[t[0]] : connections[t[1]];
            forests[ind] = combine(forests[ind], t);
            connections[t[0]] = ind;
            connections[t[1]] = ind;
        }
    }
    return cycles_to_perm(forests, N);
}

vector<vi> graph;
vi travIndex;

void dfs(vi &traversal, int node, int parent, int depth) {
    travIndex[node] = traversal.size();
    traversal.push_back(depth);
    for (int neighbour : graph[node]) {
        if (neighbour == parent) continue;
        dfs(traversal, neighbour, node, depth + 1);
        traversal.push_back(depth);
    }
}

vector<vi> getCycles(vi perm) {
    vb visited (perm.size());
    vector<vi> cycles;
    F0R(i, perm.size()) {
        if (visited[i]) continue;
        int cur = i;
        vi curCycle;
        do {
            curCycle.push_back(cur);
            visited[cur] = true;
            cur = perm[cur];
        } while (cur != i);
        cycles.push_back(curCycle);
    }
    return cycles;
}

void modify(vi &arr, int i, int v) {
    i += arr.size()/2;
    arr[i] = v;
    for (i /= 2; i >= 1; i /= 2) arr[i] = min(arr[2*i], arr[2*i+1]);
}

int query(vi &arr, int a, int b) {
    a += arr.size() / 2; b += arr.size() / 2;
    int best = arr[a];
    while (a <= b) {
        if (a % 2 == 1) best = min(best, arr[a++]);
        if (b % 2 == 0) best = min(best, arr[b--]);
        a /= 2; b /= 2;
    }
    return best;
}

vector<int> breanna(int T, int N, vector<int> P, int Q, vector<int> qA, vector<int> qB) {
    vector<int> answers;
    vector<vi> cycles = getCycles(P);
    graph.resize(N);
    travIndex.resize(N);
    vi component (N);

    vector<vi> segmentTrees;

    F0R(i, cycles.size()) {
        vi cycle = cycles[i];
        int root = cycle[0];
        for (int x : cycle) component[x] = i;
        while (cycle.size() > 1) {
            auto x = reduce(cycle);
            graph[x.second[0]].push_back(x.second[1]);
            graph[x.second[1]].push_back(x.second[0]);
            cycle = x.first;
        }
        vi traversal;
        dfs(traversal, root, -1, 0);
        vi segmentTree(2 * traversal.size());
        F0R(i, traversal.size()) modify(segmentTree, i, traversal[i]);
        segmentTrees.push_back(segmentTree);
    } 

    F0R(j, Q) {
        int a = qA[j]; int b = qB[j];
        if (component[a] != component[b]) {answers.push_back(-1); continue;}
        int i = component[a];
        int d1 = query(segmentTrees[i], travIndex[a], travIndex[a]);
        int d2 = query(segmentTrees[i], travIndex[b], travIndex[b]);
        int d3 = query(segmentTrees[i], min(travIndex[a], travIndex[b]), max(travIndex[a], travIndex[b]));
        answers.push_back(d1 + d2 - 2 * d3);
    }
    return answers;
}

int main() {
    
    vi cur;
    vector<pii> edges = {{4, 7}, {4, 6}, {5, 7}, {2, 7}, {1, 2}, {2, 3}};
    sort(edges.begin(), edges.end());
    for (auto x : edges) {
        cur = combine(cur, {x.first, x.second});
        cout << to_string(cur) << endl;
    }
    cout << to_string(cur) << endl;
    
}
