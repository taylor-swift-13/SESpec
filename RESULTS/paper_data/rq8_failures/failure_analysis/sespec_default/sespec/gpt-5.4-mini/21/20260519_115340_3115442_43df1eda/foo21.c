
/*@
  requires \valid_read(s + (0 .. 1));
  assigns \nothing;
*/
int starts_with_te(const char *s);

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo21(const char **args, int args_len);

/*@
  requires \valid_read(s + (0 .. 1));
  assigns \nothing;
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}
/*@
  requires \valid(args + (0 .. args_len - 1));
  requires \forall integer i; 0 <= i < args_len ==> \valid_read(args[i] + (0 .. 1));
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures args_len < 4 ==> \result == 0;
  ensures args_len >= 4 ==> \result == ((args[0][0] == 't' && args[0][1] == 'e' ? 1 : 0)
                                      + (args_len > 1 && args[1][0] == 't' && args[1][1] == 'e' ? 1 : 0)
                                      + (args_len > 2 && args[2][0] == 't' && args[2][1] == 'e' ? 1 : 0)
                                      + (args_len > 3 && args[3][0] == 't' && args[3][1] == 'e' ? 1 : 0) == 1);
*/
int foo21(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= 4;
      loop invariant \forall integer k; 0 <= k < 4 ==> args[k] == \at(args[k], Pre);
      loop assigns i;
    */
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    
    return i == 1;
}
