
/*@ 
  requires k >= 0;
*/

void foo49(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n;
          loop invariant n <= 2 * k;
          loop invariant b == 0 || b == 1;
          loop invariant (b == 1) <==> (n % 2 == 0);
          loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n;
          loop invariant i == \at(i,Pre) + (n + 1) / 2;
          loop invariant j == \at(j,Pre) + n / 2;
          loop invariant i >= \at(i,Pre);
          loop invariant j >= \at(j,Pre);
          loop invariant (n % 2 == 0) ==> (i - \at(i,Pre) == j - \at(j,Pre));
          loop invariant (n % 2 == 1) ==> (i - \at(i,Pre) == (j - \at(j,Pre)) + 1);
          loop invariant (n == 0) ==> (b == 1 && i == \at(i,Pre) && j == \at(j,Pre));
          loop invariant (n == 2 * k) ==> (b == ( (2 * k) % 2 == 0 ? 1 : 0 ));
          loop invariant (n >= 1) ==> ( (b == 0 && i == \at(i,Pre) + (n + 1)/2 && j == \at(j,Pre) + n/2)
                                      || (b == 1 && i == \at(i,Pre) + n/2 && j == \at(j,Pre) + n/2) );

          loop invariant (0 < (2 * \at(k,Pre))) ==> (i + j == \at(i,Pre) + \at(j,Pre) + n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> ( (0 <= i - \at(i,Pre)) && (i - \at(i,Pre) == (n + 1) / 2) );
          loop invariant (0 < (2 * \at(k,Pre))) ==> ( (0 <= j - \at(j,Pre)) && (j - \at(j,Pre) == n / 2) );
          loop invariant (0 < (2 * \at(k,Pre))) ==> ( 0 <= n && n <= 2 * \at(k,Pre) );
          loop invariant (0 < (2 * \at(k,Pre))) ==> (((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || (b == 0 || b == 1));
          loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
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
