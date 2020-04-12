#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define loop(x) for (int i = 0;i < x;i++)
#define each(x, xs) for (auto& x : xs)
#define iter(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);



int main() {
    ios_base::sync_with_stdio(false);

    int n, r;
    cin >> n >> r;

    auto area = [r](int d) {
	double alfa = 2 * acos((double)d / (2 * r));
	return r * r * (alfa - sin(alfa));
    };

    vi a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    double ans = 0;
    double circle = PI * r * r;
    for (int i = 0;i < n;i++) {
	ans += circle;
	if (i) {
	    int d = a[i] - a[i - 1];
	    if (d < 2 * r) ans -= area(d);
	}
    }
    cout << fixed << setprecision(10) << ans << endl;
}

