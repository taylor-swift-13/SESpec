
/*@ 
  predicate progressed(integer i0, integer j0, integer k0, integer i, integer j, integer n, integer b) =
    (i - i0) >= 0 && (j - j0) >= 0 && (i - i0) + (j - j0) == n &&
    (b == 0 || b == 1);
*/
        
void foo162_c50(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    
            
        /*@
          loop invariant (0 < (2 * \at(k,Pre))) ==> (progressed(\at(i,Pre), \at(j,Pre), \at(k,Pre), i, j, n, b));
          loop invariant (0 < (2 * \at(k,Pre))) ==> ( (i - \at(i,Pre)) >= 0 );
          loop invariant (0 < (2 * \at(k,Pre))) ==> ( (j - \at(j,Pre)) >= 0 );
          loop invariant (0 < (2 * \at(k,Pre))) ==> (  (i - \at(i,Pre)) + (j - \at(j,Pre)) == n );
          loop invariant (0 < (2 * \at(k,Pre))) ==> (((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || progressed(\at(i,Pre), \at(j,Pre), \at(k,Pre), i, j, n, b));
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
