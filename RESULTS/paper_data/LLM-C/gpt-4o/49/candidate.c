/*@ 
    requires k >= 0;
    assigns i, j;
    ensures i + j == \old(i) + \old(j) + 2 * k;
*/
void foo176(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    /*@
        loop invariant 0 <= n <= 2 * k;
        loop invariant i + j == \at(i, Pre) + \at(j, Pre) + n;
        loop invariant b == 0 || b == 1;
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
