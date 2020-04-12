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

typedef tuple<int, bool, int, int, int> tup;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	int t, k, d;
	priority_queue<tup, vector<tup>, greater<tup>> pq;
	loop(q) {
		cin >> t >> k >> d;
		pq.emplace(t, true, k, d, i);
	}
	bitset<100> servers;
	int disp = n, id;
	bool ins;
	vector<bitset<100>> masks(q, 0);
	while (!pq.empty()) {
		tie(t, ins, k, d, id) = pq.top();
		pq.pop();
		if (ins) {
			if (disp >= k) {
				disp -= k;
				int sum = 0;
				for (int i = 0, j = 0;i < n and j < k;i++) {
					if (!servers[i]) {
						masks[id].set(i);
						servers.set(i);
						sum += i + 1;
						j++;
					}
				}
				pq.emplace(t + d, false, k, d, id);
				cout << sum << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else {
			disp += k;
			servers &= masks[id].flip();
		}
	}
	return 0;
}

