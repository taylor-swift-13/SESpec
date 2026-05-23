class SVCOMP_linear_0052__145 {
//@ ensures (\old(mid) > 0 ==> mid == 0) && (\old(mid) <= 0 ==> mid == \old(mid));
static /*@ spec_public @*/ void foo145(int mid) {

int lo;
int hi;

lo = 0;
hi = 2 * mid;

//@ ghost int mid0 = mid;
//@ maintaining mid >= 0;
//@ maintaining lo + mid == mid0;
//@ maintaining hi == 2*mid + lo;
//@ maintaining hi >= lo;
//@ decreases mid;
while(mid > 0){
lo = lo + 1;
hi = hi - 1;
mid = mid - 1;
}

}
}