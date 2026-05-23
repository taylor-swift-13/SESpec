
/*@
  requires k == \at(k, Pre);
  requires j == \at(j, Pre);
  requires i == \at(i, Pre);
  requires k >= 0; // Added to ensure 0 <= n <= 2 * k
  requires i + j == 0; // Added to ensure i + j == n on loop entry
*/
void foo49(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    /*@
      loop invariant 0 <= n <= 2 * k;
      loop invariant (b == 1 || b == 0);
      loop invariant i + j == n;
      loop invariant (n % 2 == 0) ==> (b == 1);
      loop invariant (n % 2 != 0) ==> (b == 0);
      loop invariant k == \at(k, Pre);
      loop invariant (0 < (2 * \at(k, Pre))) ==> (b == 1 || b == 0);
      loop invariant (0 < (2 * \at(k, Pre))) ==> (i >= \at(i, Pre));
      loop invariant (0 < (2 * \at(k, Pre))) ==> (j >= \at(j, Pre));
      loop invariant (0 < (2 * \at(k, Pre))) ==> (n >= 0);
      loop invariant (0 < (2 * \at(k, Pre))) ==> (((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || (b == 1 || b == 0));
      loop invariant (!(0 < (2 * \at(k, Pre)))) ==> ((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
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
