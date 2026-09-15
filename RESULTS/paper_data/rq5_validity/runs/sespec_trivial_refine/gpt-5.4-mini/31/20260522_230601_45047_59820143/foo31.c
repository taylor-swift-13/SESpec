int foo31(int i);


/*@
  assigns \nothing;
  ensures i == 0 ==> \result == 0;
  ensures i != 0 ==> \result == 1;
  ensures \result == 0 <==> i == 0;
*/
int foo31(int i) {
    if (i == 0) return 0;
    int j = 10 / i;
    (void)j;
    return 1;
}