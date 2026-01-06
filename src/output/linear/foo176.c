
/*@
    requires k > 0 && k < 20000001 && i == j;
    */
    
void foo176(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < (2 * \at(k,Pre))) ==> (i == \at(i,Pre) + (n + 1) / 2);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (j == \at(j,Pre) + n / 2);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (n >= 0 && n <= 2 * \at(k,Pre));
          loop invariant (0 < (2 * \at(k,Pre))) ==> (((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || (b == 1 && n % 2 == 0) || (b == 0 && n % 2 == 1));
          loop invariant !(0 < (2 * \at(k,Pre))) ==> ((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
          loop invariant k == \at(k,Pre);
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
            

    /*@ assert (n >= (2 * k) ==> (i == j)); */

  }
