
/*@
  logic integer odd_step(integer n) = n * 2 + 1;
*/

void foo242() {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 1;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= 1;
          loop invariant i % 2 == 1;
          loop invariant j >= 1;
          loop invariant a == (i - 1) / 2;
          loop assigns a, b, i, j;
            */
            while (unknown()) {
       a = a + 1;
       b = b + j - i;
       i = i + 2;
       if (i % 2 == 0){
       j = j + 2;
      }
       else{
       j = j + 1;
      }
      }
            

  }
