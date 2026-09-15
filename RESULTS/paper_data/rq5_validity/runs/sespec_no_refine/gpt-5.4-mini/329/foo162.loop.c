
/*@
  logic integer even(integer x) = x % 2 == 0;
*/

void foo162(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    /*@
      loop invariant 0 <= n <= 2 * k;
      loop invariant k == \at(k,Pre);
      loop invariant (b == 0 || b == 1);
      loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n / 2;
      loop invariant (n % 2 == 0) ==> (i == \at(i,Pre) + n / 2 && j == \at(j,Pre) + n / 2);
      loop invariant (n % 2 != 0) ==> (i == \at(i,Pre) + n / 2 && j == \at(j,Pre) + n / 2 + 1);
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
