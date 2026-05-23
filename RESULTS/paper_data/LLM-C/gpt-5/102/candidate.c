/*@ 
  logic integer sum_digits(integer n) = n < 10 ? n : sum_digits(n/10) + n % 10;
  logic integer digit_root_logic(integer n) = n < 10 ? n : digit_root_logic(sum_digits(n));
*/

/*@ 
  requires num >= 0;
  assigns \nothing;
  ensures 0 <= \result <= 9;
  ensures \old(num) == 0 ==> \result == 0;
  ensures \old(num) > 0 ==> (\result >= 1 && (\result - \old(num)) % 9 == 0);
  ensures \result == digit_root_logic(\old(num));
*/
int digitRoot(int num);

int digitRoot(int num) {
        /*@ 
          loop invariant num >= 0;
          loop invariant num <= \at(num,Pre);
          loop invariant (\at(num,Pre) == 0) ==> (num == 0);
          loop invariant (\at(num,Pre) > 0) ==> (num > 0 && num % 9 == \at(num,Pre) % 9);
          loop assigns num;
          loop variant num;
        */
        while (num >= 10) {
            int sum = 0;
            /*@
              loop invariant num >= 0;
              loop invariant sum >= 0;
              loop assigns num, sum;
              loop variant num;
            */
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
}
