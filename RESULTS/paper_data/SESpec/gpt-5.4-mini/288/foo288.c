
/*@ logic integer fib2(integer n) =
      n <= 0 ? 0 :
      n == 1 ? 1 :
      fib2(n - 1) + 2 * fib2(n - 2);
*/

/*@ assigns \nothing; */
int foo288(int j) {

		int *ret = (int *)malloc(sizeof(int) * (j + 1));
int ret_len = j + 1;
		ret[0] = 0;
		ret[1] = 1;
		
            /*@
              loop invariant 2 <= p;
              loop invariant \forall integer k; 0 <= k < 2 ==> ret[k] == fib2(k);
              loop assigns p, ret[0..j];
            */
            for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
            
		return ret[j];
}
