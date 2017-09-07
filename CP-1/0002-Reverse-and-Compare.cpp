#include <bits/stdc++.h>
 
using namespace std;
 
string s;
unordered_map <char, int> m;
 
int main() {
  cin >> s;
  int n = s.length();
  long long ans = n * 1LL * (n - 1) / 2 + 1;
  for (auto z : s) {
    ans -= m[z];
    m[z]++;
  }
  cout << ans << endl;
}
