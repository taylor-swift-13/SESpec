
/*@ 
  logic unsigned int count_mult6(unsigned int n) = n / 6;
  logic unsigned int count_mult5_not6(unsigned int n) = n / 5 - n / 30;
  logic unsigned int count_mult4_not5_not6(unsigned int n) = n / 4 - n / 20 - n / 12 + n / 60;
  logic unsigned int count_mult3_not4_not5_not6(unsigned int n) = n / 3 - n / 12 - n / 15 - n / 18 + n / 60;
  logic unsigned int count_mult2_not3_not4_not5_not6(unsigned int n) = n / 2 - n / 6 - n / 10 - n / 14 + n / 30;
  logic unsigned int count_other(unsigned int n) = n - count_mult6(n) - count_mult5_not6(n) - count_mult4_not5_not6(n) - count_mult3_not4_not5_not6(n) - count_mult2_not3_not4_not5_not6(n);
*/

void foo306(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(n,Pre)) ==> (j == count_other(l) && i == count_mult3_not4_not5_not6(l) && k == count_other(l) && v4 == count_mult4_not5_not6(l) && v3 == count_mult5_not6(l) && v2 == count_mult6(l) && l <= n) ;
          loop invariant (0 < \at(n,Pre)) ==> (i == count_mult3_not4_not5_not6(l)) ;
          loop invariant (0 < \at(n,Pre)) ==> (k == count_other(l)) ;
          loop invariant (0 < \at(n,Pre)) ==> (v4 == count_mult4_not5_not6(l)) ;
          loop invariant (0 < \at(n,Pre)) ==> (v3 == count_mult5_not6(l)) ;
          loop invariant (0 < \at(n,Pre)) ==> (v2 == count_mult6(l)) ;
          loop invariant (0 < \at(n,Pre)) ==> (l <= n) ;
          loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns v2, v3, v4, i, j, k, l;
            */
            while (l < n) {
       if((l % 6) == 0){
       v2 = v2 + 1;
      }
       else if ((l % 5) == 0){
       v3 = v3 + 1;
      }
       else if ((l % 4) == 0) {
       v4 = v4 + 1;
      }
       else if((l % 3) == 0){
       i = i + 1;
      }
       else if((l % 2) == 0){
       j = j + 1;
      }
       else{
       k = k + 1;
      }
       l = l + 1;
      }
            

  }
