int SimpleCalc(int x, int y)
{
  // write one line of code to return
  // (i) if y >=0, x^y (ii) otherwise reutrn x*y
  return y >= 0  ? [x, y]()->int { int res = 1; for(int i = 0; i < y; i++) res *= x; return res; }() : x*y;
}
