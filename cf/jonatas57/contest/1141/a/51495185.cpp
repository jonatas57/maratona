#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

pair<ii, int> div(int n) {
	ii x = {0, 0};
	while (n % 2 == 0) {
		x.first++;
		n /= 2;
	}
	while (n % 3 == 0) {
		x.second++;
		n /= 3;
	}
	return {x, n};
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	auto ndiv = div(n), mdiv = div(m);
	if (ndiv.second == mdiv.second && ndiv.first.first <= mdiv.first.first && ndiv.first.second <= mdiv.first.second) {
		cout << mdiv.first.first - ndiv.first.first + mdiv.first.second - ndiv.first.second << endl;
	}
	else {
		cout << - 1 << endl;
	}
	return 0;
}
