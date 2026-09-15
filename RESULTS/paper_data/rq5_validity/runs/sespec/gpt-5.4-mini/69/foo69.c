
/*@
  logic integer count_div3(integer x) =
    x <= 0 ? 0 : count_div3(x - 1) + (((x - 1) % 3) == 0 ? 1 : 0);

  logic integer count_div2not3(integer x) =
    x <= 0 ? 0 : count_div2not3(x - 1) + ((((x - 1) % 2) == 0 && ((x - 1) % 3) != 0) ? 1 : 0);

  logic integer count_other(integer x) =
    x <= 0 ? 0 : count_other(x - 1) + ((((x - 1) % 3) != 0 && ((x - 1) % 2) != 0) ? 1 : 0);
*/

void foo69(unsigned int n) {

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
      loop invariant 0 <= i;
      loop invariant 0 <= j;
      loop invariant 0 <= k;
      loop invariant i + j + k == l;
      loop invariant i == count_div3(l);
      loop invariant j == count_div2not3(l);
      loop invariant k == count_other(l);
      loop invariant l == i + j + k;
      loop invariant l <= n;
      loop invariant (0 < \at(n,Pre)) ==> (i + j + k == l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j && j <= n);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i && i <= n);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k && k <= n);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l && l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0) && (k == 0) && (i == 0) && (j == 0) && (n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, j, k, l;
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
