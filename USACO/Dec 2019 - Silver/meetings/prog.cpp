#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;

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

struct event {
    ll etime;
    ll etype;
    ll ci;
    event(ll a, ll b, ll c) : etime (a), etype(b), ci(c) {}

    bool operator<(const struct event& other) const {
        return (etime > other.etime) || (etime == other.etime && etype > other.etype) || (etime == other.etime && etype == other.etype && ci > other.ci);
    } 
};
using vc = vector<char>;
using vi = vector<int>;

void swap(ll &a, ll &b) {
    ll t = a;
    a = b;
    b = t;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);

    ll N, L;
    cin >> N >> L;
    L *= 2;

    vi cowTime (N+2, 0);
    vi cowPos (N+2);
    vi cowDir (N+2, 0);
    vi cowWeight (N+2);

    ll allCowWeight = 0;
    //cout << 1 << endl;

    vector<tuple<int, int, int>> cancer;
    F0R(i, N) {
        ll w, x, d; cin >> w >> x >> d;
        cancer.push_back(make_tuple(x, w, d));
    }
    sort(cancer.begin(), cancer.end());

    F0R(i, N) {
        ll w = get<0>(cancer[i]);
        ll x = get<1>(cancer[i]);
        ll d = get<2>(cancer[i]);
        cowPos[i+1] = 2*x;
        cowDir[i+1] = d;
        cowWeight[i+1] = w;
        allCowWeight += w;
    }
    //cout << 2 << endl;
    priority_queue<event> q;
    FOR(i, 1, N+1) {
        if (cowDir[i-1] == 0 && cowDir[i] == -1) {
            q.push(event(cowPos[i], 1, i));
        } if (cowDir[i+1] == 0 && cowDir[i] == 1) {
            q.push(event((L - cowPos[i]), 1, i));
        } if (cowDir[i] == 1 && cowDir[i+1] == -1) {
            q.push(event((cowPos[i+1] - cowPos[i]) / 2, 0, i));
        }
    }
    //cout << 3 << endl;
    ll finCowWeight = 0;
    ll total = 0;
    while (q.size() > 0) {
        event e = q.top(); q.pop();
        ll etime = e.etime;
        ll etype = e.etype;
        ll ci = e.ci;
        //cout << "EVENT: " << etime << " " << etype << " " << ci <<  " " << to_string(cowDir) << endl;
        if (etype == 1) {
            finCowWeight += cowWeight[ci];
            if (cowDir[ci] == 1 && cowDir[ci - 1] == 1) {
                q.push(event(cowTime[ci - 1] + (L - cowPos[ci - 1]), 1, ci - 1));
            } else if (cowDir[ci] == -1 && cowDir[ci + 1] == -1) {
                q.push(event(cowTime[ci + 1] + cowPos[ci + 1], 1, ci + 1));
            }
            if (finCowWeight >= allCowWeight / 2) break;
            cowDir[ci] = 0;
        } else {
            total++;
            // cowPos[ci] += etime - cowTime[ci];
            // cowPos[ci+1] -= etime - cowTime[ci+1];
            cowPos[ci] = (cowPos[ci] + cowPos[ci+1]) / 2;
            cowPos[ci + 1] = cowPos[ci];
            
            //cout << "POS: " << cowPos[ci] << endl;
            cowTime[ci] = etime;
            cowTime[ci+1] = etime;

            swap(cowWeight[ci], cowWeight[ci+1]);
            cowDir[ci] = -1; cowDir[ci+1] = 1;

            if (cowDir[ci - 1] == 0) {
                //cout << "1-";
                q.push(event(cowTime[ci] + cowPos[ci], 1, ci));
                //cout << cowTime[ci] + cowPos[ci];
            } else if (cowDir[ci - 1] == 1) {
                //cout << '2';
                cowPos[ci - 1] += etime - cowTime[ci - 1];
                cowTime[ci - 1] = etime;
                q.push(event(etime + (cowPos[ci] - cowPos[ci - 1]) / 2, 0, ci - 1));
            }

            if (cowDir[ci + 2] == 0) {
                //cout << "3-";
                q.push(event(cowTime[ci+1] + (L - cowPos[ci+1]), 1, ci+1));
                //cout << cowTime[ci+1] + (L - cowPos[ci+1]);
            } else if (cowDir[ci + 2] == -1) {
                //cout << '4';
                cowPos[ci+2] -= etime - cowTime[ci+2];
                cowTime[ci+2] = etime;
                q.push(event(etime + (cowPos[ci+2] - cowPos[ci+1]) / 2, 0, ci+1));
            }
            //cout << endl;
        }
    }
    cout << total << endl;
}