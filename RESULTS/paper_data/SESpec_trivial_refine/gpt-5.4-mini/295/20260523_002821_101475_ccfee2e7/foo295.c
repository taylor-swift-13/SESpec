
/*@
*/

/*
 */

/*@
  logic integer foo295_fib(integer n) =
    n == 0 ? 2 :
    n == 1 ? 1 :
    foo295_fib(n - 1) + foo295_fib(n - 2);
*/
/*@
  requires 1 <= num;
  requires num <= 2147483646;
  assigns \nothing;
  ensures foo295_fib(num) == \result;
  ensures \result >= 1;
  ensures num == 1 ==> \result == 1;
  ensures num > 1 ==> \result == foo295_fib(num - 1) + foo295_fib(num - 2);
  ensures \result == \old(foo295_fib(num));
  ensures \result == PLACE_HOLDER_RESULT;
*/
int foo295(int num) {

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns l, result[2 .. num];
          loop invariant 2 <= l <= num + 1;
          loop invariant result[0] == 2;
          loop invariant result[1] == 1;
          loop invariant \forall integer i; 2 <= i < l ==> result[i] == result[i - 1] + result[i - 2];
            */
            for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
            
		return result[num];
}
