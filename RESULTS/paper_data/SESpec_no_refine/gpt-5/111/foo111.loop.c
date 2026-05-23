
/*@
*/
        
int foo111(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= x_len;
          loop invariant \forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k];
          loop assigns index;
            */
            while (index < x_len) {
            if (x[index] != y[x_len - 1 - index]) {
                return 0;
            } else {
                index = index + 1;
            }
        }
            
        return 1;
}
