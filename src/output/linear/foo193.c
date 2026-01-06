
/*@
    requires i < n;
    */
    
void foo193(int i, int n) {

    int b;

    i = 0;


    
            /*@
          loop invariant 0 <= i <= n;
          loop invariant b != 0 ==> i < n;
          loop invariant n == \at(n,Pre);
          loop assigns i;
            */
            while(i < n && b != 0){
       i = i + 1;
      }
            

    /*@ assert (b == 0) ==> (i < n); */

  }
