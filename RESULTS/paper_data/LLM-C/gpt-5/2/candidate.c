int fibonacci(int n);

/*@ 
  logic integer Fib(integer n) = (n <= 0) ? 0 : (n == 1 ? 1 : Fib(n-1) + Fib(n-2));
*/

/*@ 
  requires n <= 46;
  ensures \result == Fib(n);
  ensures \result >= 0;
  assigns \nothing;
  decreases n >= 0 ? n : 0;
*/
int fibonacci(int n) {

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return fibonacci(n - 1) + fibonacci(n - 2);
        }
}
