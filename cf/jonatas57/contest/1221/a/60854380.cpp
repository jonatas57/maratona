#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>> q;
		ll x;
		loop(n) {
			cin >> x;
			if (x <= 2048) q.push(x);
		}
		bool p = false;
		while (!q.empty()) {
			ll next = q.top();
			q.pop();
			if (next == 2048) {
				p = true;
				break;
			}
			if (q.empty()) break;
			if (next == q.top()) {
				q.pop();
				q.push(2 * next);
			}
		}
		cout << (p ? "YES" : "NO") << endl;
	}
	return 0;
}
