#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

const int N = 2e5 + 5;
vector<ii> vc;
ll acc[N];
ll acq[N];

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	ll h;
	cin >>n >>h;

	for(int i = 0; i < n; i++) {
		ll a, b;
		cin >>a >>b;
		vc.eb(a,b);
	}

	for(int i = 1; i < n; i++) {
		acq[i] = vc[i].fi - vc[i-1].se;
		acq[i] += acq[i-1];
	}
	acq[n] = INF;
	
	acc[0] = 0;
	for(int i = 1; i <= n; i++) {
		acc[i] = vc[i-1].se - vc[i-1].fi;
		acc[i] += acc[i-1];
	}
	
	
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int x = lower_bound(acq, acq+n, h+acq[i]) - begin(acq);
		ans = max(ans,h+(acc[x]-acc[i]));
	}

	cout <<ans <<endl;

	return 0;
}

