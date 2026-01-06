
/*@
    requires n <= 50000001;
    */
    
void foo301(int n) {

    int i;
    int j;

    i = 0;
    j = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(n,Pre)) ==> (i % 3 == 0 && i >= 0);
          loop invariant (!(0 < \at(n,Pre))) ==> ((j == 0)&&(i == 0)&&(n == \at(n,Pre)));
          loop invariant j == 0;
          loop invariant n == \at(n,Pre);
          loop assigns i;
            */
            while(i < n){
       if(unknown())
       i = i + 6;
       else
       i = i + 3;
      }
            

    /*@ assert i % 3 == 0; */

  }
