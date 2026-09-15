
/*@ 
  predicate PLACE_HOLDER_VERFICATION_GOAL = \true; 
*/

/*@ logic integer pow4(integer k) =
      k <= 0 ? 1 : 4 * pow4(k - 1); */
/*@ logic boolean is_pow4(integer n) =
      n == 1 ? \true :
      (n > 0 && n % 4 == 0) ? is_pow4(n / 4) : \false; */
/*@ 
  requires \true;
  assigns \nothing;
*/
int foo73(int n) {

    if(n <= 0) {
        return 0;
    }

    /*@
      loop invariant n >= 1;
      loop invariant (!(n % 4 == 0)) ==> (n >= 1);
      loop invariant (n % 4 == 0) ==> (PLACE_HOLDER_VERFICATION_GOAL);
      loop invariant (!(n % 4 == 0)) ==> (\true);
      loop assigns n;
    */
    while (n % 4 == 0) {
        n /= 4;
    }

    return n == 1;
}
