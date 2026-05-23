
/*@ logic integer foo386_result(integer num, integer b, integer r) =
      r <= 0 ? 0 :
      (r == 1 ? (num * 10) / b : foo386_result((num * 10) % b, b, r - 1)); */
/*@
  requires b != 0;
  requires r >= 0;
  decreases r;
  assigns \nothing;
  ensures r == 0 ==> \result == 0;
  ensures r > 0 ==> \result == foo386_result(\at(num, Pre), b, r);
  ensures \result == foo386_result(\at(num, Pre), b, r);
*/
int foo386(int num, int b, int r)
{
  if (r <= 0) {
    return 0;
  }

  if (r == 1) {
    return (num * 10) / b;
  }

  return foo386((num * 10) % b, b, r - 1);
}
