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
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 5;
ll v[T];
int n,k;

 
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	ll tot = 0;
	ll mini = INF;

	for(int i = 0; i < n; i++) {
		cin >> v[i];
		mini = min(mini,v[i]);
		if(i < k-1) tot += v[i];
	}

	ll ans = 0;
	
	for(int i = k-1; i < n; i++) {	
		tot += v[i];
		if(i-k >= 0) tot -= v[i-k];
		int at = i;
		while (at >= 0 and tot >= 0) {
			ll x = max(mini, v[at] - (tot+1)); 
			ans += (v[at] - x);
			tot += (x - v[at]);
			v[at] = x;
			at--;
		}
	}
	
	cout << ans << endl;
	for(int i = 0; i < n; i++) cout << v[i] << " ";
	cout << endl;
	
	return 0;
}

