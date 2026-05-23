
/*@
  requires n >= 0;
  assigns \nothing;
  ensures \old(n) <= 1 ==> \result == 0;
  ensures \old(n) > 1 ==> \result > 0 && \old(n) % \result == 0;
*/
int foo346(int n) {
  if (n <= 1) {
    return 0;
  }
  return n;
}
