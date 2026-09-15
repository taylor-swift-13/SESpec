
/*@
  logic integer fibo(integer n) =
    n <= 0 ? 0 :
    n == 1 ? 1 :
    fibo(n - 1) + fibo(n - 2);
*/

int foo105(int n) {

		if(n < 0) return -1;
		else if(n == 0) return 0;

		int *fib = (int *)malloc(sizeof(int) * (n + 1));
int fib_len = n + 1;
		fib[0] = 0;
		fib[1] = 1;
		int index = 2;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= index <= fib_len;
          loop invariant (index < fib_len) ==> (fib[index - 1] == fibo(index - 1) && fib[index - 2] == fibo(index - 2));
          loop invariant (!(index < fib_len)) ==> (1 == 1);
          loop invariant \forall integer k; 0 <= k < index ==> fib[k] == fibo(k);
          loop assigns fib[0..fib_len-1], index;
            */
            while (index < fib_len) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}
            

		return fib[n];
}
