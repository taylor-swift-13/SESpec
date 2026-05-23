
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
void foo89(int k){

    int y=0;
    int x=0;
    int c=0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c == y;
          loop invariant 0 <= c;
          loop invariant 0 <= x;
          loop assigns c, y, x;
            */
            while(c < k){
     c = c + 1 ;
     y = y + 1;
     x=y*y*y*y*y+x;
    }
            

}
