
/* Simple function: remove factors of two */

/*@
  requires \true;
  assigns \nothing;
  ensures \old(n) <= 0 ==> \result == 0;
*/
int foo148(int n) {

    if(n <= 0) {
        return 0;
    }

    /*@
      loop invariant 1 <= n;
      loop invariant n % 2 == 0 || n % 2 == 1;
      loop invariant n == 1 || n/2 < n;
      loop invariant n % 2 == 0 ==> n >= 2;
      loop assigns n;
    */
    while (n % 2 == 0) {
        n /= 2;
    }

    return n == 1;
}
