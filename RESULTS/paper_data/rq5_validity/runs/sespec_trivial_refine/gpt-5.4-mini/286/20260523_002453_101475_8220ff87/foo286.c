
/*@
*/

/*@
*/

/*@ logic integer foo286_seq(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      foo286_seq(n - 1) + 2 * foo286_seq(n - 2);
*/
/*@
  requires j >= 1;
  assigns \nothing;
  ensures \result == foo286_seq(j);
  ensures j == 1 ==> \result == 1;
  ensures j >= 2 ==> \result == foo286_seq(j - 1) + 2 * foo286_seq(j - 2);
  ensures \result >= 0;
*/
int foo286(int j) {

		int *r = (int *)malloc(sizeof(int) * (j + 1));
int r_len = j + 1;
		r[0] = 0;
		r[1] = 1;
		
        /*@
          loop invariant r[0] == 0 && r[1] == 1;
          loop invariant 2 <= p <= j + 1;
          loop invariant \forall integer k; 2 <= k < p ==> r[k] == r[k - 1] + 2 * r[k - 2];
          loop assigns p, r[0 .. j];
        */
            for (int p = 2; p <= j; p++) {
			r[p] = r[p - 1]
					+ 2 * r[p - 2];
		}
            
		return r[j];
}
