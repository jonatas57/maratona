#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

#define loop(x)        for (int i = 0;i < x;i++)
#define each(x, xs)    for (auto& x : xs)
#define avg(l, r)      l + (r - l) / 2

typedef vector<int>    vi;
typedef pair<int, int> ii;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	vi a(n);
	loop(n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int t;
	int minc = INF, cost;
	for (int i = 1;i <= 100;i++) {
		cost = 0;
		each(x, a) {
			int aux = 0;
			if (x > i) aux = 1;
			else if (x < i) aux = -1;
			cost += abs(x - (i + aux));
		}
		if (minc <= cost and i > 0) {
			break;
		}
		minc = cost;
		t = i;
	}
	cout << t << " " << minc << endl;
	return 0;
}
