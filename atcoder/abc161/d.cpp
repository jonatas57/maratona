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

struct lunlun {
	string s = "";
	int l = 0;
	void inc(int pos = 0) {
		if (pos == l) {
			s += '1';
			l++;
			tomin(pos);
			return;
		}
		s[pos]++;
		if (s[pos] == '9' + 1 or (l > 1 and s[pos] == s[pos + 1] + 2)) {
			inc(pos + 1);
			tomin(pos + 1);
		}
	}
	void tomin(int qtd) {
		for (int i = qtd - 1;i >= 0;i--) {
			s[i] = max(s[i + 1] - 1, (int)'0');
		}
	}
	void print() {
		loop(l) {
			cout << s[l - i - 1];
		}
		cout << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int k;
	cin >> k;
	lunlun s;
	loop(k) {
		s.inc();
	}
	s.print();
	return 0;
}

