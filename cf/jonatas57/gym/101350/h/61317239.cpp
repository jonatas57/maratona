#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout <<#x <<" = " <<x <<endl;
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	string v = {"AHIMOTUVWXY"};
	set<char> m; 
	for(auto at:v) m.insert(at);

	while(tc--) {
		string s;
		cin >>s;
		bool mirror = true;

		for(int i = 0; i < s.size(); i++) 
			if(!m.count(s[i])) mirror = false;
		for(int i = 0; i < s.size()/2; i++) 
			if(s[i] != s[s.size()-i-1]) mirror = false;

		cout <<(mirror?"yes":"no") <<endl;
	}
	
	return 0;
}

