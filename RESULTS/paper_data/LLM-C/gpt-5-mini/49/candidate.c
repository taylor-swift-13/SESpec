/*@
    requires k >= 0;
    assigns \nothing;
    ensures n == 2 * k;
    ensures b == 1;
    ensures i == \old(i) + k;
    ensures j == \old(j) + k;
*/
void foo176(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    /*@
        loop invariant 0 <= n <= 2 * k;
        loop invariant (n % 2 == 0) ==> b == 1;
        loop invariant (n % 2 == 1) ==> b == 0;
        loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n;
        loop assigns n, b, i, j;
        loop variant 2 * k - n;
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
