/*
MOD AND BASE FOR HASHIN
#define MOD 2147483647
#define BASE 27361

**************CONTINUE HASH***************
void continueHash(int start, string &p, int idx, int limit, vector<ll> &Hashing) {
  for(int i = idx; i < limit; ++i, ++start) {
    pot[start] = (pot[start-1]*(ll)base)%MOD;
    Hashing[start] = ((Hashing[start-1]*(ll)base) + (ll)p[i])%MOD;
  }
}

*************************IS PALINDROME******************************
int palindrome[MAXN][MAXN];
int ans[MAXN];
vector<ll> pot(MAXN), Hash(MAXN), revHash(MAXN);
int n;
 
void build(string &p) {
  pot[0] = 1;
  Hash[0] = p[0];
  revHash[0] = p[n - 1];
  for(int i = 1; i < n; ++i) {
    pot[i] = (pot[i-1]*base)%MOD;
    Hash[i] = ((Hash[i-1]*base) + p[i])%MOD;
    revHash[i] = ((revHash[i - 1]*base) + p[n - 1 - i])%MOD;
  }
}
 
ll getKey(int l, int r, vector<ll> &Hashing) {
  ll res = Hashing[r];
  if(l > 0) res = ((res - pot[r - l + 1] * Hashing[l-1])%MOD + MOD)%MOD;
  return res;
}

bool isPalindrome(int l, int r, string &p) {
  int m = (l + r);
  int firKey, secKey;
  if(m%2 == 0) {
    firKey = getKey(l, m/2, Hash);
    secKey = getKey(n - 1 - r, n - 1 - m/2, revHash);
  } else {
    firKey = getKey(l, m/2, Hash);
    secKey = getKey(n - 1 - r, n - 1 - (m/2 + 1), revHash);
  }
  return  firKey == secKey ;
}

int checkPalindrome(int l, int r, string &p) {
  if(palindrome[l][r] != -1) return palindrome[l][r];

  int m = (l + r), firRank, secRank;
  if(m%2 == 0) {
    firRank = checkPalindrome(l, m/2 - 1, p);
    secRank = checkPalindrome(m/2 + 1, r, p);
  } else {
    firRank = checkPalindrome(l, m/2, p);
    secRank = checkPalindrome(m/2 + 1, r, p);
  }

  palindrome[l][r] = 0;
  
  if(isPalindrome(l, r, p)) {
    palindrome[l][r] = min(firRank, secRank) + 1;
  }
  ans[palindrome[l][r]]++;
  return palindrome[l][r];
}

*****************************UNIQUE WORDS*********************************
#define MOD 1073676287
#define MOD2 2147483647
#define base 27361
#define base2 26227

vector<ll> pot(MAXN), Hash(MAXN);
vector<ll> secPot(MAXN), secHash(MAXN);
int n;

void build(string &p, vector<ll> &power, vector<ll> &Hashing, ll base, ll mod) {
  power[0] = 1;
  Hashing[0] = p[0];
  for(int i = 1; i < n; ++i) {
    power[i] = (power[i-1]*base)%mod;
    Hashing[i] = ((Hashing[i-1]*base) + p[i])%mod;
  }
}

ll getKey(int l, int r, vector<ll> &power, vector<ll> &Hashing, ll mod) {
  ll res = Hashing[r];
  if(l > 0) res = ((res - power[r - l + 1] * Hashing[l-1])%mod + mod)%mod;
  return res;
}

set<ll> unique;
set<ll> secUnique;
build(input, pot, Hash, BASE, MOD);
build(input, secPot, secHash, BASE2, MOD2);
--k;
ll ans = 0;
for(int i = 0; i + k < n; ++i) {
    bool firCol = true, secCol = true;
    ll firKey = getKey(i, i + k, pot, Hash, MOD), secKey = getKey(i, i + k, secPot, secHash, MOD2);
    if(unique.find(firKey) == end(unique)) {
    firCol = false;
    unique.insert(firKey);
    }
    if(secUnique.find(secKey) == end(secUnique)) {
    secCol = false;
    secUnique.insert(secKey);
    }
    if(!firCol || !secCol) {
    ans++;
    }
}
cout << ans << endl;
*/