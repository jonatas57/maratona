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
		vi a(n), used(n + 1, 0);
		vb ok(n, false);
		int notok = 0;
		loop(n) {
			cin >> a[i];
			used[a[i]]++;
			ok[i] = a[i] == i;
		}
		int mex = 0;
		while (mex < n and used[mex]) mex++;
		while (notok < n and ok[notok]) notok++;
		vi ans;
		while (notok < n) {
			if (mex < n) {
				int tmp = a[mex];
				used[a[mex]]--;
				a[mex] = mex;
				ans.push_back(mex + 1);
				ok[mex] = true;
				used[mex]++;
				if (!used[tmp] and tmp < mex) mex = tmp;
			}
			else {
				int tmp = a[notok];
				used[a[notok]]--;
				a[notok] = mex;
				used[mex]++;
				ans.push_back(notok + 1);
				mex = tmp;
			}
			while (mex < n and used[mex]) mex++;
			while (notok < n and ok[notok]) notok++;
		}
		cout << ans.size() << endl;
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	return 0;
}

