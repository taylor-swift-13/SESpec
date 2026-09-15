

void foo49(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    /*@
      loop invariant 0 <= n;
      loop invariant n <= 2 * k || k < 0;
      loop invariant i == \at(i,Pre) + (n + 1) / 2;
      loop invariant j == \at(j,Pre) + n / 2;
      loop invariant k == \at(k,Pre);
      loop invariant b == 1 <==> n % 2 == 0;
      loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n;
      loop invariant n % 2 == 0 ==> b == 1;
      loop invariant n % 2 != 0 ==> b == 0;
      loop invariant \at(i,Pre) <= i;
      loop invariant \at(j,Pre) <= j;
      loop invariant 0 < (2 * \at(k,Pre)) ==> (i + j == \at(i,Pre) + \at(j,Pre) + n);
      loop invariant 0 < (2 * \at(k,Pre)) ==> (i == \at(i,Pre) + (n + 1) / 2);
      loop invariant 0 < (2 * \at(k,Pre)) ==> (j == \at(j,Pre) + n / 2);
      loop invariant 0 < (2 * \at(k,Pre)) ==> (0 <= n <= 2 * k || k < 0);
      loop invariant 0 < (2 * \at(k,Pre)) ==> ((n % 2 == 0 && b == 1) || (n % 2 != 0 && b == 0));
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
