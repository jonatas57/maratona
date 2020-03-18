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

int top(deque<int>& q, bool inv) {
	return inv ? q.back() : q.front();
}

int pop(deque<int>& q, bool inv) {
	int x = top(q, inv);
	if (inv) q.pop_back(); else q.pop_front();
	return x;
}

void push(deque<int>& q, bool inv, int x) {
	if (inv) q.push_back(x);
	else q.push_front(x);
}

int flip(deque<int>& q, bool inv, int x) {
	int ans = 0;
	queue<int> p;
	for (;top(q, inv) != x;ans++) p.push(pop(q, inv));
	pop(q, inv);
	while (!p.empty()) push(q, inv, p.front()), p.pop();
	push(q, inv, x);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);//cin.tie(NULL);cout.tie(NULL);

	string s;
	while (getline(cin, s)) {
		stringstream ss;
		ss << s;
		deque<int> dq;
		vi v;
		int x;
		while (ss >> x) dq.push_back(x), v.push_back(x), cout << x << " ";
		cout << endl;
		sort(riter(v));
		int n = v.size();
		bool inv = false;
		for (int i = 0;i < n;) {
			if (top(dq, inv) == v[i] and i < n - 1) {
				cout << i + 1 << " ";
				pop(dq, inv);
				inv = !inv;
				i++;
			}
			else if (top(dq, !inv) == v[i]) {
				pop(dq, !inv);
				i++;
			}
			else {
				cout << n - flip(dq, inv, v[i]) << " ";
			}
		}
		cout << 0 << endl;
	}
	return 0;
}

