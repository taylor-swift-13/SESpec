
        /*@
        */
        

void foo56(int x) {

    unsigned int count;
    double exp;
    double term;
    double result;

    exp = 1;
    term = 1;
    count = 1;
    result = 2 * (1 / (1 - x));

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant count >= 1;
          loop assigns exp, term, count;
            */
            while(unknown()){
       term = term * (x / count) ;
       exp = exp + term ;
       count++ ;
      }
            

  }
