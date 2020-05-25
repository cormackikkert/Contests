#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<ll>;

void solve() {
    ll N, T, A, B;
    cin >> N >> T >> A >> B;
    vector<pair<ll, bool>> probs (N);
    vector<bool> types (N);

    ll alleasy = 0;
    ll allhard = 0;

    ll all = 0;

    F0R(i, N) {ll ans; cin >> ans; types[i] = (ans == 1);}
    F0R(i, N) {
        ll req; cin >> req;
    
        probs[i] = {req, types[i]};
        if (types[i]) {++allhard; all += B;}
        else {++alleasy; all += A;}
    }

    sort(probs.begin(), probs.end());

    ll best = (all <= T) ? N : 0;
    ll reqeasy = 0;
    ll reqhard = 0;
    F0R(i, N) {
        if (i == 0 || probs[i-1].first < probs[i].first) {
            ll time = probs[i].first;

            ll t1 = probs[i].first - 1;
            t1 -= B * reqhard; t1 -= A * reqeasy;
            if (t1 >= 0) {
                ll extra_easy = min(t1 / A, alleasy - reqeasy);
                t1 -= A * extra_easy;
                ll extra_hard = min(t1 / B, allhard - reqhard);
                best = max(best, extra_easy + extra_hard + reqeasy + reqhard);
            }
        }
        
        if (probs[i].second) ++reqhard;
        else ++reqeasy;
        
        if (i == N-1 || probs[i+1].first > probs[i].first) {
            ll t2 = probs[i].first;
            t2 -= B * reqhard; t2 -= A * reqeasy;
            if (t2 >= 0) {
                ll extra_easy = min(t2 / A, alleasy - reqeasy);
                t2 -= A * extra_easy;
                ll extra_hard = min(t2 / B, allhard - reqhard);
                best = max(best, extra_easy + extra_hard + reqeasy + reqhard);
            }
        }
        
    }
    cout << best << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll M; cin >> M;
    F0R(i, M) solve();
}