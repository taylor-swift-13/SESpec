int foo33(int denom);


/*@
  assigns \nothing;
  ensures denom == 0 ==> \result == 0;
  ensures denom != 0 ==> \result == 1;
  ensures \result == 0 || \result == 1;
*/
int foo33(int denom) {
    if (denom == 0) return 0;
    int j = 10 / denom;
    (void)j;
    return 1;
}