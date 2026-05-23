
void foo50(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

            /*@
          loop invariant 0 <= n;
          loop invariant (b == 0) <==> (n % 2 == 0);
          loop invariant (b == 1) <==> (n % 2 == 1);
          loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n;
          loop invariant i == \at(i,Pre) + (n / 2);
          loop invariant j == \at(j,Pre) + ((n + 1) / 2);
          loop invariant (n % 2 == 0) ==> (b == 0 && i == \at(i,Pre) + n/2 && j == \at(j,Pre) + n/2);
          loop invariant (n % 2 == 1) ==> (b == 1 && i == \at(i,Pre) + n/2 && j == \at(j,Pre) + n/2 + 1);
          loop invariant n == 0 ==> (b == 0 && i == \at(i,Pre) && j == \at(j,Pre));
          loop invariant (n == 2 * k) ==> (i + j == \at(i,Pre) + \at(j,Pre) + 2 * k);

          loop invariant (0 < (2 * \at(k,Pre))) ==> (n <= 2 * \at(k,Pre));
          loop invariant (0 < (2 * \at(k,Pre))) ==> (0 <= i - \at(i,Pre) && i - \at(i,Pre) <= n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (0 <= j - \at(j,Pre) && j - \at(j,Pre) <= n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (0 <= n && n <= 2 * \at(k,Pre));
          loop invariant (0 < (2 * \at(k,Pre))) ==> (((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || (b == 0 || b == 1));
          loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
          loop invariant k == \at(k,Pre);
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
