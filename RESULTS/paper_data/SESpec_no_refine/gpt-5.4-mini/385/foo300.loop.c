
/*@
  // no additional predicates or logic functions needed
*/

int foo300(int n, int m) {

  /*@
    loop invariant (!(i >= 0)) ==> ((m == \at(m,Pre)) && (n == \at(n,Pre)));
    loop invariant m == \at(m,Pre);
    loop invariant n == \at(n,Pre);
    loop assigns i;
  */
  for (int i = n; i >= 0; i--) {
    if (i % m == 0) {
      return i;
    }
  }

  return -1;
}
