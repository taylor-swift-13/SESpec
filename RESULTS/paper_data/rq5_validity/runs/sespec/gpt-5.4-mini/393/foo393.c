
/*@
logic integer fact(integer n) = n <= 0 ? 1 : n * fact(n - 1);
*/

/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures -99 <= \result && \result < 100 ;
  ensures num == 0 ==> \result == 1;
*/
int foo393(int num) {

		int ret = 1;
		
        /*@
          loop invariant 1 <= loop <= num + 1;
          loop invariant ret == fact(loop - 1);
          loop assigns loop, ret;
        */
        for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
            
		int remainder = (int) (ret % 100);
		return remainder;
}
