
/*@ axiomatic Pow3 {
      logic integer pow3(integer n);

      axiom pow3_base:
        pow3(1) == 1;

      axiom pow3_step:
        \forall integer n; n > 1 && n % 3 == 0 ==> pow3(n) == pow3(n/3);

      axiom pow3_nonpow:
        \forall integer n; n <= 0 || (n > 1 && n % 3 != 0) ==> pow3(n) != 1;
  }
*/

/*@
  requires n >= 0;
  assigns \nothing;
  ensures \result == 1 <==> pow3(n) == 1;
  ensures \result == 0 <==> pow3(n) != 1;
  ensures 0 <= \result <= 1;
*/
int foo147(int n) {
    int temp = n;

    /*@
      loop invariant temp >= 0;
      loop invariant pow3(temp) == pow3(n);
      loop assigns temp;
      loop variant temp;
    */
    while (temp != 0 && temp % 3 == 0) {
        temp /= 3;
    }

    return temp == 1;
}
