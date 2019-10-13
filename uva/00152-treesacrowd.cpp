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
#define endl               "\n"

struct point {
	int x, y, z;
	point(int x, int y, int z) : x(x), y(y), z(z) {}
	point operator-(point b) {
		return point(x - b.x, y - b.y, z - b.z);
	}
};

double dist(point a, point b) {
	point del = b - a;
	return sqrt(del.x * del.x + del.y * del.y + del.z * del.z);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int x, y, z;
	vector<point> ps;
	while (cin >> x >> y >> z and x | y | z) ps.emplace_back(x, y, z);
	int n = ps.size();
	vi ans(10, 0);
	vector<double> mds(n, INF);
	loop(n - 1) {
		for (int j = i + 1;j < n;j++) {
			double d = dist(ps[i], ps[j]);
			mds[i] = min(mds[i], d);
			mds[j] = min(mds[j], d);
		}
	}
	loop(n) {
		if (mds[i] < 10) ans[(int)mds[i]]++;
	}
	each(s, ans) cout << setw(4) << s;cout << endl;
	return 0;
}

