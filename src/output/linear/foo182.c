
/*@
    requires n >= 0 && n <= 20000001 && k >= 0 && k <= 20000001;
    */
    
void foo182(int k, int n) {

    int i;
    int j;

    j = 0;
    i = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(n,Pre)) ==> (i == j && i <= n + 1) ;
          loop invariant (0 <= \at(n,Pre)) ==> (j == i && j <= n + 1) ;
          loop invariant (!(0 <= \at(n,Pre))) ==> ((j == 0)&&(i == 0)&&(n == \at(n,Pre))&&(k == \at(k,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant k == \at(k,Pre);
          loop assigns i, j;
            */
            while(i <= n){
       i = i + 1;
       j = j + 1;
      }
            

    /*@ assert (i > n) ==> (k + i + j) > (2 * n); */

  }
