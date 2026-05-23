
void foo301(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int l;

    i = 0;
    j = 0;
    l = 0;

    
            
        /*@
          loop invariant (0 < \at(n,Pre)) ==> (j == l / 2);
          loop invariant (0 < \at(n,Pre)) ==> (i == (l + 1) / 2);
          loop invariant (0 < \at(n,Pre)) ==> (l <= n);
          loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns i, j, l;
        */
            while (l < n) {
       if ((l % 2) == 0) {
       i = i + 1;
      }
       else{
       j = j + 1;
      }
       l = l + 1;
      }
            

  }
