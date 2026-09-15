
/*@ predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION(int b, int n, int i, int j, int k) =
      (b == 1) && (n == 0) && (k == \at(k,Pre)) && (j == \at(j,Pre)) && (i == \at(i,Pre));
*/

void foo156(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    /*@
      loop invariant 0 <= n <= 2 * k;
      loop invariant k == \at(k,Pre);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (i == \at(i,Pre) + (n + 1) / 2);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (j == \at(j,Pre) + n / 2);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (n == 0 || n == 1 || n == 2 * k);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || (b == 0 || b == 1));
      loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
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
