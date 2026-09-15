
/*@ logic integer f(integer n, integer w); */

/*@ logic integer foo268_rec(integer n, integer w) =
      n == 0 ? 1 :
      n == 1 ? w :
      n == 2 ? w * w :
      ((w - 1) * (foo268_rec(n - 1, w) + foo268_rec(n - 2, w))) % 1000000007; */
/*@
  requires 0 <= count <= 2147483646;
  requires 1 <= w <= 46340;
  decreases count;
  assigns \result \from count, w;
  ensures count == 0 ==> \result == 1;
  ensures count == 1 ==> \result == w;
  ensures count == 2 ==> \result == w * w;
*/
int foo268(int count, int w)
{
  if (count == 0) {
    return 1;
  } else if (count == 1) {
    return w;
  } else if (count == 2) {
    return w * w;
  } else {
    long long t1 = foo268(count - 1, w);
    long long t2 = foo268(count - 2, w);
    long long tmp = (long long)(w - 1) * (t1 + t2);
    return (int)(tmp % 1000000007LL);
  }
}
