
/*@
logic integer odd_sum(integer n) =
  n <= 0 ? 0 : odd_sum(n - 1) + ((n % 2) != 0 ? n : 0);

logic integer odd_count(integer n) =
  n <= 0 ? 0 : odd_count(n - 1) + ((n % 2) != 0 ? 1 : 0);
*/

int foo359(int size) {

	int ret = 0;
	int total = 0;
		
	/*@
	  loop invariant \true;
	  loop assigns c, ret, total;
	*/
	for (int c = 1; c <= size; c++) {
		if (c % 2 != 0) {
			ret += c;
			total++;
		}
	}
		
	return ret / total;
}
