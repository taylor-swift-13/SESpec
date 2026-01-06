
/*@
    requires n > 0;
    */
    
void foo55(int n,int v1,int v2,int v3) {

    int c = 0;

    
    /*@
      loop invariant v3 == \at(v3,Pre);
      loop invariant v2 == \at(v2,Pre);
      loop invariant v1 == \at(v1,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns c;
    */
    while (unknown()) {
        {
          if (unknown()) {
            if ( c > n )
            {
            c  = c + 1;
            }
          } else {
            if (c == n) 
            {
            c  = 1;
            }
          }
        }
    }
   
    /*@ assert ((c < 0)&& (c > n)) ==> (c == n); */
}
