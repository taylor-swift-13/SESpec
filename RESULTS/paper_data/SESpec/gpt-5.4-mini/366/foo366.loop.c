
int foo366(int n) {

        int sum = 0;
        int count = 0;
        
        /*@
          loop invariant 1 <= i;
          loop invariant 0 <= count;
          loop invariant 0 <= sum;
          loop invariant count <= i / 2;
          loop invariant 2 * count <= i - 1;
          loop invariant i - 1 < 2 * (count + 1);
          loop invariant sum == count * (count + 1);
          loop invariant sum >= count;
          loop assigns i, sum, count;
        */
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
            
        return sum / count;
}
