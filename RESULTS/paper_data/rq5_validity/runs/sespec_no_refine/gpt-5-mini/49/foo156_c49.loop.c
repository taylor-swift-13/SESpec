
/*@ predicate even(integer x) = x % 2 == 0; */
/*@ predicate odd(integer x) = x % 2 != 0; */

void foo156_c49(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    
            
        /*@
          loop invariant (0 < (2 * \at(k,Pre))) ==> (n <= 2 * \at(k,Pre));
          loop invariant (0 < (2 * \at(k,Pre))) ==> (i >= \at(i,Pre));
          loop invariant (0 < (2 * \at(k,Pre))) ==> (j >= \at(j,Pre));
          loop invariant (0 < (2 * \at(k,Pre))) ==> (n >= 0);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || ( (0 <= n) && (i == \at(i,Pre) + (n+1)/2) && (j == \at(j,Pre) + n/2) && ( (b==1) <==> even(n) ) && (k == \at(k,Pre)) ));
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
