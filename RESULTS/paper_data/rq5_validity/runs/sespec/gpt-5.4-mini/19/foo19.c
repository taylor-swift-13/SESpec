
/*@
  logic integer c_strlen{L}(char *s) =
    \at(*s, L) == 0 ? 0 : 1 + c_strlen{L}(s + 1);
*/

/*@
  requires \valid_read(s1 + (0 .. 24));
  requires (\forall integer i; 0 <= i < 24 ==> s1[i] != 0);
  requires s1[24] == 0;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int foo19(const char * s1) {

    return ((int)strlen(s1)) == 24;
}
