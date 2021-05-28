/*
int n, tree[MAXN];

int query(int x) {
  int s = 0;
  while(x > 0) {
    s += tree[x];
    x -= (x & -x);
  }
  return s;
}

ll rangeQuery(int l, int r) {
  return query(r) - query(l);
}

void update(int x, int v) {
  while(x < MAXN) {
    tree[x] += v;
    x += (x & -x);
  }
}
*/