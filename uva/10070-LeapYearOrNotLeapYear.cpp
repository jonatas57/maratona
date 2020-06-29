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

bool divisible(int n, int d) {
	return n % d == 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	for (int t = 0;cin >> s;t++) {
		int o = 0, e = 0;
		for (int i = 0;s[i];i++) {
			(i & 1 ? o : e) += s[i] - '0';
		}
		int x = stoi(s.substr(s.length() - 4), nullptr, 10);
		bool leap = (divisible(x, 4) and !divisible(x, 100)) or divisible(x, 400);
		bool hulu = divisible(x, 5) and divisible(e + o, 3);
		bool bulu = divisible(x, 5) and divisible(e - o, 11) and leap;
		bool none = !leap and not hulu and not bulu;

		if (t) cout << endl;
		if (none) cout << "This is an ordinary year." << endl;
		else {
			if (leap) cout << "This is leap year." << endl;
			if (hulu) cout << "This is huluculu festival year." << endl;
			if (bulu) cout << "This is bulukulu festival year." << endl;
		}
	}
	return 0;
}

