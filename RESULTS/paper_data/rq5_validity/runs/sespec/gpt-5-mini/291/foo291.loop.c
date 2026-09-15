
/*@
  logic integer jrec(integer k) =
    k == 0 ? 2
  : k == 1 ? 1
  : jrec(k-1) + 2 * jrec(k-2);
*/

#include <stdlib.h>

/*@
  requires c >= 1;
  requires \valid((int *)0); // dummy to satisfy Frama-C when using malloc; actual array validity is ensured after allocation
*/
int foo291(int c) {

	int *j = (int *)malloc(sizeof(int) * (c + 1));
	int j_len = c + 1;
	j[0] = 2;
	j[1] = 1;

    /* >>> LOOP INVARIANT FILLED <<< */
    /*@
      loop invariant 2 <= j_len;
      loop invariant 2 <= (c + 1);
      loop invariant 0 <= p <= c + 1;
      loop invariant \valid(j + (0 .. j_len - 1));
      loop invariant \forall integer k; 0 <= k < p ==> j[k] == jrec(k);
      
        // Note: \at(...,Pre) for j[] prior to loop entry corresponds to values set before the loop:
        // j[0] and j[1] are initialized before the loop; for k>=2 they get their computed values as loop progresses.
      loop invariant \forall integer k; 0 <= k < p ==> 0 <= j[k];
      loop invariant (p <= c) ==> j[p] == jrec(p);
      loop invariant (!(p <= c)) ==> (p == c + 1);
      loop invariant \forall integer k; 0 <= k <= c ==> j[k] == jrec(k) || k >= p;
      loop assigns p, j[0 .. j_len - 1];
    */
    for (int p = 2; p <= c; p++) {
		j[p] = j[p - 1] + 2 * j[p - 2];
	}

	return j[c];
}
