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

map<char, int> suit2int = {{'C', 0}, {'D', 1}, {'H', 2}, {'S', 3}}, rank2int = {{'K', 0}, {'A', 1}, {'T', 10}, {'J', 11}, {'Q', 12}};
string int2suit = "CDHS", int2rank = "KA23456789TJQ";

struct card {
	int r, s, val;
	bool joker;
	card(string c) : s(0) {
		if (isdigit(c[1])) {
			joker = true;
			r = c[1] - '0';
			val = 51 + r;
		}
		else {
			joker = false;
			r = isdigit(c[0]) ? c[0] - '0' : rank2int[c[0]];
			s = suit2int[c[1]];
			val = s * 13 + r;
		}
	}
};

vector<vb> allcards;

struct rect {
	int x, y;
	bitset<13> ranks;
	bitset<4> suits;
	vector<pair<int, string>> js;
	int lastsuit;

	rect(int i, int j) : x(i), y(j) {}
	
	void addCard(card& c) {
		if (c.joker) js.emplace_back(c.r, "");
		else {
			ranks.set(c.r);
			suits.set(c.s);
			lastsuit = c.s;
		}
	}

	int check() {
		int qtdr = ranks.count(), qtds = suits.count(), qtdj = js.size();
		if (!qtdj) return qtdr == 9 or qtds == 1;
		if (qtds > 1 and qtdr + qtdj < 9) return 0;
		return -1;
	}

	bool replace() {
		return false;
	}

	auto hasJoker() {
		return js;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	allcards.assign(13, vb(4, false));
	int n, m;
	cin >> n >> m;
	vector<vector<card>> cs(n);
	string s;
	loop(n) {
		vloop(j, m) {
			cin >> s;
			cs[i].emplace_back(s);
			if (not cs[i][j].joker) allcards[cs[i][j].r][cs[i][j].s] = false;
		}
	}
	vector<rect> possible;
	loop(n - 2) {
		vloop(j, m - 2) {
			rect r(i + 1, j + 1);
			vloop(k, 9) {
				r.addCard(cs[i + k / 3][j + k % 3]);
			}
			if (r.check()) possible.push_back(r);
		}
	}
	int sz = possible.size();
	if (sz >= 2) {
		bool found = false;
		int x, y, a, b;
		vector<string> js;
		for (int i = 0;i < sz and not found;i++) {
			x = possible[i].x, y = possible[i].y;
			for (int j = i + 1;j < sz and not found;j++) {
				if ((a = possible[j].x) >= x + 2 or (b = possible[j].y) >= y + 2) {
					found = true;
					for (auto& [id, r] : possible[i].hasJoker()) js.push_back("J" + to_string(id) + " with " + r);
					for (auto& [id, r] : possible[j].hasJoker()) js.push_back("J" + to_string(id) + " with " + r);
				}
			}
		}
		if (found) {
			cout << "Solution exists." << endl;
			if (js.size()) {
				sort(iter(js));
				cout << "Replace ";
				loop(js.size()) {
					if (i) cout << " and ";
					cout << js[i];
				}
				cout << "." << endl;
			}
			else cout << "There are no jokers." << endl;
			cout << "Put the first square to (" << x << ", " << y << ")." << endl;
			cout << "Put the second square to (" << a << ", " << b << ")." << endl;
		}
		else cout << "No solution." << endl;
	}
	else {
		cout << "No solution." << endl;
	}
	return 0;
}
