

/*@
  logic integer fib(integer n) =
    n <= 0 ? 0 : (n == 1 ? 1 : fib(n - 1) + fib(n - 2));
*/

/*@
  requires n >= 0;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
  decreases n;
*/
int foo2(int n);


int foo2(int n) {

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return foo2(n - 1) + foo2(n - 2);
        }
}