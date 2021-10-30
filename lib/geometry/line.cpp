// point
struct line {
  ll a, b, c;
  line(point& p, point& q) {
    point del = p - q;
    a = del.y;
    b = -del.x;
    c = -(a * p.x + b * p.y);
    ll m = gcd(abs(a), gcd(abs(b), abs(c)));
    if (a < 0) m = -m;
    if (m) a /= m, b /=m, c /= m;
  }
  ll eval(point& p) {
    return a * p.x + b * p.y + c;
  }
  bool inside(point& p) {
    return eval(p) == 0;
  }
};
