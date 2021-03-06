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

	string s;
	cin >> s;
	vector<ii> ans;
	stack<int> bs;
	for (int i = 0;s[i];i++) {
		if (s[i] == '(') bs.push(i);
		else if (!bs.empty()) ans.emplace_back(bs.top(), i), bs.pop();
	}
	int sz = ans.size(), ml = 0, qtd = 0;
	sort(iter(ans));
	for (int i = 0, l = -1, r = -10;i < sz;i++) {
		if (ans[i].first > l and ans[i].first < r) continue;
		if (ans[i].first == r + 1) {
			r = ans[i].second;
		}
		else {
			tie(l, r) = ans[i];
		}
		if (r - l + 1 > ml) ml = r - l + 1, qtd = 1;
		else if (r - l + 1 == ml) qtd++;
	}
	cout << ml << " " << (ml ? qtd : 1) << endl;
	return 0;
}

