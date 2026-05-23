
/*@
predicate is_te(char *s) = s[0] == 't' && s[1] == 'e';
*/

/*@ 
  requires \valid_read(s + (0..1));
  assigns \nothing;
  ensures \result == (s[0] == 't' && s[1] == 'e');
*/
int starts_with_te(const char *s);

/*@
  requires args_len < 4 || (\valid_read(args + (0 .. 3)) &&
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
                            (\forall integer k; 0 <= k < 4 ==> \valid_read(args[k] + (0 .. 1))));
*/
int foo21(const char **args, int args_len);

int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}
/*@
  requires args_len < 4 || (\valid_read(args + (0 .. 3)) &&
           (\forall integer k; 0 <= k < 4 ==> \valid_read(args[k] + (0 .. 1))));
  assigns \nothing;
  ensures args_len < 4 ==> \result == 0;
  ensures args_len >= 4 ==> (\result == 1 <==> (\exists integer k; 0 <= k < 4 && is_te((char *)args[k]) && (\forall integer m; 0 <= m < 4 && m != k ==> !is_te((char *)args[m]))));
  ensures args_len >= 4 ==> (\result == 0 <==> (\forall integer k; 0 <= k < 4 ==> !is_te((char *)args[k]) || (\exists integer m; 0 <= m < 4 && m != k && is_te((char *)args[m]))));
*/
int foo21(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= j <= 4;
      loop invariant 0 <= i <= j;
      loop invariant i == \numof integer k; 0 <= k < j && is_te((char *)args[k]);
      loop assigns i, j;
    */
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    
    return i == 1;
}
