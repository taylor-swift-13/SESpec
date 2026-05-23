
void foo67(int n) {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

    /*@
      loop invariant 0 <= i;
      loop invariant i % 3 == 0;
      loop invariant 0 <= j;
      loop invariant 0 <= k;

      loop invariant (0 < \at(n,Pre)) ==> (i <= n + 2);
      loop invariant (0 < \at(n,Pre)) ==> (j % 3 == 0);
      loop invariant (0 < \at(n,Pre)) ==> (k % 3 == 0);

      loop invariant j + k == i;

      loop invariant i <= (n < 0 ? 0 : n + 2);
      loop invariant (j == 0) ==> (i % 2 == 0);
      loop invariant (0 < \at(n,Pre)) ==> ( (i == 0) || (i >= 3) );
      loop invariant (0 < \at(n,Pre)) ==> ( (i == 0) || ( (i - 3) >= 0 && ((i - 3) % 3 == 0) ) );

      loop invariant (0 < \at(n,Pre)) ==> (j + k == i);
      loop invariant (0 < \at(n,Pre)) ==> (j >= 0 && k >= 0);

      loop invariant (0 < \at(n,Pre)) ==> (i % 3 == 0);

      loop invariant (0 < \at(n,Pre)) ==> (i >= 0);
      loop invariant (0 < \at(n,Pre)) ==> (j >= 0);
      loop invariant (0 < \at(n,Pre)) ==> (k >= 0);

      loop invariant (0 < \at(n,Pre)) ==> ( (i == 0) ==> (j == 0 && k == 0) );

      loop invariant (!(0 < \at(n,Pre))) ==> ((j == 0)&&(k == 0)&&(i == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, j, k;
    */
    while(i < n){
       i = i + 3;
       if((i % 2) != 0)
         j = j + 3;
       else
         k = k + 3;
    }

}
