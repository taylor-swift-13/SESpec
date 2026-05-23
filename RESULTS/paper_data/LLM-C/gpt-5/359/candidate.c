int averageOdd(int size);

/*@ 
  requires 1 <= size;
  requires ((size + 1) / 2) <= 46340;
  assigns \nothing;
  ensures \result == (size + 1) / 2;
*/
int averageOdd(int size) {

		int ret = 0;
		int total = 0;
		/*@
		  loop invariant 1 <= c <= size + 1;
		  loop invariant 0 <= total <= c;
		  loop invariant total == c / 2;
		  loop invariant 0 <= ret;
		  loop invariant ret == (c / 2) * (c / 2);
		  loop assigns ret, total, c;
		  loop variant size - c + 1;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
		/*@ assert total > 0; */
		/*@ assert ret == total * total; */
		/*@ assert total == (size + 1) / 2; */
		return ret / total;
}
