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

int ask(int l, int r) {
	cout << "? " << r - l + 1;
	for (int i = l;i <= r;i++) cout << " " << i;
	cout << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

int ask(set<int>& s) {
	cout << "? " << s.size();
	each(x, s) cout << " " << x;
	cout << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, k;
		cin >> n >> k;
		vi sets(n + 1);
		vector<set<int>> ss(k);
		loop(k) {
			int c, x;
			cin >> c;
			vloop(j, c) {
				cin >> x;
				sets[x] = i;
				ss[i].insert(x);
			}
		}
		int l = 1, r = n;
		int mid = avg(l, r);
		int x = ask(1, mid), y = ask(mid + 1, r);
		int maxv;
		if (x < y) {
			l = mid + 1;
			maxv = y;
		}
		else {
			r = mid;
			maxv = x;
		}
		while (l < r) {
			mid = avg(l, r);
			x = ask(l, mid);
			if (x == maxv) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		int maxs = sets[l];
		set<int> sx;
		for (int i = 1;i <= n;i++) {
			if (!ss[maxs].count(i)) sx.insert(i);
		}
		int otherval = ask(sx);
		cout << "!";
		loop(k) {
			if (i == maxs) {
				cout << " " << otherval;
			}
			else {
				cout << " " << maxv;
			}
		}
		cout << endl;
		cout.flush();
		string result;
		cin >> result;
		if (result == "Incorrect") return 0;
	}
	return 0;
}

