class SVCOMP_linear_0052__145 {
    //@ ensures true;
static void foo145(int mid) {

int lo;
int hi;

lo = 0;
hi = 2 * mid;

 
    //@ maintaining lo + mid == \old(mid);
    //@ maintaining hi - mid == \old(mid);
    //@ decreases mid;
while(mid > 0){
lo = lo + 1;
hi = hi - 1;
mid = mid - 1;
}

}
}