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

vector<vi> ps;
vi pos;

int pop(int x) {
	int y = ps[x].back();
	ps[x].pop_back();
	pos[y] = -1;
	return y;
}

void push(int x, int a) {
	ps[x].push_back(a);
	pos[a] = x;
}

stack<int> getPile(int x, int a, bool geta = true) {
	stack<int> q;
	while (ps[x].back() != a) {
		q.push(pop(x));
	}
	if (geta) q.push(pop(x));
	return q;
}

void removeAbove(int x, int a) {
	stack<int> q = getPile(x, a, false);
	while (!q.empty()) {
		push(q.top(), q.top());
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	loop(n) {
		ps.emplace_back(1, i);
		pos.push_back(i);
	}
	string com, tp;
	int a, b;
	while (cin >> com and com != "quit") {
		cin >> a >> tp >> b;
		int x = pos[a], y = pos[b];
		if (a == b or x == y) continue;
		if (tp == "onto") removeAbove(y, b);
		if (com == "move") {
			removeAbove(x, a);
			push(y, pop(x));
		}
		else {
			stack<int> q = getPile(x, a);
			while (!q.empty()) {
				push(y, q.top());
				q.pop();
			}
		}
	}
	loop(n) {
		cout << i << ":";
		each(x, ps[i]) cout << " " << x;
		cout << endl;
	}
	return 0;
}

