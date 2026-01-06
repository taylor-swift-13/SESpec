
/*@
  requires n <= 20000001;
  ensures \result == 0;
*/
int example_function(unsigned int n) {
  /*@
    loop invariant 0 <= i <= n;
    loop assigns i;
  */
  for (unsigned int i = 0; i < n; i++) {
    // Loop body
  }
  return 0;
}
