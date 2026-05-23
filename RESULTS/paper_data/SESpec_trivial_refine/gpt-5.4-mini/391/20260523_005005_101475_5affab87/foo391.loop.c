
        /*@
        ensures \result > n;
        */
        
int foo391(int n) {

        int i = 1;
        int square = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (square == (i - 1) * (i - 1)) || (i == 1 && square == 1);
          loop invariant i >= 1;
          loop assigns i, square;
            */
            while (square <= n) {
            square = i*i;
            i++;
        }
            
        return square;
}
