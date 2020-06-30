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
	cin >> n >> k;
	vi a, b, ab;
	int t, x, y;
	loop(n) {
		cin >> t >> x >> y;
		if (x and y) ab.push_back(t);
		else if (x) a.push_back(t);
		else if (y) b.push_back(t);
	}
	sort(iter(ab)), sort(iter(a)), sort(iter(b));
	int i = 0, j = 0, l = 0;
	int sum = 0;
	each(t, ab) {
		if (i == k) break;
		i++;
		sum += t;
	}
	each(t, a) {
		if (i + j == k) break;
		j++;
		sum += t;
	}
	each(t, b) {
		if (i + l == k) break;
		l++;
		sum += t;
	}
	if (i + j != k or i + l != k) cout << -1 << endl;
	else {
		int sza = a.size(), szb = b.size();
		while (i > 0 and j < sza and l < szb and ab[i - 1] > a[j] + b[l]) {
			sum += a[j] + b[l] - ab[i - 1];
			i--;
			j++;
			l++;
		}
		cout << sum << endl;
	}
	return 0;
}

