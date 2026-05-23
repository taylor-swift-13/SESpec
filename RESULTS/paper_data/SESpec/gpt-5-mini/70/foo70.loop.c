
/* No extra predicate/logic function needed for this simple arithmetic reasoning. */

void foo70(unsigned int n) {

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

    /* Explanation: Weakened the previously too-strong equality to a bound that holds at entry.
       During the loop the sum of counters never exceeds the original n.
    */

    /*@
      loop invariant 0 <= l && l <= n;
      loop invariant 0 <= i && 0 <= j && 0 <= k && 0 <= v4;
      loop invariant i <= l && j <= l && k <= l && v4 <= l;
      loop invariant v4 + i + j + k == l;

      loop invariant 0 <= v4 && 0 <= i && 0 <= j && 0 <= k;

      loop invariant (l == n) ==> (v4 + i + j + k == \at(n,Pre) && n == \at(n,Pre));

      loop invariant (0 < \at(n,Pre)) ==> (v4 + i + j + k <= \at(n,Pre));

      loop invariant (0 < \at(n,Pre)) ==> (j <= \at(n,Pre) && 0 <= j);
      loop invariant (0 < \at(n,Pre)) ==> (i <= \at(n,Pre) && 0 <= i);
      loop invariant (0 < \at(n,Pre)) ==> (k <= \at(n,Pre) && 0 <= k);
      loop invariant (0 < \at(n,Pre)) ==> (v4 <= \at(n,Pre) && 0 <= v4);
      loop invariant (0 < \at(n,Pre)) ==> (l <= \at(n,Pre) && 0 <= l);

      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0) && (v4 == 0) && (k == 0) && (i == 0) && (j == 0) && (n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v4, i, j, k, l;
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
