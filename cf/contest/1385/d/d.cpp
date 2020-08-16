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

int check(string& s, vector<vi>& acc, char c, int l, int r) {
	if (l == r) return s[l] != c;
	int mid = avg(l, r);
	int x = mid - l + 1 - acc[mid + 1][c - 'a'] + acc[l][c - 'a'] + check(s, acc, c + 1, mid + 1, r);
	int y = r - mid - acc[r + 1][c - 'a'] + acc[mid + 1][c - 'a'] + check(s, acc, c + 1, l, mid);
	return min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		string s;
		cin >> n >> s;
		vector<vector<int>> acc(1, vi(26, 0));
		loop(n) {
			acc.push_back(acc[i]);
			acc[i + 1][s[i] - 'a']++;
		}
		cout << check(s, acc, 'a', 0, n - 1) << endl;
	}
	return 0;
}

