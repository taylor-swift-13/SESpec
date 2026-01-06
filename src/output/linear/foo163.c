
/*@
    requires n > 0;
    */
    
void foo163(int n) {

    int b;
    int j;
    int flag;

    j = 0;
    b = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(n,Pre)) ==> (0 <= b <= n);
          loop invariant (0 < \at(n,Pre)) ==> ((flag == 1) ==> (j == b)) && ((flag != 1) ==> (j <= b));
          loop invariant (!(0 < \at(n,Pre))) ==> ((j == 0)&&(b == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns j, b;
            */
            while(b < n){
       if(flag == 1){
       j = j + 1;
       b = b + 1;
      }
       else if (flag != 1){
       b = b + 1;
      }
      }
            

    /*@ assert (flag == 1) ==> (j == n); */

  }
