
/*@
*/

int foo102(int num) {

        while (num >= 10) 
        /*@ 
          loop invariant num >= 0;
          loop assigns num;
        */
        {
            int sum = 0;
            while (num > 0) 
            /*@ 
              loop invariant num >= 0;
              loop invariant sum >= 0;
              loop assigns num, sum;
            */
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
}
