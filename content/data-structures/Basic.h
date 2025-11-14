/**
 * Author: Simon Lindholm, chilli
 * Date: 2018-07-23
 * License: CC0
 * Source: http://codeforces.com/blog/entry/60737
 * Description: Hash map with mostly the same API as unordered\_map, but \tilde
 */

// BS
int l = 0, r = n - 1, ans = -1;
while (l <= r) {
  int mid = l + (r - l) / 2;
  if (check(mid))
    ans = mid, l = mid + 1;
  else
    h = mid - 1;
}
if (ans == -1)
  ; // Ans not found.
else
  ; // Ans is 'ans'
// 
const dl EPS = 1e-9;
dl l = 0, r = 1e9;
while (r - l > EPS) {
    dl m1 = l + (r - l) / 3;
    dl m2 = r - (r - l) / 3;
    
    // cout << "m1: " << m1 << " , m2: " << m2 << ", f(m1): " << f(m1) << ", f(m2): " << f(m2) << endl;
    if (f(m1) < f(m2)) l = m1;
    else r = m2;
}
cout << f(l) << endl;
