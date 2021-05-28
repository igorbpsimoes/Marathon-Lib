/*
********************HISTOGRAM********************
vector<ll> val(n);
    for(ll i = 0; i < n; ++i) {
      cin >> val[i];
    }
    vector<pii> idx(n);
    stack<pii> curHeight;
    // left to right
    for(ll i = 0; i < n; ++i) {
      while(!curHeight.empty()) {
        pii curTop = curHeight.top();
        if(curTop.f <= val[i]) break;

        idx[curTop.s].f = i;
        curHeight.pop();
      }

      curHeight.emplace(val[i], i);
    }
    while(!curHeight.empty()) {
      idx[curHeight.top().s].f = n;
      curHeight.pop();
    }
    // right to left
    for(ll i = n - 1; i >= 0; --i) {
      while(!curHeight.empty()) {
        pii curTop = curHeight.top();
        if(curTop.f <= val[i]) break;

        idx[curTop.s].s = i;
        curHeight.pop();
      }

      curHeight.emplace(val[i], i);
    }
    while(!curHeight.empty()) {
      idx[curHeight.top().s].s = -1;
      curHeight.pop();
    }

    ll ans = -inf, cur;
    for(ll i = 0; i < n; ++i) {
      // cout << idx[i].f << " " << idx[i].s << endl;
      cur = (idx[i].f - i)*val[i];
      cur += (i - idx[i].s)*val[i];
      cur -= val[i];
      // cout << cur << endl;
      ans = max(ans, cur);
    }
    cout << ans << endl;
*/
