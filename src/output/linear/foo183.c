
/*@
    requires x != y && t == y;
    */
    
void foo183(int t, int x, int y) {

    int i;

    i = 0;


    
            
        /* >>> LOOP INVARIANT FIXED <<< */        
            /*@
          loop invariant (\at(x,Pre) > 0) ==> (y >= t);
          loop invariant (!(\at(x,Pre) > 0)) ==> ((i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(t == \at(t,Pre)));
          loop invariant i == 0;
          loop invariant x == \at(x,Pre);
          loop invariant t == \at(t,Pre);
          loop assigns y;
            */
            while(x > 0){
       y = x + y;
      }
            

    /*@ assert y >= t; */

  }
