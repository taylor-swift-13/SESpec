
/*@
  // Helper logic to count even and odd numbers in [0, l)
  logic integer evens_upto(integer l) = (l + 1) / 2;
  logic integer odds_upto(integer l)  = l / 2;
*/

/*@
  requires \true;
*/
void foo301(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int l;

    i = 0;
    j = 0;
    l = 0;

    /*@
      loop invariant 0 <= l <= n;
      loop invariant i + j == l;
      loop invariant i == evens_upto((integer)l);
      loop invariant j == odds_upto((integer)l);
      loop invariant (0 < \at(n,Pre)) ==> (i + j == l);
      loop invariant (0 < \at(n,Pre)) ==> (j == odds_upto((integer)l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (i == evens_upto((integer)l)) ;
      loop invariant (0 < \at(n,Pre)) ==> (l <= n) ;
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, j, l;
    */
    while (l < n) {
        if ((l % 2) == 0) {
            i = i + 1;
        }
        else{
            j = j + 1;
        }
        l = l + 1;
    }

}
