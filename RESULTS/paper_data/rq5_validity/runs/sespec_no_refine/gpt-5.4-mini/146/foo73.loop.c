
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo73(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /*@
          loop invariant n > 0;
          loop invariant n % 4 == 0;
        */
        
            /*@
          loop invariant (!(n % 4 == 0)) ==> ();
          loop assigns n;
            */
            while (n % 4 == 0) {
            n /= 4;
        }
            
        return n == 1;
}
