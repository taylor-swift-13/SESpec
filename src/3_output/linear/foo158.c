
/*@
    requires m > 0;
    */
    
void foo158(int m) {

    int a;
    int j;

    a = 0;
    j = 1;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (1 <= \at(m,Pre)) ==> (-j + 1 <= a <= j - 1);
          loop invariant (1 <= \at(m,Pre)) ==> (1 <= j <= m + 1);
          loop invariant (!(1 <= \at(m,Pre))) ==> ((j == 1)&&(a == 0)&&(m == \at(m,Pre)));
          loop invariant m == \at(m,Pre);
          loop assigns a, j;
            */
            while(j <= m){
       if(unknown()){
       a = a + 1;
      }
       else{
       a = a - 1;
      }
       j = j + 1;
      }
            

    /*@ assert (j > m) ==> (a <= m); */

  }
