#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

const int N = 2e5, T = 4 * N + 10;
vi st(T, 0);
void update(int id, int l, int r, int pos) {
  if (l == r) st[id]++;
  else {
    int mid = avg(l, r);
    if (pos <= mid) update(id << 1, l, mid, pos);
    else update(id << 1 | 1, mid + 1, r, pos);
    st[id] = st[id << 1] + st[id << 1 | 1];
  }
}
int query(int id, int l, int r, int a, int b) {
  if (l > b or r < a) return 0;
  if (a <= l and r <= b) return st[id];
  int mid = avg(l, r);
  return query(id << 1, l, mid, a, b) + query(id << 1 | 1, mid + 1, r, a, b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vi ids(n + 1);
  loop(n) {
    int x;
    cin >> x;
    ids[x] = i;
  }
  ll inv = 0, mov = 0, med = -1;
  ll szl = 0, szr = 0;
  priority_queue<ll> l, r;
  for (int i = 1;i <= n;i++) {
    update(1, 0, n - 1, ids[i]);
    inv += query(1, 0, n - 1, ids[i] + 1, n - 1);

    if (med == -1) med = ids[i];
    else if (ids[i] > med) {
      r.push(-ids[i]);
      mov += ids[i] - med;
      szr++;
    }
    else {
      l.push(ids[i]);
      mov += med - ids[i];
      szl++;
    }
    if (szl > szr) {
      ll del = med - l.top();
      mov += (szr - szl + 1) * del;
      r.push(-med);
      med = l.top();
      l.pop();
      szr++;
      szl--;
    }
    else if (szr > szl + 1) {
      ll del = -r.top() - med;
      mov += (szl - szr + 1) * del;
      l.push(med);
      med = -r.top();
      r.pop();
      szl++;
      szr--;
    }
    cout << inv + mov - (szr * (szr + 1) + szl * (szl + 1)) / 2 << " ";
  }
  cout << endl;
  return 0;
}

