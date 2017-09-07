#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
ll n, a[4], b[4];
ll ans = 0, fac = 8;
 
int main() {
  for (int i = 0; i < 4; i++) cin >> a[i];
  cin >> n;
  n <<= 2;
  for (int i = 0; i < 4; i++) {
    ll foo = fac;
    for (int j = i; j < 4; j++) {
      b[j - i] = foo * a[j - i];
      foo >>= 1;
    }
    sort(b, b + (4 - i));
    ans += b[0] * (n / fac);
    n %= fac;
    fac >>= 1;
  }
  cout << ans << endl;
}
