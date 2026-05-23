
/*@
        predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
        */
        
void foo253(int k) {

    int n;
    int i;

    n = 0;
    i = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < 2 * \at(k,Pre)) ==> (0 <= i && i <= 2 * k);
          loop invariant (!(0 < 2 * \at(k,Pre))) ==> ((i == 0)&&(n == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns n, i;
            */
            while (i < 2 * k) {
       if(i % 2 == 0){
       n = n + 1;
      }
       i = i + 1;
      }
            

  }
