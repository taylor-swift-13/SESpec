int evenBitToggleNumber(int number);

/*@
    requires number >= 0;
    assigns \nothing;
    ensures \forall integer i; 0 <= i < 8 * sizeof(int) ==>
        ( ( (1 << i) <= number && i % 2 == 0) 
            ==> (((\result >> i) & 1) == 1 - (((number >> i) & 1))) )
        && ( !((1 << i) <= number && i % 2 == 0)
            ==> (((\result >> i) & 1) == (((number >> i) & 1))) );
*/
int evenBitToggleNumber(int number) {

		int result = 0;
		int ret = 0;
		int total = number;
		/*@
		    loop invariant total == number >> ret;
		    loop invariant ret >= 0;
		    loop invariant ret <= 8 * sizeof(int);
		    loop invariant \forall integer j; 0 <= j < ret && j < 8 * sizeof(int) ==>
		        ( (j % 2 == 0) ==> (((result >> j) & 1) == 1) )
		        && ( (j % 2 == 1) ==> (((result >> j) & 1) == 0) );
		    loop invariant \forall integer j; ret <= j && j < 8 * sizeof(int) ==> (((result >> j) & 1) == 0);
		    loop assigns ret, total, result;
		    loop variant total;
		*/
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ result;
}
