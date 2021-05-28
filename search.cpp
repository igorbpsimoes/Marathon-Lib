#include <bits/stdc++.h>
using namespace std;

//Next Permutation Search
// do {

// } while (next_permutation(all(x)));

//Subset
// int n = 20;
// for(int mask = 0; mask < (1 << n); ++mask) {
//     vector<int> subset;
//     for(int j = 0; j < n; ++i) {
//         if((mask >> j) & 1) {
//             subset.pb(j);
//         }
//     }
// }

//Binary Search
// int binarySearch(int lo, int hi) {
//     while(lo < hi) {
//         int mid = (lo + hi)/2;
//         if(isValid(mid)) {
//             hi = mid;
//         } else {
//             lo = mid + 1;
//         }
//     }
//     return lo;
// }

int CalcInversion(string &str, int size) {
  int inversions = 0;
  
  multiset<char> chars;

  for(auto i: str) {
    chars.insert(i);
    auto end = chars.end();
    auto upper = upper_bound(chars.begin(), chars.end(), i);
    inversions += distance(upper, end);
  }

  return inversions;
}