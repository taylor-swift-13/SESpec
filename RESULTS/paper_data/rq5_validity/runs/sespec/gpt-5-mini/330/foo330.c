
/*@
  logic integer cubes_sum(integer n) = n <= 0 ? 0 : cubes_sum(n-1) + n*n*n;
*/

/*@
  logic integer sum_n(integer n) = n <= 0 ? 0 : sum_n(n-1) + n;
*/

/*@
  requires diff >= 0;
  assigns \nothing;   
*/
int foo330(int diff) {

	int result = 0;
	int max = 0;

	/*@
	  loop invariant 1 <= j <= diff + 1;
	  loop invariant 0 <= result;
	  loop invariant 0 <= j;
	  loop invariant 0 <= diff;
	  loop invariant result == cubes_sum(j-1);
	  loop invariant max == 0;
	  loop invariant diff == \at(diff,Pre);
	  loop assigns j, result;
	*/
	for (int j = 1; j <= diff; j++) {
		result += j * j * j;
	}

	/*@
	  loop invariant 1 <= j <= diff + 1;
	  loop invariant 0 <= max;
	  loop invariant 0 <= j;
	  loop invariant 0 <= diff;
	  loop invariant max == sum_n(j-1);
	  loop invariant \forall integer k; 1 <= k && k < j ==> sum_n(k) < sum_n(k+1);
	  loop invariant (j > 1) ==> (max >= (j-1));
	  loop invariant (j == diff + 1) ==> (max == sum_n(diff));
	  loop assigns j, max;
	*/
	for (int j = 1; j <= diff; j++) {
		max += j;
	}

	return result - max;
}
