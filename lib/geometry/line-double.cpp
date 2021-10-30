// point-double
struct line {
  double a, b, c;
  line(point& p, point& q) {
    point del = p - q;
    a = del.y;
    b = -del.x;
    c = -(a * p.x + b * p.y);
  }
  line(double a, double b, double c) : a(a), b(b), c(c) {}
  double eval(point& p) {
    return a * p.x + b * p.y + c;
  }
  bool inside(point& p) {
    return abs(eval(p)) < EPS;
  }
};
