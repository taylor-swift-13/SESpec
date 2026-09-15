/*@ 
    requires n >= 0;
    assigns \nothing;
    ensures \true;
*/
void foo308(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;

    /*@
        loop invariant 0 <= l <= n;
        loop invariant i >= 0 && j >= 0 && k >= 0 && v4 >= 0;
        loop invariant v4 == \sum(0 <= x < l, (x % 4 == 0 ? 1 : 0));
        loop invariant i == \sum(0 <= x < l, (x % 4 != 0 && x % 3 == 0 ? 1 : 0));
        loop invariant j == \sum(0 <= x < l, (x % 4 != 0 && x % 3 != 0 && x % 2 == 0 ? 1 : 0));
        loop invariant k == \sum(0 <= x < l, (x % 4 != 0 && x % 3 != 0 && x % 2 != 0 ? 1 : 0));
        loop assigns l, v4, i, j, k;
        loop variant n - l;
    */
    while (l < n) {
       if ((l % 4) == 0) {
           v4 = v4 + 1;
       }
       else if((l % 3) == 0){
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
