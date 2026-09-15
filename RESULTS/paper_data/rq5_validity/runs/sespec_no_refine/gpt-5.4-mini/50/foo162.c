
/*@
  logic integer abs_int(integer x) = x < 0 ? -x : x;
*/

void foo162(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    /*@
      loop invariant 0 <= b <= 1;
      loop invariant k == \at(k,Pre);
      loop invariant b == n % 2;
      loop invariant (0 < (2 * \at(k,Pre))) ==> (i >= \at(i,Pre));
      loop invariant (0 < (2 * \at(k,Pre))) ==> (j >= \at(j,Pre));
      loop invariant (0 < (2 * \at(k,Pre))) ==> (n >= 0);
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
