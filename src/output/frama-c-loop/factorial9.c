
/*@
  logic integer factorial(integer x) =
    x <= 1 ? 1 : x * factorial(x - 1);
*/

/*@
  assigns \nothing;
  ensures
    (n < 1 ==> \result == 1) &&
    (1 <= n ==> \result == factorial(n));
*/
int factorial9(int n) {

  int i = 1;
  int f = 1;

  /*@
    loop invariant (1 <= \at(n,Pre)) ==> (1 <= i <= n + 1);
    loop invariant (1 <= \at(n,Pre)) ==> (f == factorial(i - 1));
    loop invariant !(1 <= \at(n,Pre)) ==> ((f == 1) && (i == 1) && (n == \at(n,Pre)));
    loop invariant n == \at(n,Pre);
    assigns i, f;
    ensures
      (n < 1 ==> (i == 1 && f == 1)) &&
      (1 <= n ==> (i == n + 1 && f == factorial(n)));
  */
  while (i <= n)  {
    f = f * i;
    i = i + 1;
  }

  return f;
}
