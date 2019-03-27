ll right = 0;
for (ll left = 0; left < n; ++left) {
  while (right < n && (right を 1 個進めたときに条件を満たす)) {
    /* 実際に right を 1 進める */
    // ex: sum += a[right];
    ++right;
  }

  /* break した状態で right は条件を満たす最大なので、何かする */
  // ex: res += (right - left);

  /* left をインクリメントする準備 */
  // ex: if (right == left) ++right;
  // ex: else sum -= a[left];
}
