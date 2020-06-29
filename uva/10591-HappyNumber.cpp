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

vb visit(800, false);
bool ishappy(int n) {
	if (n < 800 and visit[n]) return false;
	if (n < 800) visit[n] = true;
	int sum = 0;
	for (int i = n;i;i /= 10) {
		int x = i % 10;
		sum += x * x;
	}
	bool ans = sum == 1 ? true : ishappy(sum);
	if (n < 800) visit[n] = false;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1;i <= t;i++) {
		int n;
		cin >> n;
		cout << "Case #" << i << ": " << n << " is a" << (ishappy(n) ? " Happy" : "n Unhappy") << " number." << endl;
	}
	return 0;
}

