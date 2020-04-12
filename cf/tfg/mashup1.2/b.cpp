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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

struct knight {
	ll p, c, id, ans = 0;
	bool operator<(knight& k) {
		return (p == k.p ? c > k.c : p < k.p);
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<knight> a(n);
	loop(n) {
		cin >> a[i].p;
		a[i].id = i;
	}
	loop(n) cin >> a[i].c;
	ll cnt = 0, acc = 0;
	set<ll> coins;
	sort(iter(a));
	loop(n) {
		acc += a[i].c;
		coins.insert(a[i].c);
		a[i].ans = acc;
		if (cnt == k) {
			acc -= *coins.begin();
			coins.erase(coins.begin());
		}
		else cnt++;
	}
	sort(iter(a), [](knight& a, knight& b) {
		return a.id < b.id;
	});
	each(k, a) {
		cout << k.ans << " ";
	}
	cout << endl;
	return 0;
}
