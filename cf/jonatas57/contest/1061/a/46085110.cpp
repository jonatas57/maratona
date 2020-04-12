#include <bits/stdc++.h>

using namespace std;

int main() {
        ios_base::sync_with_stdio(false);


        int n, s;
        cin >> n >> s;
        int x = s / n, y = s % n;
        if (y != 0) x++;
        cout << x << endl;
        return 0;
}