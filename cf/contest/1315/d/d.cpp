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
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi a(n);
	map<int, priority_queue<ll>> ts;
	int x;
	set<ll> next;
	loop(n) cin >> a[i], next.insert(a[i]);
	loop(n) cin >> x, ts[a[i]].push(x);
	ll ans = 0, sum = 0;
	int last = -1;
	priority_queue<ll> added;
	for (auto& [c, q] : ts) {
		if (last != -1 and c - last > 1) {
			while (!added.empty() and last < c) {
				sum -= added.top();
				added.pop();
				ans += sum;
				last++;
			}
		}
		q.pop();
		while (!q.empty()) {
			sum += q.top();
			added.push(q.top());
			q.pop();
		}
		ans += sum;
		last = c;
	}
	while (!added.empty()) {
		sum -= added.top();
		added.pop();
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}

