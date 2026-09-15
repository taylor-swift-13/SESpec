int foo32(double i);


/*@
   requires \true;
   assigns \nothing;
   ensures \result == 0 || \result == 1; // The function only returns 0 or 1.
*/
int foo32(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}