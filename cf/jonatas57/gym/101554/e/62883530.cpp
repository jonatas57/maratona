#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define cc(x) cout <<#x <<" = " <<x <<endl;
#define loop(i, r) for(int i = 0; i < r; i++)
#define each(x, xs) for(auto &x:xs)

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);

	string s, t;
	cin >>s >>t;

	int i, j;
	for(i = 0; i < min(s.size(), t.size()); i++) {
		if(s[i] != t[i]) break;
	}

	for(j = 0; j < min(s.size(), t.size()); j++) {
		if(s[s.size()-j-1] != t[t.size()-j-1]) break;
	}
	
	cout <<max(max(0,(int)(t.size()-s.size())),(int) ((t.size()-j)-i)) <<endl;
	
	return 0;
}

