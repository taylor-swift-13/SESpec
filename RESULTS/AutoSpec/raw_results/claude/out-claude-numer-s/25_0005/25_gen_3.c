/*@
  requires n > 0;
*/
int hoo25(int n,int a) { 
    
    int i = 0;
    int sn = 0;

    /*@
    */
    while(i < n) {
      sn = sn + a;
      i++;
    }
  
    /*@ assert sn == n*a || sn == 0; */
  }