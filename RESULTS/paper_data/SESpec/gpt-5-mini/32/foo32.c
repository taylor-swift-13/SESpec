int foo32(double i);


/*@
  requires \true;
  assigns \nothing;
  ensures (i == 0.0) ==> (\result == 0);
  ensures \result == 1 ==> (i != 0.0);
*/
int foo32(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}