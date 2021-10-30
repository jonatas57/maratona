// point
// segsegintersect
void cutPolygon(vector<point>& pol, point& a, point& b, int side) {
  vector<point> q;
  int n = pol.size();
  point cut = b - a;
  loop(n) {
    double l1 = cut ^ (pol[i] - a), l2 = 0;
    if (i != n - 1) l2 = cut ^ (pol[i + 1] - a);
    if (l1 * side > -EPS) q.push_back(pol[i]);
    if (l1 * l2 < -EPS) q.push_back(intersect(pol[i], pol[i + 1], a, b));
  }
  if (!q.empty() and q[0] != q.back()) q.push_back(q[0]);
  pol.swap(q);
}
