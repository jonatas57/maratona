#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int n;
vector<string> board(4);

void putRook(int x, int y) {
  if (board[x][y] != '.') return;
  board[x][y] = 'O';
  for (int dir = 0;dir < 4;dir++) {
    int nx = x, ny = y;
    loop(n) {
      nx += (dir == 0) - (dir == 2);
      ny += (dir == 1) - (dir == 3);
      if (nx < 0 or nx >= n or ny < 0 or ny >= n or board[nx][ny] == 'X') break;
      if (board[nx][ny] == '.') board[nx][ny] = 'a';
      else board[nx][ny]++;
    }
  }
}

void remRook(int x, int y) {
  if (board[x][y] != 'O') return;
  board[x][y] = '.';
  for (int dir = 0;dir < 4;dir++) {
    int nx = x, ny = y;
    loop(n) {
      nx += (dir == 0) - (dir == 2);
      ny += (dir == 1) - (dir == 3);
      if (nx < 0 or nx >= n or ny < 0 or ny >= n or board[nx][ny] == 'X') break;
      if (board[nx][ny] == 'a') board[nx][ny] = '.';
      else board[nx][ny]--;
    }
  }
}

int solve() {
  int ans = 0;
  loop(n) vloop(j, n) {
    if (board[i][j] == '.') {
      putRook(i, j);
      ans = max(ans, 1 + solve());
      remRook(i, j);
    }
  }
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  while (cin >> n and n) {
    loop(n) cin >> board[i];
    cout << solve() << endl;
  }
	return 0;
}

