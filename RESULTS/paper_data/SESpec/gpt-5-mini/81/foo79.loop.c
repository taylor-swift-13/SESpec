
#include <stddef.h>

int unknown(void);

/*@
  requires ( \true ); // Precondition described at call site in the problem text.
*/
void foo79(int y,int x1,int x2,int x3) {
  int c = 0;
  int z = 36 * y;

  /*@
      // Supplementary invariants capturing the loop semantics:
      // (a) z accumulates exactly c over the initial value 36 * \at(y,Pre).
      loop invariant z == 36 * \at(y,Pre) + c;
      // (b) c is bounded and monotone (non-negative and at most 36).
      loop invariant 0 <= c && c <= 36;
      // (c) if some value in the processed prefix contributed, existence is trivial here:
      //     there exists k with 0 <= k <= c such that z == 36 * \at(y,Pre) + k (witness k = c).
      loop invariant \exists integer k; 0 <= k && k == c && z == 36 * \at(y,Pre) + k;
      // (d) exit-implication: when the loop condition becomes false we still have the same relation,
      //     and in particular c <= 36 ensures the post-state bound.
      loop invariant z >= 36 * \at(y,Pre) && z <= 36 * \at(y,Pre) + 36;

      // Verification goal: the relation required by the precondition/post should hold:
      loop invariant (z - 36 * \at(y,Pre)) == c;
      // Named variable slots:
      loop invariant c >= 0 && c <= 36;
      loop invariant z == 36 * \at(y,Pre) + c;
      loop invariant x3 == \at(x3,Pre);
      loop invariant x2 == \at(x2,Pre);
      loop invariant x1 == \at(x1,Pre);
      loop invariant y == \at(y,Pre);
      loop assigns z, c;
  */
  while (unknown()) {
    if ( c < 36 )
    {
      z  = z + 1;
      c  = c + 1;
    }
  }
}
