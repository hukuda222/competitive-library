ll binary_search(ll key) {
  ll left = -1;
  ll right = (ll)a.size();

  while (right - left > 1) {
    ll mid = left + (right - left) / 2;

    if (isOK(mid, key))
      right = mid;
    else
      left = mid;
  }

  return right;
}
