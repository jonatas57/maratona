struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  point operator+(const point& p) const {
    return point(x + p.x, y + p.y);
  }
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  ll operator*(const point& p) const {
    return x * p.x + y * p.y;
  }
  point operator*(const ll a) const {
    return point(a * x, a * y);
  }
  ll operator^(const point& p) const {
    return x * p.y - y * p.x;
  }

  bool operator<(const point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
  bool operator==(const point& p) const {
    return x == p.x and y == p.y;
  }

  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
  friend ostream& operator<<(ostream& os, point& p) {
    os << p.x << " " << p.y;
    return os;
  }
};
