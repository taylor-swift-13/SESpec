
/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
*/

/*@
  requires k >= 0;
  requires i >= 0;
  requires j >= 0;
*/
void foo50(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    /*@
      loop invariant 0 <= n <= 2 * k;
      loop invariant k == \at(k,Pre);
      loop invariant 0 <= i;
      loop invariant 0 <= j;
      loop invariant 0 <= b && b <= 1;
      loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n;
      loop invariant (n % 2 == 0) ==> (b == 0 && i == \at(i,Pre) + n/2 && j == \at(j,Pre) + n/2);
      loop invariant (n % 2 == 1) ==> (b == 1 && i == \at(i,Pre) + n/2 && j == \at(j,Pre) + n/2 + 1);
      loop invariant \forall integer t; 0 <= t <= n ==> (\exists integer ii, jj; ii + jj == \at(i,Pre) + \at(j,Pre) + t);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (i + j == \at(i,Pre) + \at(j,Pre) + n);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (i >= \at(i,Pre));
      loop invariant (0 < (2 * \at(k,Pre))) ==> (j >= \at(j,Pre));
      loop invariant (0 < (2 * \at(k,Pre))) ==> (n >= 0);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || (0 <= b && b <= 1));
      loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
      loop assigns n, b, i, j;
    */
    while(n < (2 * k)){
       n = n + 1;
       if(b == 1){
         b = 0;
         i = i + 1;
       }
       else{
         b = 1;
         j = j + 1;
       }
    }
}
