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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

struct node {
	int x, dep;
	node *left, *right, *par;
	node(int x) : x(x), dep(1), left(nullptr), right(nullptr), par(nullptr) {}
};

int dep(node* t) {
	return t ? t->dep : 0;
}

node* insert(node* t, node *n) {
	if (!t) return n;
	if (t->x > n->x) {
		n->left = t;
		if (n->par) n->par->right = n;
		if (n->left) n->left->par = n;
		n->dep = 1 + dep(n->left);
		return n;
	}
	if (t->x < n->x) {
		t->right = insert(t->right, n);
		n->par = t;
		t->dep = max(1 + dep(t->left), 1 + dep(t->right));
	}
	return t;
}

node* remove(node *t) {
	if (t->left) {
		node *ans = remove(t->left);
		t->dep = max(1 + dep(t->left), 1 + dep(t->right));
		return ans;
	}
	if (t->x == 1) return t;
	if (t->right) t->right->par = t->par;
	if (t->par) t->par->left = t->right;
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	node *t = nullptr;
	int x;
	loop(n) {
		cin >> x;
		t = insert(t, new node(x));
	}
	int mind = t->dep, id = -1;
	loop(n) {
		node *r = remove(t);
		if (r->x == 1) {
			t->left = t->right;
			t->right = nullptr;
		}
		else {
			r->dep = 1;
			r->left = r->right = r->par = nullptr;
			t = insert(t, r);
			if (mind > t->dep) {
				mind = t->dep;
				id = i;
			}
		}
	}
	cout << mind << " " << id + 1 << endl;
	return 0;
}
