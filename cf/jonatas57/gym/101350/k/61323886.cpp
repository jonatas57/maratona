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

	while(tc--) {
		ll a, b, n;
		cin >>a >>b >>n;
		set<ll> s;
		for(ll i = 1; i*i <= n; i++) {
			if(a*i*i + b*i <= n) 
				s.insert(a*i*i + b*i);
		}

		int pts[10];
		int maiorGeral = 1;
		memset(pts, 0, sizeof pts);
		for(auto at:s) {
			int p[10];
			memset(p, 0, sizeof p);

			int att = at;
			int maior = 0;
			while(att > 0) {
				p[att%10]++;
				maior = max(maior, p[att%10]);
				att /= 10;
			}
			for(int i = 0; i < 10; i++) {
				if(p[i] == maior) {
					pts[i]++;
					maiorGeral = max(maiorGeral, pts[i]);
				}
			}
		}

		vector<int> ans;
		for(int i = 0; i < 10; i++) {
			if(pts[i] == maiorGeral) ans.pb(i);
		}
		if(ans.size() > 0) cout <<ans[0] <<endl;
		else cout <<-1 <<endl;
	}
	
	return 0;
}
