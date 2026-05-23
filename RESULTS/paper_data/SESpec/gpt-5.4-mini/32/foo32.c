int foo32(double i);


/*@
  requires i == 0.0;
  assigns \nothing;
  ensures \result == 0 ==> i == 0.0;
  ensures \result == 1 ==> i != 0.0;
  ensures \result == 0 || \result == 1;
*/
int foo32(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}