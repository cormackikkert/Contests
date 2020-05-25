#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<string,int> M;
  for(int i=0; i<n; i++) {
    string element;
    int whole, dec;
    char point;
    cin >> element >> whole >> point >> dec;
    M[element] = whole * 100 + dec;
  }

  cin >> ws; // Go to the next character...

  int ans = 0;
  while(isupper(cin.peek())) {
    string compound;
    char c;
    cin >> c;
    compound = c;
    if(islower(cin.peek())) {
      cin >> c;
      compound += c;
    }

    int mass = M[compound];
    if(isdigit(cin.peek())) {
      int amt;
      cin >> amt;
      mass *= amt;
    }

    ans += mass;
  }

  cout << ans/100 << "." << setw(2) << setfill('0') << ans%100 << endl;
}
