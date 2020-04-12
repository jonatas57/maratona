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

#define PI                 acos(-1)
#define DPI                acos(1)

double cs(int a, int b, int c) {
	return (double)(b * b + c * c - a * a) / (2 * b * c);
}

double area(int r, double alfa) {
	double senA = sin(alfa), cosA = cos(alfa);
	return r * r * (senA * ((1 + cosA) / (1 - cosA) + 1) - PI + alfa) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b, c, r;
	cin >> a >> b >> c >> r;
	double cosA = cs(a, b, c), cosB = cs(b, a, c), cosC = cs(c, a, b);
	double A = acos(cosA), B = acos(cosB), C = acos(cosC);
	double p = (a + b + c) / 2.0;
	double areaT = sqrt(p * (p - a) * (p - b) * (p - c)), s1 = area(r, A), s2 = area(r, B), s3 = area(r, C);
	double ans = (areaT - s1 - s2 - s3) / areaT;
	printf("%.15f\n", ans);
	return 0;
}

