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

struct point {
	double x, y;
	point(double x, double y) : x(x), y(y) {}
	void operator+=(point p) {
		x += p.x;
		y += p.y;
	}
	point operator*(double a) {
		return point(a * x, a * y);
	}
};

double norm(point p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

double diag = sqrt(2) / 2;
map<string, pair<double, double>> dir = {{"N", {0, 1}}, {"NE", {diag, diag}}, {"E", {1,0}},{"SE",{diag,-diag}},{"S",{0,-1}},{"SW",{-diag,-diag}},{"W",{-1,0}},{"NW",{-diag,diag}}};

int main() {
	string s;
	for (int m = 1;cin >> s and s != "END";m++) {
		point st(0, 0);
		int a = 0;
		string d = "";
		for (int i = 0;s[i];i++) {
			if (isdigit(s[i])) {
				a *= 10;
				a += s[i] - '0';
			}
			else if (isalpha(s[i])) {
				d += s[i];
			}
			else {
				auto next = dir[d];
				st += point(next.first, next.second) * a;
				a = 0;
				d = "";
			}
		}
		cout << "Map #" << m << endl;
		printf("The treasure is located at (%.3f,%.3f).\n", st.x, st.y);
		printf("The distance to the treasure is %.3f.\n\n", norm(st));
	}
	return 0;
}

