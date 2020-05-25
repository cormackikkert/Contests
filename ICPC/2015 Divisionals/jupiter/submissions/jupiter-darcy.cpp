#include <bits/stdc++.h>
using namespace std;

int n, k, l, m;

int win(string s,string t){
	string moves = "PRSPRS";
	int wins[3] = {0};
	for(int i=0;i<k;i++){
		int me = moves.find(s[i]);
		int you = moves.find(t[i],me);
		wins[you-me]++;
		if(you != me && wins[you-me] == m)
			return (you-me == 2 ? -1 : 1);
	}
	return 0;
}

string morph(string s,int st){
	string moves = "RPSR";
	for(int i=0;i<l;i++)
		s[st+i] = moves[moves.find(s[st+i])+1];
	return s;
}

int phase3(string s,string t){
	int best = -1;
	for(int i=0;i<=k-l;i++)
		best = max(best,win(morph(s,i),t));
	return best;
}

int phase2(string s,string t){
	int best = 1;
	for(int i=0;i<=n-k;i++)
  	best = min(best,phase3(s,t.substr(i,k)));
  return best;
}

int phase1(string s,string t){
	int best = -1;
	for(int i=0;i<=n-k;i++)
  	best = max(best,phase2(s.substr(i,k),t));
  return best;
}

int main(){
  cin >> n >> k >> l >> m;

  string s,t;
  cin >> s >> t;

	int winner = phase1(s,t);

	vector<string> names = {"Bob","Draw","Alice"};
	cout << names[winner+1] << endl;  
  
  return 0;
}
