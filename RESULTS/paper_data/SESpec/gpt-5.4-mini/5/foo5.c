
/*@
  requires \true;
  decreases 101 - n;
  assigns \nothing;
  ensures (n > 100) ? (\result == n - 10) : (\result == 91);
*/
int foo5(int n);

int foo5(int n) {
    if (n > 100) return n - 10;
    else return foo5(foo5(n + 11));
}
