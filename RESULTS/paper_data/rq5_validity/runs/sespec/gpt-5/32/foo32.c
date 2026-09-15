int foo32(double i);


/*@
  requires \is_finite(i);
  assigns \nothing;
  ensures (i == 0.0) ==> \result == 0;
  ensures (i != 0.0) ==> \result == 1;
  ensures \result == 0 || \result == 1;
*/
int foo32(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}