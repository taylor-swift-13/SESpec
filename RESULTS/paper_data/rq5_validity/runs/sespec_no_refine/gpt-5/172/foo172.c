
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@
  requires ... ; same as input but kept there.
  assigns \nothing;
  ensures p <= 0 ==> \result == -1;
  ensures \result == (p <= 0 ? -1 : \result);
*/
int foo172(...) { ... }
