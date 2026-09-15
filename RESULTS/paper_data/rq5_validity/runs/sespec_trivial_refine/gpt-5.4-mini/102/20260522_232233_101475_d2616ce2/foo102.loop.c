
/*@ */
        
int foo102(int num) {

        /*@
          loop invariant num >= 0;
          loop assigns num, sum;
        */
        while (num >= 10) {
            int sum = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant sum >= 0;
          loop invariant num >= 0;
          loop assigns num, sum;
            */
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            num = sum;
        }
            
        return num;
}
