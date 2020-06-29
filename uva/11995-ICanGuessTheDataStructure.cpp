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
	while (cin >> n) {
		queue<int> q;
		stack<int> st;
		priority_queue<int> pq;
		int ans = 7, op, x;
		loop(n) {
			cin >> op >> x;
			if (op == 1) {
				if (ans & 1) q.push(x);
				if (ans & 2) st.push(x);
				if (ans & 4) pq.push(x);
			}
			else {
				if (ans & 1) {
					if (q.empty() or q.front() != x) ans &= 6;
					else q.pop();
				}
			  if (ans & 2) {
					if (st.empty() or st.top() != x) ans &= 5;
					else st.pop();
				}
			  if (ans & 4) {
					if (pq.empty() or pq.top() != x) ans &= 3;
					else pq.pop();
				}
			}
		}
		int b = __builtin_popcount(ans);
		if (b == 0) cout << "impossible" << endl;
		else if (b > 1) cout << "not sure" << endl;
		else if (ans & 1) cout << "queue" << endl;
		else if (ans & 2) cout << "stack" << endl;
		else cout << "priority queue" << endl;
	}
	return 0;
}

