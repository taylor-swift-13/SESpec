
/*@
  logic integer count_mod0(integer x) =
    x <= 0 ? 0 : count_mod0(x - 1) + (((x - 1) % 3 == 0) ? 1 : 0);
*/

/*@ 
  logic integer count_mod1(integer x) =
    x <= 0 ? 0 : count_mod1(x - 1) + ((((x - 1) % 3 != 0) && ((x - 1) % 2 != 0)) ? 1 : 0);
*/

/*@
  logic integer count_mod2(integer x) =
    x <= 0 ? 0 : count_mod2(x - 1) + ((((x - 1) % 3 != 0) && ((x - 1) % 2 == 0)) ? 1 : 0);
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
      loop invariant n == \at(n,Pre);
      loop invariant l <= n;
      loop invariant i == count_mod0(l);
      loop invariant j == count_mod2(l);
      loop invariant k == count_mod1(l);
      loop invariant i + j + k == l;
      loop invariant (0 < \at(n,Pre)) ==> (i + j + k == l);
      loop invariant (0 < \at(n,Pre)) ==> (j == count_mod2(l));
      loop invariant (0 < \at(n,Pre)) ==> (i == count_mod0(l));
      loop invariant (0 < \at(n,Pre)) ==> (k == count_mod1(l));
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
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
