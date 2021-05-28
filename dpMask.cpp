/*

********MASK DP*************
for(int mask = 0; mask < (1 << (n + 1)); ++mask) {
    for(int currDish = 0; currDish < n; ++currDish) {
      if(((mask >> currDish) & 1) == false) continue;

      for(int b = 0; b < n; ++b) {
        if(((mask >> b) & 1) && currDish != b) {
          //if bit b is set, sum curr answer with its best answer
          dp[mask][currDish] = max(dp[mask][currDish], dp[mask - (1 << currDish)][b] + bonus[b][currDish] + satisfaction[currDish]);
        }
      }

      if(__builtin_popcount(mask) == dishQtt) ans = max(ans, dp[mask][currDish]);
    }
  }
  
*******RECURSIVE MASK DP********
int adj[MAXN][MAXN];
int girlMask[MAXN];
int dp[1 << MAXN];
int n;

int solve(int mask, int girls) {
  if(mask == (1 << n) - 1) popcount(mask) + popcount(girls);
  if(dp[mask] != -1) return dp[mask];

  int ans = popcount(mask) + popcount(girls);

  for(int j = 0; j < n; ++j) {
    if(not(mask & (1 << j))) {
      int newGirls = girls & girlMask[j];
      ans = max(ans, solve(mask | (1 << j), newGirls));
    }
  }

  return dp[mask] = ans;
}

*********DIGIT DP**************
ll dp[19][18*9 + 1][2];

ll solve(ll pos, ll sum, ll isSmaller) {
  
  if(pos == number.size()) return sum;
  if(dp[pos][sum][isSmaller] != -1) return dp[pos][sum][isSmaller];

  ll ans = 0;
  ll lim = (isSmaller == 0) ? number[pos] : 9;

  for(ll digit = 0; digit <= lim; ++digit) {
    ll newSmaller = isSmaller || (digit < lim);
    ll newSum = sum + digit;
    ans += solve(pos + 1, newSum, newSmaller);
  }

  return dp[pos][sum][isSmaller] = ans;
}

void GenDigits(ll x) {
  if(x >= 10) GenDigits(x/10);
  number.pb(x%10);
}

ll CalcDigits(int x) {
  memset(dp, -1, sizeof(dp));
  number.clear();

  if(x < 0) x = 0;
  GenDigits(x);
  return solve(0, 0, 0);
}

**********TSP****************
Description: Menor/Maior custo para visitar todos
os vértices de um grafo passando por cada vértice apenas uma vez

double adj[10][10];
double dp[10][1 << 10];
int decision[10][1 << 10];
int n;
 
double tsp(int pos, int visited) {
  //se toda a mask estiver ligada
  if(visited == (1 << n) - 1) return 0;
  if(dp[pos][visited] != -1) return dp[pos][visited];
  double ans = inf, tempAns;
 
  for(int j = 0; j < n; ++j) {
    if(not (visited & (1 << j))){
      tempAns = adj[pos][j] + tsp(j, visited | (1 << j));
      if(tempAns < ans) {
        ans = tempAns;
        decision[pos][visited] = j;
      }
    }
  }
 
  return dp[pos][visited] = ans;
}
*/