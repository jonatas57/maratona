struct circle {
  point o;
  ll r;
  circle(point o = point(), ll r = 0) : o(o), r(r) {}
  bool operator==(const circle& c) const {
    return o == c.o and r == c.r;
  }
  bool operator<(const circle& c) const {
    return o == c.o ? r < c.r : o < c.o;
  }

  friend istream& operator>>(istream& is, circle& c) {
    is >> c.o >> c.r;
    return is;
  }
};
