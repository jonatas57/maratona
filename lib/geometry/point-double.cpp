struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(const point& p) const {
    return point(x + p.x, y + p.y);
  }
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  double operator*(const point& p) const {
    return x * p.x + y * p.y;
  }
  point operator*(const ll a) const {
    return point(a * x, a * y);
  }
  double operator^(const point& p) const {
    return x * p.y - y * p.x;
  }
  point operator/(const double a) const {
    return point(x / a, y / a);
  }

  bool operator<(const point& p) const {
    return abs(x - p.x) < EPS ? y + EPS < p.y : x + EPS < p.x;
  }
  bool operator==(const point& p) const {
    return abs(x - p.x) < EPS and abs(y - p.y) < EPS;
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
