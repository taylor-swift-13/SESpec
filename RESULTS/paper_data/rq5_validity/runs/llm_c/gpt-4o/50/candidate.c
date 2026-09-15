/*@
    requires k >= 0;
    assigns i, j;
    ensures i == \old(i) + k;
    ensures j == \old(j) + k;
*/
void foo181(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    /*@
        loop invariant 0 <= n <= 2 * k;
        loop invariant b == 0 || b == 1;
        loop invariant i == \old(i) + n / 2;
        loop invariant j == \old(j) + n / 2;
        loop assigns n, b, i, j;
        loop variant (2 * k) - n;
    */
    while(n < (2 * k)){
       n = n + 1;
       if(b == 1){
           b = 0;
           i = i + 1;
       }
       else{
           b = 1;
           j = j + 1;
       }
    }
}
