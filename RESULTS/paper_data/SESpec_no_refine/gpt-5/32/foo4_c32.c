int foo4_c32(double i);


/*@
  assigns \nothing;
  ensures (i == 0.0) ==> (\result == 0);
*/
int foo4_c32(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}