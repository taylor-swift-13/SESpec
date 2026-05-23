
/*@
  requires 3 <= n <= 12;
  assigns \nothing;
  ensures \result > 0;
  ensures \forall integer k; 0 <= k < n ==> \result % (k + 1) == 0;
*/
int foo158(int n) {
  switch (n) {
    case 3:  return 6;
    case 4:  return 24;
    case 5:  return 120;
    case 6:  return 720;
    case 7:  return 5040;
    case 8:  return 40320;
    case 9:  return 362880;
    case 10: return 3628800;
    case 11: return 39916800;
    case 12: return 479001600;
    default: return 0;
  }
}
