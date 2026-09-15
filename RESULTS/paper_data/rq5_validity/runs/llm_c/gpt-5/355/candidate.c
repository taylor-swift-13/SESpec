#include <limits.h>

int evenBitSetNumber(int num);

/*@ 
  assigns \nothing;
  ensures
    (num <= 0 ==> \result == num);
  ensures
    (num > 0 ==> \result >= num);
  ensures
    num > 0 ==> 
      \forall integer i; i >= 0 ==>
        (((\result >> i) & 1)
         ==
         ((((num >> i) & 1))
          | (((i % 2 == 1) && ((num >> i) != 0)) ? 1 : 0)));
*/
int evenBitSetNumber(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		/*@
		  loop invariant 0 <= result;
		  loop invariant sum == (num >> result);
		  loop invariant \forall integer i; 0 <= i < result ==> (((end >> i) & 1) == ((i % 2 == 1) ? 1 : 0));
		  loop invariant \forall integer i; i >= result ==> (((end >> i) & 1) == 0);
		  loop assigns result, end, sum;
		  loop variant sum;
		*/
		while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | end);
}
