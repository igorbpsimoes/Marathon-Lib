
/*
**********BINARY TRIE***************
//MAXN is defined by total storage
#define MAXN 100000
//Sigma is the alphabet length
#define SIGMA 2

int trie[MAXN][SIGMA], z;

void build() {
  memset(trie, -1, sizeof trie);
  z = 1;
}

void insert(int num) {
  int cur = 0;
  for(int i = 31; i >= 0; --i) {
    int id = (num >> i) & 1;
    if(trie[cur][id] == -1) {
      trie[cur][id] = z; 
      ++z;
    }
    cur = trie[cur][id];
  }

**********OTHER IMPLEMENTATION***************
int trie[MAXN][SIGMA], terminal[MAXN], passing[MAXN], z;

void init() {
  memset(trie[0], -1, sizeof trie[0]);
  memset(terminal, 0, sizeof terminal);
  z = 1;
}

int getId(char &c) {
  return c - '0';
}

void insert(string &p) {
  int cur = 0;
  for(int i = 0; i < p.size(); ++i) {
    int id = getId(p[i]);
    if(trie[cur][id] == -1) {
      memset(trie[z], -1, sizeof trie[z]);
      trie[cur][id] = z; 
      ++z;
    }
    passing[cur]++;
    cur = trie[cur][id];
  }
  terminal[cur]++;
}

void remove(string &p, int cur, int idx) {
  if(idx < 30) {
    --passing[cur];
    
    int id = getId(p[idx]);
    remove(p, trie[cur][id], idx + 1);

    int next = trie[cur][id];
    if(terminal[next] == 0 && passing[next] == 0) {
      trie[cur][id] = -1;
    }
  } else {
    --terminal[cur];
  }
}

int count(string &p) {
  int cur = 0, ans = 0;
  for(int i = 0; i < p.size(); ++i) {
    int id = getId(p[i]);
    if(trie[cur][!id] != -1) {
      cur = trie[cur][!id];
      ans |= 1 << (29 - i);
      // cout << ans << endl;
    } else if(trie[cur][id] != -1) {
      cur = trie[cur][id];
    } else {
      return ans;
    }
  }
  return ans;
}

void getBinaryString(int toConv, string &ret) {
  ret = "000000000000000000000000000000";
  for(int j = 0; j < 30; ++j) {
    if((toConv >> j) & 1) ret[ret.size() - 1 - j] = '1';
  }
  // cout << ret << endl;
}
}*/
