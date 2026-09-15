
/*@ 
  logic integer factorial(integer n) =
    n <= 1 ? 1 : n * factorial(n - 1);
*/

/*@
  requires \true;
  assigns \nothing;
  ensures \true;
*/

int foo149_c324(int number) {

	int first = 1;
	
    /*@
      loop invariant 2 <= c <= \at(number,Pre) + 1 || c == 2; 
      loop invariant (c <= \at(number,Pre)) ==> (first == factorial(c-1));
      loop invariant (c <= \at(number,Pre)) ==> (first > 0);
      loop invariant number == \at(number,Pre);
      loop assigns c, first;
    */
	for (int c = 2; c <= number; c++) {
		first *= c;
	}
		
	int result = 0;
	
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns result, first;
            */
            while (first > 0) {
		result = first % 10;
		first /= 10;
	}
            
	return result;
}
