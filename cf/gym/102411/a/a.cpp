#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);

    int a, b, n;
    cin >> a >> b >> n;
    int del = b - a;
    int x = (n - b + del - 1) / del;
    cout << 2 * x + 1 << endl;
    return 0;
}


