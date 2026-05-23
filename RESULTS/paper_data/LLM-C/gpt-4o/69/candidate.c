/*@ 
    requires n >= 0;
    assigns \nothing;
    ensures \true;
*/
void foo307(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

    /*@
        loop invariant 0 <= l <= n;
        loop invariant i + j + k == l;
        loop invariant \forall integer x; 0 <= x < l ==> 
            ((x % 3 == 0) ==> i == (\sum integer y; 0 <= y < l && y % 3 == 0; 1)) &&
            ((x % 3 != 0 && x % 2 == 0) ==> j == (\sum integer y; 0 <= y < l && y % 3 != 0 && y % 2 == 0; 1)) &&
            ((x % 3 != 0 && x % 2 != 0) ==> k == (\sum integer y; 0 <= y < l && y % 3 != 0 && y % 2 != 0; 1));
        loop assigns i, j, k, l;
        loop variant n - l;
    */
    while (l < n) {
       if ((l % 3) == 0) {
           i = i + 1;
       }
       else if((l % 2) == 0){
           j = j + 1;
       }
       else{
           k = k + 1;
       }
       l = l + 1;
    }
}
