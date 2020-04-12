#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
// #define top(x)             x.front(), x.pop()

#define pb                 push_back
#define eb                 emplace_back

pair<ull, ull> overlap(ull a, ull b, ull c, ull d) {
	if (c < a) {
		swap(a, c);
		swap(b, d);
	}
	if (a > d or b < c) return {0, 0};
	if (c >= a and d <= b) return {c, d};
	return {max(c, a), min(b, d)};
}

struct square {
	ull x1, y1, x2, y2;
	ull b, w;
	square(ull a, ull b, ull c, ull d) : x1(a), y1(b), x2(c), y2(d) {}
	square inter(square& q) {
		ull ix1, ix2, iy1, iy2;
		tie(ix1, ix2) = overlap(x1, x2, q.x1, q.x2);
		tie(iy1, iy2) = overlap(y1, y2, q.y1, q.y2);
		if (ix1 and ix2 and iy1 and iy2) return square(ix1, iy1, ix2, iy2);
		else return square(0,0,0,0);
	}
	ull count(bool black) {
		if (x1 == 0) return 0;
		ull x = x2 - x1 + 1, y = y2 - y1 + 1;
		ull px = (x + (x % 2 ? (x1 % 2 ? 1 : -1) : 0)) / 2;
		ull py = (y + (y % 2 ? (y1 % 2 ? 1 : -1) : 0)) / 2;
		ull ix = x - px, iy = y - py;
		ull b = ix * py;
		b += px * iy;
		return (black ? b : area() - b);
	}
	ull area() {
		return (x2 - x1 + 1) * (y2 - y1 + 1);
	}
};
#define BLACK true
#define WHITE false
int main() {
  ios_base::sync_with_stdio(false);

	int t, n, m;
	cin >> t;
	loop(t) {
		cin >> n >> m;
		ull x1, y1, x2, y2, x3, y3, x4, y4;
		ull b, w;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;
		square white(x1, y1, x2, y2), black(x3, y3, x4, y4), board(1, 1, n, m);
		b = board.count(BLACK);
		b -= white.count(BLACK);
		b += black.count(WHITE);
		square inter = black.inter(white);
		b += inter.count(BLACK);
		w = board.area() - b;
		cout << w << " " << b << endl;
	}
  return 0;
}
