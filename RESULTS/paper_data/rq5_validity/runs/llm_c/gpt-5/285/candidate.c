const char * countDivisors(int n);

/*@ logic integer divisor_count(integer n) =
      n <= 0 ? 0 : \sum(integer k, 1, n, ((n % k) == 0 ? 1 : 0));
*/

/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == "Even" || \result == "Odd";
  ensures (\result == "Even") <=> (divisor_count(n) % 2 == 0);
  ensures (\result == "Odd")  <=> (divisor_count(n) % 2 == 1);
*/
const char * countDivisors(int n) {

        int count = 0;
        /*@
          loop invariant n >= 1 ==> (1 <= i && i <= n+1);
          loop invariant n < 1 ==> i == 1;
          loop invariant 0 <= count;
          loop invariant count == \sum(integer k, 1, i-1, ((n % k) == 0 ? 1 : 0));
          loop assigns i, count;
          loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        //@ assert count == divisor_count(n);
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}
