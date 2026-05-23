
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

void foo78(int y) {
  int c = 0;
  int z = 36 * y;

  
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= 36;
          loop invariant z == 36 * y + c;
          loop assigns c, z;
            */
            while (unknown()) {

    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
    }
  }
            

}
