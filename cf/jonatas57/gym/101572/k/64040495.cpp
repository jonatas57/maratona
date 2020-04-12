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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 5;
ll v[T];
ll b,n,e;
ll bb,nn,ee;
int x;

bool check(ll ok) {

	ll w,h,z;
	w = b, h = n, z = e;
	vector<ll> pqp;

	for(int i = 0; i < x; i++) {
		pqp.clear();
		pqp.pb(w and h? v[i]*(bb+nn) : 0);
		pqp.pb(w and z? v[i]*(bb+ee) : 0);
		pqp.pb(h and z? v[i]*(nn+ee) : 0);
		pqp.pb(w > 1? v[i]*(bb+bb) : 0);
		pqp.pb(h > 1? v[i]*(nn+nn) : 0);
		pqp.pb(z > 1? v[i]*(ee+ee) : 0);
		
		ll um = pqp[0];
		ll dois = pqp[1];
		ll tres = pqp[2];
		ll qu = pqp[3];
		ll qi = pqp[4];
		ll sex = pqp[5];

		sort(pqp.begin(), pqp.end());
		int j = lower_bound(pqp.begin(),pqp.end(),ok) - pqp.begin();

		if(j == 6) return 0; 

		if(pqp[j] == um) w--, h--;
		else if(pqp[j] == dois) w--, z--;
		else if(pqp[j] == tres) h--, z--;
		else if(pqp[j] == qu) w -=2;
		else if(pqp[j] == qi) h -=2;
		else z -=2;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> b >> n >> e;
	cin >> bb >> nn >> ee;

	x = b+n+e;
	x /= 2;

	for(int i = 0; i < x; i++) cin >> v[i];

	ll l = 0;
	ll r = 1e18;
	ll ans = 0;

	while(l <= r) {
		ll mid = (l+r) >> 1;
		if(check(mid)) ans = mid, l = mid+1;
		else r = mid-1;
	}

	cout << ans << endl;

	return 0;
}

