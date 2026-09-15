
/*@ 
  logic integer abs_value(integer x) = x < 0 ? -x : x;
*/

/*@ 
  logic integer foo7_logic(integer n, integer m) =
    abs_value(m) == 0 ? 0 : n * abs_value(m);
*/

/*@
  requires m >= 0 || m <= 0; // Ensures m is a valid integer.
  requires n >= 0 || n <= 0; // Ensures n is a valid integer.
  decreases abs_value(m);    // Ensures termination of the recursion.
  assigns \nothing;          // No global or pointer variables are modified.
  ensures \result == foo7_logic(n, m); // Result matches the logic function.
  ensures \result == n * abs_value(m); // Result is the product of n and |m|.
*/
int foo7(int n, int m) {
    if (m < 0) {
        return foo7(n, -m);
    }
    if (m == 0) {
        return 0;
    }
    return n + foo7(n, m - 1);
}
