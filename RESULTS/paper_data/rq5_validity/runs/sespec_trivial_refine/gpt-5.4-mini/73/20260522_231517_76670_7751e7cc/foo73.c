
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

void foo73(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant 0 <= l <= n;
      loop invariant i <= l;
      loop invariant j <= l;
      loop invariant k <= l;
      loop invariant v1 <= l;
      loop invariant v2 <= l;
      loop invariant v3 <= l;
      loop invariant v4 <= l;
      loop invariant i + j + k + v1 + v2 + v3 + v4 == l;
      loop assigns i, j, k, l, v1, v2, v3, v4;
    */
    while (l < n) {
       if((l % 7) == 0){
         v1 = v1 + 1;
       }
       else if((l % 6) == 0){
         v2 = v2 + 1;
       }
       else if ((l % 5) == 0){
         v3 = v3 + 1;
       }
       else if ((l % 4) == 0) {
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
