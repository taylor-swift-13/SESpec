
/*@ logic integer pow4_even(integer k) = (2*k)*(2*k)*(2*k)*(2*k); */
/*@ logic integer sum_even_fourth(integer n) =
      n <= 0 ? 0 : sum_even_fourth(n-1) + pow4_even(n); */
/*@
  requires p >= 0;
  assigns \nothing;
  ensures (p <= 0) ==> (\result == 0);
  ensures (p >= 1) ==> (\result == sum_even_fourth(p));
  ensures \result >= 0;
  ensures p == 1 ==> \result == (2*1)*(2*1)*(2*1)*(2*1);
  ensures p == 2 ==> \result == (2*1)*(2*1)*(2*1)*(2*1) + (2*2)*(2*2)*(2*2)*(2*2);
*/
int foo396(int p) {

    int even = 0;

    /*@
      loop invariant 1 <= c <= p + 1;
      loop invariant even == sum_even_fourth(c-1);
      loop invariant even >= 0;
      loop invariant c == 1 ==> even == 0;
      loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
      loop invariant p == \at(p,Pre);
      loop assigns c, even;
      loop variant p - c + 1;
    */
    for (int c = 1; c <= p; c++) {
        int count = 2 * c;
        even = even + (count * count * count * count);
    }

    return even;
}
