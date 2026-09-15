int evenPowerSum(int p);

/*@
  requires p >= 0;
  requires \sum(integer k, 1, p, (2*k)*(2*k)*(2*k)*(2*k)) <= 2147483647;
  assigns \nothing;
  ensures \result == \sum(integer k, 1, p, (2*k)*(2*k)*(2*k)*(2*k));
*/
int evenPowerSum(int p) {

		int even = 0;
		/*@
		  loop invariant 1 <= c <= p + 1;
		  loop invariant even == \sum(integer k, 1, c-1, (2*k)*(2*k)*(2*k)*(2*k));
		  loop invariant even <= \sum(integer k, 1, p, (2*k)*(2*k)*(2*k)*(2*k));
		  loop invariant even >= 0;
		  loop assigns even, c;
		  loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}
