
/*@
  logic boolean te(char *s) = s[0] == 't' && s[1] == 'e';

  logic integer count_te(char **args, integer lo, integer hi) =
    lo >= hi ? 0
             : count_te(args, lo, hi - 1) + (te(args[hi - 1]) ? 1 : 0);
*/

/*@
  requires \valid(&s[0] + (0..100-1));
  requires \forall integer i; 0 <= i < 100 ==> 0 <= s[i] <= 100;
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
  requires \valid(&s[0] + (0..100-1));
  requires \forall integer i; 0 <= i < 100 ==> 0 <= s[i] <= 100;
  assigns \nothing;
  ensures \result == (s[0] == 't' && s[1] == 'e');
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}
int foo21(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= 4;
          loop invariant 0 <= i <= j;
          loop invariant i == count_te((char **)args, 0, j);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop assigns j, i;
            */
            for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
            
    return i == 1;
}
