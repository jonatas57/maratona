#include <bits/stdc++.h>

using namespace std;

typedef vector<int>                vi;

#define loop(x)                    for (int i = 0;i < x;i++)
#define each(x, xs)                for (auto& x : xs)

int mdc(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return mdc(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, x, gcd;
	cin >> n >> x;
	vi a(n);
	loop(n) cin >> a[i], gcd = (i == 0 ? a[i] : mdc(gcd, a[i]));
	if (x % gcd == 0) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
