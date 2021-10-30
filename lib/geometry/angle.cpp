// point
// norm
double angle(point& a, point& o, point& b) {
  point u = a - o, v = b - o;
  return acos(u * v / (norm(u) * norm(v)));
}
