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

	int n, k;
	string s;
	cin >> n >> k >> s;
	vi first(26, -1), last(26, -1);
	loop(n) {
		int x = s[i] - 'A';
		if (first[x] == -1) first[x] = i;
		last[x] = max(last[x], i);
	}
	vector<ii> sl;
	loop(26) {
		if (first[i] != -1) sl.emplace_back(first[i], -1);
		if (last[i] != -1) sl.emplace_back(last[i], 1);
	}
	sort(iter(sl));
	int ans = 0, cnt = 0;
	for (auto& [x, y] : sl) {
		cnt -= y;
		ans = max(ans, cnt);
	}
	cout << (k < ans ? "YES" : "NO") << endl;
	return 0;
}

