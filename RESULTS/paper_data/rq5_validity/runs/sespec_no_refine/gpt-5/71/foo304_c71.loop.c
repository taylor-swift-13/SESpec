
/*@ 
  logic integer count_mod_5_eq_0(integer L) =
    L <= 0 ? 0 : count_mod_5_eq_0(L-1) + (( (L-1) % 5 == 0 ) ? 1 : 0);

  logic integer count_mod_4_eq_0_and_not_5(integer L) =
    L <= 0 ? 0 : count_mod_4_eq_0_and_not_5(L-1) +
                 (((L-1) % 4 == 0) && ((L-1) % 5 != 0) ? 1 : 0);

  logic integer count_mod_3_eq_0_and_not_4_or_5(integer L) =
    L <= 0 ? 0 : count_mod_3_eq_0_and_not_4_or_5(L-1) +
                 (((L-1) % 3 == 0) && ((L-1) % 4 != 0) && ((L-1) % 5 != 0) ? 1 : 0);

  logic integer count_mod_2_eq_0_and_not_3_4_5(integer L) =
    L <= 0 ? 0 : count_mod_2_eq_0_and_not_3_4_5(L-1) +
                 (((L-1) % 2 == 0) && ((L-1) % 3 != 0) && ((L-1) % 4 != 0) && ((L-1) % 5 != 0) ? 1 : 0);

  logic integer count_else_odd_or_not_div_2_3_4_5(integer L) =
    L <= 0 ? 0 : count_else_odd_or_not_div_2_3_4_5(L-1) +
                 ( (((L-1) % 5 != 0) && ((L-1) % 4 != 0) && ((L-1) % 3 != 0) && ((L-1) % 2 != 0)) ? 1 : 0);
*/

/*@
  requires \true;
*/
void foo304_c71(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;

    /*@
      loop invariant (0 < \at(n,Pre)) ==> (l <= n && 0 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (j == count_mod_2_eq_0_and_not_3_4_5(l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (i == count_mod_3_eq_0_and_not_4_or_5(l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (k == count_else_odd_or_not_div_2_3_4_5(l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (v4 == count_mod_4_eq_0_and_not_5(l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (v3 == count_mod_5_eq_0(l)) ;
      loop invariant (0 < \at(n,Pre)) ==> ( (integer)j + (integer)i + (integer)k + (integer)v4 + (integer)v3 == (integer)l ) ;
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v3, v4, i, j, k, l;
    */
    while (l < n) {
        if ((l % 5) == 0){
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
