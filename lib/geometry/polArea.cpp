// point
double area(vector<point>& pol) {
  double ans = 0;
  loop((int)pol.size() - 1) {
    ans += pol[i] ^ pol[i + 1];
  }
  return abs(ans / 2);
}
