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

#define left(x)            x << 1
#define right(x)           x << 1 | 1

const ll mod = 1000000007;

vector<ii> st(400010);

ii maxii(ii a, ii b) {
	return a.first == b.first ? min(a, b) : max(a, b);
}

void build(vi& v, int id, int l, int r) {
	if (l == r) {
		st[id] = {v[l], l};
	}
	else {
		int mid = avg(l, r);
		build(v, left(id), l, mid);
		build(v, right(id), mid + 1, r);
		st[id] = maxii(st[left(id)], st[right(id)]);
	}
}

ii query(int id, int l, int r, int a, int b) {
	if (l > b or r < a) return {0, -1};
	if (a <= l and r <= b) return st[id];
	int mid = avg(l, r);
	return maxii(query(left(id), l, mid, a, b), query(right(id), mid + 1, r, a, b));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi h(n);
	loop(n) cin >> h[i];
	build(h, 1, 0, n - 1);
	loop(n) {
		int l = i + 1, r = min(i + h[i] + 1, n);
		while (l < r) {
			int id, x, mid = avg(l, r);
			tie(x, id) = query(1, 0, n - 1, l, mid);
			if (x <= h[i]) l = mid + 1;
			else r = id;
		}
		cout << r - 1 - i << " ";
	}
	cout << endl;
	return 0;
}

