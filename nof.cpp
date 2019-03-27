// 転倒数を求める

ll merge_cnt(vector<ll> &a) {
  ll n = a.size();
  if (n <= 1) {
    return 0;
  }

  ll cnt = 0;
  vl b(a.begin(), a.begin() + n / 2);
  vl c(a.begin() + n / 2, a.end());

  cnt += merge_cnt(b);
  cnt += merge_cnt(c);

  ll ai = 0, bi = 0, ci = 0;
  // merge の処理
  while (ai < n) {
    if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
      a[ai++] = b[bi++];
    } else {
      cnt += n / 2 - bi;
      a[ai++] = c[ci++];
    }
  }
  return cnt;
}
