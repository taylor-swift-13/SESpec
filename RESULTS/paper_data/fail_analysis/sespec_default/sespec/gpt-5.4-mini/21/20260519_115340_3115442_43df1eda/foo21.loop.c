
/*@
  requires \valid_read(s + (0 .. 1));
  assigns \nothing;
*/
int starts_with_te(const char *s);
int foo21(const char **args, int args_len);

/*@
  requires \valid_read(s + (0 .. 1));
  assigns \nothing;
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}
int foo21(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    
    /*@
      
      loop invariant \forall integer k; i <= k < 4 ==> \true;
      loop invariant \forall integer k; 0 <= k < 4 ==> args[k] == \at(args[k], Pre);
      loop assigns i;
    */
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    
    return i == 1;
}
