int unknown();
int hoo22(int a) { 
    
    //pre-condition
    int sn = 0;
    int x = 0;
  
    //loop-body
    /*@
    */
    while(unknown()) {
      if (x<10) {
          sn = sn + a;
          x++;
      }
    }
  
    //post-condition
    /*@ assert sn == x*a || sn == 0; */
  }   