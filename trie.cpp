/*
int trie[MAXN][SIGMA], terminal[MAXN], z;
vector<set<string>> passing(MAXN);

void build() {
  memset(trie[0], -1, sizeof trie[0]);
  memset(terminal, 0, sizeof terminal);
  z = 1;
}

int getId(char &c) {
  return c - 'a';
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
    passing[cur].insert(p);
    cur = trie[cur][id];
  }
  terminal[cur]++;
}

bool count(string &p) {
  int cur = 0;
  for(int i = 0; i < p.size(); ++i) {
    int id = getId(p[i]);
    if(trie[cur][id] == -1) return false;
    cur = trie[cur][id];
  }
  if(passing[cur].size()) {
    for(auto i: passing[cur]) cout << i << endl;
    return true;
  }
  return false;
}
*/