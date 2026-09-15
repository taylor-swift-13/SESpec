/*@ 
    requires denom != 0;
    ensures \result == 1;
    assigns \nothing;
*/
int arithmeticException6(int denom);

/*@
    requires \true;
    ensures (denom == 0 ==> \result == 0) && (denom != 0 ==> \result == 1);
    assigns \nothing;
*/
int arithmeticException6(int denom) {
    if (denom == 0) return 0;
    int j = 10 / denom;
    (void)j;
    return 1;
}
