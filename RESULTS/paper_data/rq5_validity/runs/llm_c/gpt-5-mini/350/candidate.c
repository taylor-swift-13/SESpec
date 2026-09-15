int evenBitToggleNumber(int num);

 /*@
     requires num >= 0;
     assigns \nothing;
     ensures \forall integer i; 0 <= i < (sizeof(int) * 8) ==>
         (
             ((num >> i) != 0 && (i % 2) == 0)
             ==> (((\result >> i) & 1) == 1 - ((num >> i) & 1))
         )
         &&
         (
             !((num >> i) != 0 && (i % 2) == 0)
             ==> (((\result >> i) & 1) == ((num >> i) & 1))
         );
 */
int evenBitToggleNumber(int num) {

		int result = 0;
		int ret = 0;
		int total = num;
		/*@
		    loop invariant 0 <= ret;
		    loop invariant total == (num >> ret);
		    loop invariant \forall integer j; 0 <= j < ret ==>
		        (
		            ((j % 2) == 0) ? (((result >> j) & 1) == 1) : (((result >> j) & 1) == 0)
		        );
		    loop invariant \forall integer j; ret <= j && j < (sizeof(int) * 8) ==> (((result >> j) & 1) == 0);
		    loop assigns result, ret, total;
		    loop variant total;
		*/
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return num ^ result;
}
