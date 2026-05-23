
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        
void foo86(int k){

    int y=0;
    int x=0;
    int c=0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant y == c;
          loop invariant c >= 0;
          loop invariant x == (c * (c + 1) * (2 * c + 1)) / 6;
          loop assigns c, y, x;
            */
            while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }
            

}
