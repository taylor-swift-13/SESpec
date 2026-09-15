
/*@ logic integer foo388_result(integer num, integer c, integer r) =
      r <= 0 ? 0 : (r == 1 ? (num * 10) / c : foo388_result(((num * 10) % c), c, r - 1)); */
/*@ logic integer foo388_rem(integer num, integer c, integer r) =
      r <= 0 ? num : (foo388_rem(num, c, r - 1) * 10) % c; */
/*@ 
  requires c != 0;
  assigns \result \from num, c, r;
*/
int foo388(int num, int c, int r) {

  int result = 0;

  /*@
    loop assigns r, num, result;
  */
  while (r > 0) {
    r -= 1;
    num *= 10;
    result = num / c;
    num %= c;
  }

  return result;
}
