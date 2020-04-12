#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                2000000005
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

	int n;
	cin >> n;
	vi a(3 * n), ans(3 * n, 1);
	loop(n) {
		cin >> a[i];
		a[n + i] = a[n + n + i] = a[i];
	}
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.emplace(2 * a[3 * n - 1], 3 * n - 1);
	for (int i = 3 * n - 2;i >= 0;i--) {
		int next = INF;
		while (!pq.empty() and pq.top().first < a[i]) {
			next = min(next, pq.top().second);
			pq.pop();
		}
		ans[i] = min(ans[i + 1] + 1, next - i);
		pq.emplace(2 * a[i], i);
	}
	loop(n) {
		cout << (ans[i] >= 2 * n ? -1 : ans[i]) << " ";
	}
	cout << endl;
	return 0;
}
