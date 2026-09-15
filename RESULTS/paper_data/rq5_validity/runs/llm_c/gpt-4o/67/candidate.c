/*@ 
    requires n >= 0;
    assigns \nothing;
    ensures \true;
*/
void foo300(int n) {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

    /*@
        loop invariant 0 <= i <= n + 3;
        loop invariant j >= 0 && k >= 0;
        loop invariant i % 3 == 0;
        loop invariant j + k == i;
        loop assigns i, j, k;
        loop variant n - i;
    */
    while(i < n){
       i = i + 3;
       if((i % 2) != 0)
           j = j + 3;
       else
           k = k + 3;
    }
}
