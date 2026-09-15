
/*@ 
  logic integer count_mod3eq0(integer m) =
    m <= 0 ? 0 : count_mod3eq0(m - 1) + (( (m - 1) % 3 == 0) ? 1 : 0);

  logic integer count_even_not3(integer m) =
    m <= 0 ? 0 : count_even_not3(m - 1) + 
                 ((( (m - 1) % 2 == 0) && ((m - 1) % 3 != 0)) ? 1 : 0);

  logic integer count_odd_not3(integer m) =
    m <= 0 ? 0 : count_odd_not3(m - 1) + 
                ((( (m - 1) % 2 != 0) && ((m - 1) % 3 != 0)) ? 1 : 0);
*/

/*@
  requires \true;
*/
void foo302_c69(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

    /*@
      loop invariant (0 < \at(n,Pre)) ==> (i + j + k == l);
      loop invariant (0 < \at(n,Pre)) ==> (j == count_even_not3(l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (i == count_mod3eq0(l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (k == count_odd_not3(l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i && 0 <= j && 0 <= k && 0 <= l && l <= n) ;
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
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
