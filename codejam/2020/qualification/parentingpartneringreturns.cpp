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

typedef tuple<int, int, int> tup;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		int s, e;
		vector<tup> sl;
		string ans(n, ' ');
		loop(n) {
			cin >> s >> e;
			sl.emplace_back(s, 1, i);
			sl.emplace_back(e, 0, i);
		}
		sort(iter(sl));
		int cnt = 0;
		queue<char> free;
		free.push('C');
		free.push('J');
		int ins, id;
		each(p, sl) {
			tie(std::ignore, ins, id) = p;
			if (ins) {
				cnt++;
				if (free.empty()) {
					ans = "IMPOSSIBLE";
					break;
				}
				else {
					ans[id] = free.front();
					free.pop();
				}
			}
			else {
				cnt--;
				free.push(ans[id]);
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}

