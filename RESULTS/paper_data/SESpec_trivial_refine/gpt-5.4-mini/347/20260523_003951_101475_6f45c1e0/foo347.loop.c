
int foo347(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        
        /*@
          loop invariant y >= 0;
          loop invariant 1 <= i;
          loop invariant i <= y + 1;
          loop invariant 0 <= count;
          loop invariant count <= i - 1;
          loop assigns i, count;
        */
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
            
        return count;
}
