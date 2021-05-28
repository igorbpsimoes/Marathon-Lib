/*
int n, tree[4*MAXN];
vector<int> values;

void build(int p, int l, int r) {
  if(l == r) {
    tree[p] = values[l];
    return;
  }
  int m = (l + r)/2;
  build(2*p, l, m);
  build(2*p + 1, m + 1, r);

  //Do something
  tree[p] = tree[2*p] + tree[2*p + 1];
}

void update(int p, int l, int r, int pos, int newVal) {
  if(l == r) {
    tree[p] = newVal;
    return;
  }
  int m = (l + r)/2;
  if(pos <= m)
    update(2*p, l, m, pos, newVal);
  else
    update(2*p + 1, m + 1, r, pos, newVal);

  tree[p] = tree[2*p] + tree[2*p + 1];
}

int query(int p, int l, int r, int ql, int qr) {
  if(ql > qr) return 0;

  if(l == ql && r == qr) return tree[p];
  int m = (l + r)/2;
  return query(2*p, l, m, ql, min(m, qr)) +
         query(2*p + 1, m + 1, r, max(m + 1, ql), qr);
}

********************OTHER IMPLEMENT*****************
int n, tree[4*MAXN];
vector<int> values;

void build(int p, int l, int r) {
  if(l == r) {
    tree[p] = values[l];
    return;
  }
  int m = (l + r)/2, lc = 2*p, rc = lc+1;

  build(lc, l, m);
  build(rc, m + 1, r);

  tree[p] = tree[lc]*tree[rc];
}

void update(int p, int l, int r, int pos, int newVal) {
  if(l == r) {
    tree[p] = newVal;
    return;
  }
  int m = (l + r)/2, lc = 2*p, rc = lc+1;;
  if(pos <= m)
    update(lc, l, m, pos, newVal);
  else
    update(rc, m + 1, r, pos, newVal);

  tree[p] = tree[lc]*tree[rc];
}

int query(int p, int l, int r, int ql, int qr) {
  if(ql <= l && r <= qr) return tree[p];

  int m = (l + r)/2, lc = 2*p, rc = lc+1;

  if(qr <= m) {
    return query(lc, l, m, ql, qr);
  } else if(ql > m) {
    return query(rc, m + 1, r, ql, qr);
  } else {
    return query(lc, l, m, ql, qr)*query(rc, m + 1, r, ql, qr);
  }
}

************MAX SUBARRAY SUM FOR INTERVAL***********
ll ans, curRightMax;
ll sum[4*MAXN], maxx[4*MAXN], leftMaxx[4*MAXN], rightMaxx[4*MAXN];
vector<int> values;

void tmerge(int p, int lc, int rc) {
  sum[p] = sum[lc] + sum[rc];
  maxx[p] = max({maxx[lc], maxx[rc], rightMaxx[lc] + leftMaxx[rc]});
  leftMaxx[p] = max({leftMaxx[lc], sum[lc] + leftMaxx[rc]});
  rightMaxx[p] = max({rightMaxx[rc], sum[rc] + rightMaxx[lc]});
}

void build(int p, int l, int r) {
  if(l == r) {
    sum[p] = maxx[p] = leftMaxx[p] = rightMaxx[p] = values[l];
    return;
  }
  int m = (l + r)/2, lc = 2*p, rc = lc+1;
  build(lc, l, m);
  build(rc, m + 1, r);

  tmerge(p, lc, rc);
}

void update(int p, int l, int r, int pos, int newVal) {
  if(l == r) {
    sum[p] = maxx[p] = leftMaxx[p] = rightMaxx[p] = newVal;
    return;
  }

  int m = (l + r)/2, lc = 2*p, rc = lc+1;

  if(pos <= m) {
    update(lc, l, m, pos, newVal);
  } else {
    update(rc, m + 1, r, pos, newVal);
  }

  tmerge(p, lc, rc);
}

void query(int p, int l, int r, int ql, int qr) {
  if(l >= ql && r <= qr) {
    ans = max({ans, curRightMax + leftMaxx[p], maxx[p]});
    curRightMax = max(curRightMax + sum[p], rightMaxx[p]);
    return;
  }
  int m = (l + r)/2, lc = 2*p, rc = lc+1;

  if(qr <= m) {
    query(lc, l, m, ql, qr);
  } else if(ql > m) {
    query(rc, m + 1, r, ql, qr);
  } else {
    query(lc, l, m, ql, qr);
    query(rc, m + 1, r, ql, qr);
  }
}
*/