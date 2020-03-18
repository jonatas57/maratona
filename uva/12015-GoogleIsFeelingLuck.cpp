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
	loop(n) {
		vector<string> sites(10);
		vector<ii> ss(10);
		loop(10) {
			cin >> sites[i] >> ss[i].first;
			ss[i].second = i;
		}
		sort(iter(ss), [](ii a, ii b) {
			return a.first == b.first ? a.second < b.second : a.first > b.first;
		});
		cout << "Case #" << i + 1 << ":" << endl;
		for (int i = 0;i < 10 and ss[i].first == ss[0].first;i++) {
			cout << sites[ss[i].second] << endl;
		}
	}
	return 0;
}

