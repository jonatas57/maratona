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

struct tree {
	int val, sum;
	bool empty, neg;
	tree *left, *right, *par;
} head;

tree* newNode(tree* t = nullptr) {
	tree* x = new tree;
	x->val = 0;
	x->sum = t ? t->sum : 0;
	x->empty = true;
	x->neg = false;
	x->left = x->right = nullptr;
	x->par = t;
	return x;
}

void freeTree(tree* t) {
	if (t == nullptr) return;
	freeTree(t->left);
	freeTree(t->right);
	delete t;
}

tree* mountTree(tree* par = nullptr) {
	bool stop = false;
	tree* t = newNode(par);
	if (!par) {
		char c;
		do { c = getchar(); } while (c != '(');
	}
	bool left = true;
	while (!stop) {
		char c = getchar();
		if (isspace(c)) continue;
		if (c == ')') stop = true;
		else if (c == '(') {
			if (left) {
				t->left = mountTree(t);
				left = false;
			}
			else {
				t->right = mountTree(t);
			}
		}
		else if (isdigit(c)) {
			t->empty = false;
			t->val *= 10;
			t->val += c - '0';
		}
		else if (c == '-') {
			t->neg = true;
		}
	}
	if (t->empty) {
		delete t;
		t = nullptr;
	}
	else if (t->neg) t->val *= -1;
	return t;
}

bool search(tree* t, int sum) {
	if (!t) return false;
	if (!t->left and !t->right and sum == t->val) return true;
	return search(t->left, sum - t->val) or search(t->right, sum - t->val);
}

int main() {
	int sum;
	while (cin >> sum) {
		tree *t = mountTree();
		cout << (search(t, sum) ? "yes" : "no") << endl;
		freeTree(t);
	}
	return 0;
}

