
/*@ logic integer sum_digits(integer n) =
      n < 10 ? n : (n % 10) + sum_digits(n / 10); */
/*@ logic integer digital_root(integer n) =
      n < 10 ? n : digital_root(sum_digits(n)); */
/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result == digital_root(\old(num));
  ensures 0 <= \result <= 9;
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
