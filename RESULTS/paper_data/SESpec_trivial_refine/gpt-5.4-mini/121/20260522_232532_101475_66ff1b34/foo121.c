
/*@
  requires bits_len > 0;
  requires \valid(bits + (0 .. bits_len - 1));
  requires \forall integer k; 0 <= k < bits_len ==> bits[k] == 0;
  assigns \nothing;
  ensures 0 <= \result <= 1;
  ensures \result == 1;
  ensures \result == (bits_len > 0);
*/
int foo121(int * bits, int bits_len) {
  int n = bits_len, i = 0;

  /*@
    loop invariant 0 <= i <= n - 1;
    loop invariant \forall integer k; 0 <= k < i ==> bits[k] == 0;
    loop assigns i;
    loop variant n - 1 - i;
  */
  while (i < n - 1) {
    i += bits[i] + 1;
  }

  return i == n - 1;
}
