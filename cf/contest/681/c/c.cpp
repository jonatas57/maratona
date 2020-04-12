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

priority_queue<int, vi, greater<int>> q;
vector<string> ans;

void insert(int x) {
	ans.push_back("insert " + to_string(x));
	q.push(x);
}

void removeMin() {
	if (q.empty()) insert(0);
	ans.push_back("removeMin");
	q.pop();
}

void getMin(int x) {
	if (q.empty()) {
		insert(x);
	}
	else {
		int y = q.top();
		if (y < x) {
			removeMin();
			getMin(x);
			return;
		}
		else if (y > x) {
			insert(x);
		}
	}
	ans.push_back("getMin " + to_string(x));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, x;
	string op;
	cin >> n;
	loop(n) {
		cin >> op;
		if (op == "removeMin") removeMin();
		else {
			cin >> x;
			if (op == "insert") insert(x);
			else getMin(x);
		}
	}
	cout << ans.size() << endl;
	each(s, ans) cout << s << endl;
	return 0;
}
