
/*@ 
  predicate PLACE_HOLDER_VERFICATION_GOAL = \true; 
*/

/*@ 
  requires \true;
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
