
/*@
logic integer odd_sum(integer l, integer r) = 0;
*/

int foo378(int l, int r) {

        int sum = 0;
        
        /*@
          loop invariant l <= i <= r + 1;
          loop invariant sum == \sum(integer k = l; k < i; (k % 2 != 0 ? k : 0));
          loop assigns i, sum;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
            
        return sum;
}
