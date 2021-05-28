/*
*********GCD**********
ll gcd(ll a, ll b) {
  while(b) a %= b, swap(a, b); // gcd(b, a%b)
  return a;
}


******FIND DIVISORS**********
void findDiv(int n, set<int> &ans, int mod) {
  for(int i = 1; i <= sqrt(n); ++i) {
    if(n%i == 0) {
      if(mod < i) ans.insert(i);
      if(n/i != i) if(mod < n/i) ans.insert(n/i);
    }
  }
}

*************LCM*******************
ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}

*********DIV SIEVE***********
vector<int> divSieve(LIMIT);

void countDiv(int lim) {
  for(int i = 1; i <= lim; ++i)
    for(int j = i; j <= lim; j += i)
      ++divSieve[j];
}

********PRIME SIEVE***********
bool sieve[MAXN];

void fastPrime(int lim, vector<int> &ans) {
  memset(sieve, 1, sizeof sieve);
  ans.pb(2);
  for(int i = 3; i < lim; i+=2) {
    if(sieve[i]) {
      ans.pb(i);
      if(i > lim/i) continue;
      for(int j = i*i; j < lim; j+= i+i) {
        sieve[j] = 0;
      }
    }
  }
}

********EULER TOTIENT***********
Definição: Quantidade de números k entre 1 e N tal que MDC(k,N) = 1

-------CALCULATES ONE PHI------------
int PHI(int n) {
  int ans = n;
  for(int i = 2; i*i <= n; ++i) {
    if(n%i == 0) {
      ans -= ans/i;
      while(n%i == 0) n /= i;
    }
  }
  if(n > 1) {
    ans -= ans/n;
  }
  return ans;
}
--------PHI SIEVE------------
ll PHI(int p, vector<int> &phi) {
  for(int i = 1; i <= p; ++i) phi[i] = i;
  ll sum = 1;

  for(int i = 2; i <= p; ++i) {
    if(phi[i] == i)
      for(int j = i; j <= p; j+=i)
        phi[j] = phi[j]/i*(i-1);
    sum += phi[i];
  }
  return sum;
}

********FEXP********
ll fExp(ll a, ll b) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}

*****MATRIX EXP******
const int m = 2;

struct Matrix {
  ll mat[m][m];

  Matrix operator * (const Matrix &p) {
    Matrix ans;
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < m; ++j)
        for(int k = ans.mat[i][j] = 0; k < m; ++k)
          ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
    return ans;
  }
};

Matrix fExp(Matrix a, ll b) {
  Matrix ans;
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < m; ++j)
      ans.mat[i][j] = i == j;

  while(b) {
    if(b & 1) ans = ans * a;
    a = a*a;
    b >>= 1;
    // for(int i = 0; i < m; ++i) {
    //   for(int j = 0; j < m; ++j) {
    //       cout << ans.mat[i][j] << " ";
    //   }
    //   cout << endl;
    // }
  }
  return ans;
}

Matrix mult;
mult.mat[0] = {a, 1, 0, 0, 0};
mult.mat[1] = {b, 0, 1, 0, 0};
mult.mat[2] = {c, 0, 0, 1, 0};
mult.mat[3] = {d, 0, 0, 0, 0};
mult.mat[4] = {e, 0, 0, 0, 1};

// cout << mult.mat[4][0] << endl;

Matrix temp;
temp.mat[0] = {3, 2, 1, 0, 1};

*********EQUAÇÃO DIOFANTINA LINEAR************
Encontre algum par de inteiros (X, Y), 
tal que A * X + B * Y = C, com A, B, C constantes.
For linear Diophantine equation equations, 
integral solutions exist if and only if, 
the GCD of coefficients of the two variables divides 
the constant term perfectly. 
In other words the integral solution exists if, GCD(a ,b) divides c.

ll gcd_ext(ll a, ll b, ll& x, ll& y) {
if (b == 0) {
 x = 1, y = 0;
 return a;
 }
 ll nx, ny;
 ll gc = gcd_ext(b, a % b, nx, ny);
 x = ny;
 y = nx - (a / b) * ny;
return gc;
}
*/