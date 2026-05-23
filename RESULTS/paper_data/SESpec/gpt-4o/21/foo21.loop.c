
/*@
  logic integer count_starts_with_te(const char **args, integer lo, integer hi) =
    (lo >= hi) ? 0
               : count_starts_with_te(args, lo, hi - 1) + (starts_with_te(args[hi - 1]) ? 1 : 0);
*/

/*@
  requires \valid(s);
  assigns \nothing;   
*/
int starts_with_te(const char *s);

/*@
  requires \valid(s);
  assigns \nothing;
  ensures \result == 1 ==> (s[0] == 't' && s[1] == 'e');
  ensures \result == 0 ==> (s[0] != 't' || s[1] != 'e');
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}

/*@
  requires \valid(args) && args_len >= 0;
  assigns \nothing;
*/
int foo21(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;

    /*@
      loop invariant 0 <= j <= 4;
      loop invariant 0 <= i <= j;
      loop invariant i == count_starts_with_te(args, 0, j);
      loop invariant \forall integer k; 0 <= k < j ==> \valid(args[k]);
      loop invariant \forall integer k; 0 <= k < j ==> args[k] == \at(args[k], Pre);
      loop assigns i;
    */
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }

    return i == 1;
}
