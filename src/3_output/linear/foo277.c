
/*@
    requires n >= 0 && n <= 20000001;
    */
    
void foo277(int n) {

    int i;
    int k;

    i = 0;
    k = n;


    
            /*@
          loop invariant (0 < \at(n,Pre)) ==> (i == 2*(\at(n,Pre) - k));
          loop invariant (0 < \at(n,Pre)) ==> (k == \at(n,Pre) - i/2);
          loop invariant (0 < \at(n,Pre)) ==> (2*k >= n - 1);
          loop invariant (!(0 < \at(n,Pre))) ==> ((k == \at(n,Pre))&&(i == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns i, k;
            */
            while (i < n) {
       k--;
       i += 2;
      }
            

    /*@ assert 2 * k >= n - 1; */

  }
