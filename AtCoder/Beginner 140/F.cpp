#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename A>
string to_string(multiset<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

int main() {
    int n; 
    cin >> n;
    multiset<int> slimes;

    for (int i = 0; i < pow(2, n); ++i) {
        int slime;
        cin >> slime;
        slimes.insert(slime);
    }
    cout << endl;
    multiset<int> created;

    ll firstSlime = *(slimes.rbegin());
    created.insert(firstSlime);
    slimes.erase(firstSlime);
    for (int i = 0; i < n; ++i) {
        multiset<int> buffer;
        for (multiset<int>::reverse_iterator it = created.rbegin(); it != created.rend(); ++it)  { 
            ll slime = *it;
            
            if (slimes.lower_bound(slime) == slimes.begin()) {
                cout << "No" << endl;
                return 0;
            }

            ll toCreate = *(--slimes.lower_bound(slime));
            buffer.insert(toCreate);
            slimes.erase(slimes.lower_bound(toCreate));
        }
        for (int s : buffer) created.insert(s);
    }

    cout << "Yes" << endl;
}