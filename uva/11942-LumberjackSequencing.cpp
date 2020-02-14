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

	int t;
	cin >> t;
	string s;
	getline(cin, s);
	cout << "Lumberjacks:" << endl;
	loop(t) {
		stringstream ss;
		vi a;
		int x;
		getline(cin, s);
		ss << s;
		while (ss >> x) {
			a.push_back(x);
		}
		int l = a.size();
		bool cres = true, decr = true;
		loop(l - 1) {
			cres &= (a[i] <= a[i + 1]);
			decr &= (a[l - i - 1] <= a[l - i - 2]);
		}
		cout << (cres or decr ? "Ordered" : "Unordered") << endl;
	}
	return 0;
}

