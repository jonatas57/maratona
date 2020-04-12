#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long llu;
#define INF 0x3f3f3f3f

using namespace std;

int main() {
        ios_base::sync_with_stdio(false);


        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0;i < n;i++) {
                cin >> v[i];
        }
        sort(v.begin(), v.end());
        int last = 0;
        llu sum = 0;
        for (int i = 0;i < n;i++) {
                sum += v[i] - 1;
                if (v[i] != last) {
                        last++;
                }
        }
        if (last < v[n - 1]) {
                sum -= v[n - 1] - last;
        }
        cout << sum << endl;

        return 0;
}