/* 
*********Cummulate Xor Array************
int xorAcc[];
// xorAcc[i] = xorAcc[i - 1] ^ num[i];

int getInterval(int l, int r) {
  return xorAcc[r] ^ xorAcc[l - 1];
}

***********LCS********************
string a, b;
int result[MAXN][MAXN];

int lcs(int i, int j) {
  if(i == -1 || j == -1) return 0;

  if(result[i][j] == -1) {
    if(a[i] == b[j]) result[i][j] = 1 + lcs(i-1, j-1);
    else result[i][j] = max(lcs(i-1, j), lcs(i, j-1)); 
  }

  return result[i][j];
}

*********KNAPSACK***************
int dp[MAXN][MAXN];
int weight[MAXN][MAXN];
int cap, categQtt;

void knapsack() {
  for(int categ = 1; categ <= categQtt; ++categ) {
    for(int item = 0; item < weight[categ].size(); ++item) {
      for(int free = 0; free <= cap; ++free) {
        ll toGet = -1;
        ll dontGet = dp[categ - 1][free];
        if(free >= weight[categ][item]) {
          toGet = dp[categ - 1][free - weight[categ][item]] + weight[categ][item];
        }
        dp[categ][free] = max({dp[categ][free], toGet, dontGet});
      }
    }
  }
}

**********LONGEST PALINDROME**************
string a;
int memo[MAXN][MAXN];
int solve(int i, int j) {
  if(i > j) return 0;
  if(i == j) return 1;

  if(memo[i][j] == -1) {
    if(a[i] == a[j]) memo[i][j] = 2 + solve(i + 1, j - 1);
    else memo[i][j] = max(solve(i+1, j), solve(i, j-1));
  }
  
  return memo[i][j];
}

********** MAX SUM 2D **************
int input[MAXN][MAXN];
int ans = INT_MIN;

bool kadane(vector<int> &num, int rows, int col, pii &pos) {
  int maxSum = -500;
  int currSum = -500;
  int start = 0, end = 0;

  for(int i = 0; i < rows; ++i) {
    num[i] += input[i][col];

    currSum += num[i];

    if(num[i] > currSum) {
      currSum = num[i];
      start = i;
    }
    
    if(currSum > maxSum) {
      maxSum = currSum;
      end = i;
    }
  }

  if(maxSum > ans) {
    ans = maxSum;
    pos.first = start;
    pos.second = end;
    return true;
  }
  return false;
}

for(int left = 0; left < cols; ++left) {
    auto sum = vector<int>(rows, 0);

    for(int right = left; right < cols; ++right) {
      if(kadane(sum, rows, right, topBotPos)) {
        leftRightPos.first = left;
        leftRightPos.second = right;
      }
    }
  }
*/


