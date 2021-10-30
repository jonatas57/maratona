// point-double
// circle
// midpoint
// dist
// intersectcirclecircle
vector<point> tangentPoint(circle& c, point& p) {
  point mp = midpoint(c.o, p);
  circle d(mp, dist(mp, p));
  return intersect(c, d);
}
