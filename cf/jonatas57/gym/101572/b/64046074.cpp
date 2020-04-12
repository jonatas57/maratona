#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int,int,string> ti;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vti bag;

int32_t main() {
	int n,a,b,d,e;
	char c1,c2;
	string s;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> s >> a >> c1 >> b >> d >> c2 >> e;
		bag.eb(d*100+e, a*100+b,s);
	}

	sort(bag.begin(), bag.end());

	vector<string> ans,test;
	int ok = INF, nok = 0;

	for(int i = 0; i < n; i++) {
		test.clear();
		tie(a,b,s) = bag[i];
		nok = b;
		test.pb(s);
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			tie(a,b,s) = bag[j];
			nok += a;
			test.pb(s);
			if(test.size() == 4) {
				if(ok > nok) ok = nok, ans = test;
				break;
			}
		}
	}
	
	printf("%d.%02d\n", ok/100, ok%100);
	for(auto x : ans) cout << x << endl;

	return 0;
}

