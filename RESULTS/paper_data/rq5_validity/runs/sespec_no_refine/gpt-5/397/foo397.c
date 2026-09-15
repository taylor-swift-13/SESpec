
/*@ logic integer pow2(integer x) = x * x; */
/*@ logic integer pow4(integer x) = pow2(x) * pow2(x); */
/*@
  requires \true;
  assigns \nothing;
  ensures \result == \sum(integer k, 1, p, pow4(2*k));
  ensures p == \old(p);
*/
int foo397(int p) {

    int even = 0;

    /*@
      loop invariant 1 <= c <= p + 1;
      loop invariant p == \at(p,Pre);
      loop invariant even == \sum(integer k, 1, c - 1, (2*k)*(2*k)*(2*k)*(2*k));
      loop assigns c, tmp, even;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        even = even + (tmp * tmp * tmp * tmp);
    }

    return even;
}
