
/*@
  requires \valid_read(s + (0..1));
  assigns \nothing;
*/
int starts_with_te(const char *s);
int foo21(const char **args, int args_len);

/*@
  requires \valid_read(s + (0..1));
  assigns \nothing;
  ensures (\result == 0) || (\result == 1);
  ensures (\result == 1) <==> (s[0] == 't' && s[1] == 'e');
  ensures (s[0] != 't') ==> (\result == 0);
  ensures (s[0] == 't' && s[1] != 'e') ==> (\result == 0);
  ensures (s[0] == 't' && s[1] == 'e') ==> (\result == 1);
  ensures \result == ((s[0] == 't' && s[1] == 'e') ? 1 : 0);
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}

/*@
  requires args_len >= 4;
  requires \valid_read(args + (0..3));
  requires \forall integer k; 0 <= k < 4 ==> \valid_read(args[k] + (0..1));
  assigns \nothing;
*/
int foo21(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    
        /*@
          loop invariant 0 <= j <= 4;
          loop invariant 0 <= i <= j;
          loop invariant \forall integer k; 0 <= k < 4 ==> \valid_read(args[k] + (0..1));
          loop invariant \forall integer k; 0 <= k < 4 ==> args[k] == \at(args[k],Pre);
          loop invariant \forall integer k; 0 <= k < j ==> ((args[k][0] == 't' && args[k][1] == 'e') ==> (i >= 1));
          loop invariant \forall integer k; 0 <= k < j ==> (!(args[k][0] == 't' && args[k][1] == 'e') ==> (i >= 0));
          loop invariant (j < 4) ==> (0 <= j && j <= 3);
          loop invariant (!(j < 4)) ==> (j >= 4);
          loop assigns j, i;
        */
        for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
            
    return i == 1;
}
