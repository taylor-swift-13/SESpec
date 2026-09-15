
#define MOD 1000000007LL

/*@ logic integer MODL = 1000000007; */

/*@ logic integer foo276_seq(integer n, integer k) =
      n == 0 ? 1 :
      n == 1 ? k :
      n == 2 ? (k * k) % MODL :
      ((k - 1) * (foo276_seq(n - 1, k) + foo276_seq(n - 2, k))) % MODL;
*/

/*@
  requires n >= 2;
  assigns \nothing;
  ensures \result == foo276_seq(n, k);
  ensures n == 2 ==> \result == (k * k) % MODL;
  ensures n == 3 ==> \result == ((k - 1) * (((k * k) % MODL) + k)) % MODL;
*/
int foo276(int n, int k) {
  long long a0 = 1;
  long long a1 = k;
  long long a2 = (a1 * a1) % MOD;

  /*@
    loop invariant 3 <= i <= n + 1;
    loop invariant a0 == foo276_seq(i - 3, k);
    loop invariant a1 == foo276_seq(i - 2, k);
    loop invariant a2 == foo276_seq(i - 1, k);
    loop assigns i, a0, a1, a2;
    loop variant n - i + 1;
  */
  for (int i = 3; i <= n; i++) {
    long long next = (((long long)(k - 1)) * (a2 + a1)) % MOD;
    a0 = a1;
    a1 = a2;
    a2 = next;
  }

  return (int)a2;
}
