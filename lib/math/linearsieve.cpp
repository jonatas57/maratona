vi lp(N + 1, 0), ps;

void sieve() {
  for (int i = 2;i <= N;i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      ps.push_back(i);
    }
    each(p, ps) {
      if (p > lp[i] or i * p > N) break;
      lp[i * p] = p;
    }
  }
}

