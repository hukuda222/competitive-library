// 交差判定 (x1,y1),(x2,y2)の線分と(x3,y3),(x4,y4)の線分
bool iscross(ll x1, ll x2, ll x3, ll x4, ll y1, ll y2, ll y3, ll y4) {
  ll ta = ((x3 - x4) * (y1 - y3)) + ((y3 - y4) * (x3 - x1));
  ll tb = ((x3 - x4) * (y2 - y3)) + ((y3 - y4) * (x3 - x2));
  ll tc = ((x1 - x2) * (y3 - y1)) + ((y1 - y2) * (x1 - x3));
  ll td = ((x1 - x2) * (y4 - y1)) + ((y1 - y2) * (x1 - x4));
  return tc * td < 0 && ta * tb < 0;
}
