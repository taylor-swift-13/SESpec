
/*@
  requires \true;
  assigns \nothing;
  ensures num1 == 0 && num2 == 0 ==> \result == -1;
  ensures (num1 == 0) && (num2 != 0) ==> \result == ( (0 <= num2) ? num2 : -num2 );
  ensures (num2 == 0) && (num1 != 0) ==> \result == ( (0 <= num1) ? num1 : -num1 );
  ensures !( (0 <= \old(num1) ? \old(num1) : -\old(num1)) == 0 || (0 <= \old(num2) ? \old(num2) : -\old(num2)) == 0 )
          ==> \result >= 1;
  ensures !( (0 <= \old(num1) ? \old(num1) : -\old(num1)) == 0 || (0 <= \old(num2) ? \old(num2) : -\old(num2)) == 0 )
          ==>
          ( ( (0 <= \old(num1) ? \old(num1) : -\old(num1)) % \result == 0 ) &&
            ( (0 <= \old(num2) ? \old(num2) : -\old(num2)) % \result == 0 ) );
  ensures !( (0 <= \old(num1) ? \old(num1) : -\old(num1)) == 0 || (0 <= \old(num2) ? \old(num2) : -\old(num2)) == 0 )
          ==>
          (\forall integer d; 1 <= d <= ( (0 <= \old(num1) ? \old(num1) : -\old(num1)) ) && 1 <= d <= ( (0 <= \old(num2) ? \old(num2) : -\old(num2)) )
             ==> ( ( ( (0 <= \old(num1) ? \old(num1) : -\old(num1)) % d == 0 ) && ( (0 <= \old(num2) ? \old(num2) : -\old(num2)) % d == 0 ) ) ==> d <= \result ));
*/
int foo110(int num1, int num2) {

	int result = 1;
	num1 = (0 <= num1) ? num1 : -num1;
	num2 = (0 <= num2) ? num2 : -num2;

	if (num1 == 0 && num2 == 0) {
		return -1;
	}

	if (num1 == 0 || num2 == 0) {
		return (num1 > num2) ? num1 : num2;
	}

	/*@
	  loop invariant 1 <= i <= (num1 < num2 ? num1 : num2) + 1;
	  loop invariant 1 <= result;
	  loop invariant num1 % result == 0 && num2 % result == 0;
	  loop invariant \forall integer k; 1 <= k < i ==> ( (num1 % k == 0 && num2 % k == 0) ==> k <= result );
	  loop assigns i, result;
	*/
	for (int i = 1; i <= num1 && i <= num2; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			result = i;
		}
	}

	return result;
}
