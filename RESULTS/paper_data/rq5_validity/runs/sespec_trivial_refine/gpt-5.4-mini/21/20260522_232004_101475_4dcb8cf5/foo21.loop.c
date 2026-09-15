
/*@
predicate is_te(char *s) = s[0] == 't' && s[1] == 'e';
*/

/*@ 
  requires \valid_read(s + (0..1));
  assigns \nothing;
  ensures \result == (s[0] == 't' && s[1] == 'e');
*/
int starts_with_te(const char *s);

int foo21(const char **args, int args_len);

int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}
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
