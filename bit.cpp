// これは与えられたインデックスまでの総和を出すやつ

template <typename T> struct BIT {
  vector<T> data;

  BIT(ll sz) { data.assign(++sz, 0); }

  T query(ll k) {
    T ret = 0;
    for (++k; k > 0; k -= k & -k)
      ret += data[k];
    return (ret);
  }

  void add(ll k, T x) {
    for (++k; k < data.size(); k += k & -k)
      data[k] += x;
  }
};

//これで転倒数がわかる
REP(j, a.size()) {
  ans += j - f_tree.query(a[j]);
  f_tree.add(a[j], 1);
}
