/*@ 
  requires \valid_read(s + (0..1));
  assigns \nothing;
  ensures \result <==> (s[0] == 't' && s[1] == 'e');
*/
int starts_with_te(const char *s);

/*@
  requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires args_len < 4 || (\forall integer k; 0 <= k < 4 ==> \valid_read(args[k] + (0..1)));
  assigns \nothing;
  ensures args_len < 4 ==> \result == 0;
  ensures args_len >= 4 ==> (\result <==> 
    ((starts_with_te(args[0])?1:0) + (starts_with_te(args[1])?1:0) +
     (starts_with_te(args[2])?1:0) + (starts_with_te(args[3])?1:0) == 1));
*/
int f(const char **args, int args_len);

/*@ 
  requires \valid_read(s + (0..1));
  assigns \nothing;
  ensures \result <==> (s[0] == 't' && s[1] == 'e');
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}

/*@
  requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires args_len < 4 || (\forall integer k; 0 <= k < 4 ==> \valid_read(args[k] + (0..1)));
  assigns \nothing;
  ensures args_len < 4 ==> \result == 0;
  ensures args_len >= 4 ==> (\result <==> 
    ((starts_with_te(args[0])?1:0) + (starts_with_te(args[1])?1:0) +
     (starts_with_te(args[2])?1:0) + (starts_with_te(args[3])?1:0) == 1));
*/
int f(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    /*@
      loop invariant 0 <= j <= 4;
      loop invariant 0 <= i <= j;
      loop invariant i ==
        ((starts_with_te(args[0])?1:0) +
         (j>=2 ? (starts_with_te(args[1])?1:0) : 0) +
         (j>=3 ? (starts_with_te(args[2])?1:0) : 0) +
         (j>=4 ? (starts_with_te(args[3])?1:0) : 0));
      loop assigns j, i;
      loop variant 4 - j;
    */
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    return i == 1;
}
