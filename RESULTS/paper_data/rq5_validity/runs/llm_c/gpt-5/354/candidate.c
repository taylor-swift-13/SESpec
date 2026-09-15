int evenBitSetNumber(int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures (num <= 0) ==> (\result == num);
  ensures (num > 0) ==> (
    \forall integer i; i >= 0 ==> (
      (i % 2 == 0) ==> (((\result & (1 << i)) == (num & (1 << i))))
    )
  );
  ensures (num > 0) ==> (
    \forall integer i; i >= 0 ==> (
      ((i % 2 == 1) && ((num >> i) > 0)) ==> (((\result & (1 << i)) != 0))
    )
  );
  ensures (num > 0) ==> (
    \forall integer i; i >= 0 ==> (
      ((num >> i) == 0) ==> (((\result & (1 << i)) == 0))
    )
  );
*/
int evenBitSetNumber(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		/*@
		  loop invariant even >= 0;
		  loop invariant sum == (num >> even);
		  loop invariant \forall integer i; 0 <= i < even ==> (
		    ((i % 2 == 1) ==> ((result & (1 << i)) != 0)) &&
		    ((i % 2 == 0) ==> ((result & (1 << i)) == 0))
		  );
		  loop invariant \forall integer i; i >= even ==> ((result & (1 << i)) == 0);
		  loop assigns even, result, sum;
		  loop variant sum;
		*/
		while (sum > 0) {
			if (even % 2 == 1) {
				result |= (1 << even);
			}
			even++;
			sum >>= 1;
		}
		return (num | result);
}
