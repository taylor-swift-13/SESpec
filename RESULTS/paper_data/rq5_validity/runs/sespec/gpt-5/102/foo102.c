
/*@
  ensures (\at(num,Pre) < 10) ==> (\result == \at(num,Pre));
  ensures (\at(num,Pre) >= 10) ==> (\result >= 0);
  ensures (\at(num,Pre) >= 10) ==> (\result < 10);
  ensures (\at(num,Pre) == 0) ==> (\result == 0);
  assigns \nothing;
*/
int foo102(int num) {

        /* >>> LOOP INVARIANT TO FILL <<< */

        /*@
          loop invariant (\at(num,Pre) < 10) ==> (num == \at(num,Pre));
          loop invariant (\at(num,Pre) >= 10) ==> (num >= 0);
          loop assigns num;
        */
        while (num >= 10) {
            int sum = 0;

            /* >>> LOOP INVARIANT TO FILL <<< */

            /*@
              loop invariant sum >= 0;
              loop invariant num >= 0;
              loop invariant (num > 0) ==> (num / 10 < num);
              loop invariant \forall integer t; t == 0 ==> (sum == sum);
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
