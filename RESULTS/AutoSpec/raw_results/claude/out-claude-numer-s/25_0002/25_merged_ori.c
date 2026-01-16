/*@
  requires n > 0;
*/
int hoo25(int n,int a) { 
    
    int i = 0;
    int sn = 0;

    /*@
    loop invariant sn == i * a;
    loop invariant i <= n;
    loop invariant 0 <= i;
    loop assigns sn;
    loop assigns i;
    /*@;
    */
    while(i < n) {
      sn = sn + a;
      i++;
    }
  
    /*@ assert sn == n*a || sn == 0; */
  }