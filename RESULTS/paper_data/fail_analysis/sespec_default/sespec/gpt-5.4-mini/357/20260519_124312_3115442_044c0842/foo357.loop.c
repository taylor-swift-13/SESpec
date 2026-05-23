
int foo357(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count;
          loop invariant n == \at(n,Pre);
          loop assigns res, temp, count;
            */
            while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
            
        return (n | res);
}
