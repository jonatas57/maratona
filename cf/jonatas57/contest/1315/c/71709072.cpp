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

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		int x;
		vi a(2 * n, 0), b(2 * n + 1, -1);
		loop(n) cin >> x, b[x] = 2 * i, a[2 * i] = x;
		int aux = 0;
		bool p = true;
		priority_queue<int, vi, greater<int>> q;
		for (int i = 1, j = 0;p and i <= 2 * n;i++) {
			if (b[i] != -1) aux++, q.push(b[i] + 1);
			else {
				aux--;
				if (aux < 0) p = false;
				else {
					a[q.top()] = i;
					q.pop();
				}
			}
		}
		if (p) {
			each(x, a) cout << x << " ";
			cout << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}

