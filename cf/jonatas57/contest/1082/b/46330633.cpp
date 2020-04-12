#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define rep(a, b, c) for(int i = a;i < b;i++)
#define rp(a) rep(0, a, 1)

struct silver {
  int esq;
  int dir;
  silver (int e, int d) : esq(e), dir(d) {}
  bool operator<(silver& x) {
    return esq + dir < x.esq + x.dir;
  }
  int val() {
    return esq + dir;
  }
  int max() {
    return esq > dir ? esq : dir;
  }
};

int main() {
  int n, qtd = 0, qtds = 0, maxg = -1, gs = 0;
  string s;
  cin >> n >> s;
  vector<int> subs;
  rp(n + 1) {
    if (s[i] == 'S' || s[i] == '\0') {
      subs.push_back(qtd);
      qtds++;
      if (maxg < qtd) maxg = qtd;
      qtd = 0;
    }
    else {
      qtd++;
      gs++;
    }
  }
  vector<silver> ss;
  silver mx = silver(0, 0);
  rp(qtds - 1) {
    ss.push_back(silver(subs[i], subs[i + 1]));
    if (mx < ss[i]) mx = ss[i];
  }
  int l = ss.size(), ans;
  if (l == 0) {
    ans = n;
  }
  else if (l == 1) {
    ans = ss[0].val();
  }
  else if (mx.val() == gs) {
    ans = gs;
  }
  else {
    ans = mx.val() + 1;
  }
  cout << ans << endl;
  return 0;
}
