
/*@
  logic integer sum_evens(integer n) =
    n <= 0 ? 0 : sum_evens(n-1) + (n % 2 == 0 ? n : 0);
*/

/*@
  logic integer count_evens(integer n) =
    n <= 0 ? 0 : count_evens(n-1) + (n % 2 == 0 ? 1 : 0);
*/

/*@
  requires size >= 2;
  requires count_evens(size) > 0;
  assigns \nothing;
  ensures \result == sum_evens(size) / count_evens(size);
  ensures count_evens(size) > 0;
  ensures \result * count_evens(size) <= sum_evens(size) &&
          (\result + 1) * count_evens(size) > sum_evens(size);
  ensures size == \at(size,Pre);
*/
int foo363(int size) {

	int average = 0;
	int total = 0;
	
	/*@
	  loop invariant 1 <= c <= size + 1;
	  loop invariant 0 <= total;
	  loop invariant 0 <= average;
	  loop invariant average == sum_evens(c-1);
	  loop invariant total == count_evens(c-1);
	  loop invariant size == \at(size,Pre);
	  loop assigns c, average, total;
	*/
	for (int c = 1; c <= size; c++) {
		if (c % 2 == 0) {
			average += c;
			total++;
		}
	}
		
	return average / total;
}
