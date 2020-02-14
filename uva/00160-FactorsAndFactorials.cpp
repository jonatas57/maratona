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

vi primes;
vector<vi> memo(1001);

vi fats(int n) {
	vi fs;
	for (int i = 0;n > 1;i++) {
		fs.push_back(0);
		while (n % primes[i] == 0) {
			fs[i]++;
			n /= primes[i];
		}
	}
	return fs;
}

vi solve(int x) {
	if (memo[x].empty()) {
		if (x == 2) return memo[x] = {1};
		memo[x] = solve(x - 1);
		vi fs = fats(x);
		int l = memo[x].size();
		for (int i = 0;i < (int)fs.size();i++) {
			if (i < l) memo[x][i] += fs[i];
			else memo[x].push_back(fs[i]);
		}
	}
	return memo[x];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	for (int i = 2;i < 1000;i++) {
		bool p = true;
		for (int j = 2;j * j <= i and p;j++) {
			if (i % j == 0) p = false;
		}
		if (p) primes.push_back(i);
	}

	int n;
	while (cin >> n and n) {
		cout << setw(3) << n << "! =";
		vi fs = solve(n);
		int l = fs.size();
		for (int i = 0;i < l;i++) {
			if (i and i % 15 == 0) cout << endl << "      ";
			cout << setw(3) << fs[i];
		}
		cout << endl;
	}
	return 0;
}

