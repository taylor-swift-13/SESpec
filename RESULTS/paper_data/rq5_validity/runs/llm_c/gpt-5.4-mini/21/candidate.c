/*@
    requires \valid_read(s + (0..1));
    assigns \nothing;
    ensures \result == ((s[0] == 't') && (s[1] == 'e'));
*/
int starts_with_te(const char *s);
 /*@
    requires args_len >= 0;
    requires args_len >= 4 ==> \valid_read(args + (0..3));
    requires \forall integer i; 0 <= i < args_len ==> \valid_read(args[i] + (0..1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int f(const char **args, int args_len);

 /*@
    requires \valid_read(s + (0..1));
    assigns \nothing;
    ensures \result == ((s[0] == 't') && (s[1] == 'e'));
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}

 /*@
    requires args_len >= 0;
    requires args_len >= 4 ==> \valid_read(args + (0..3));
    requires \forall integer i; 0 <= i < args_len ==> \valid_read(args[i] + (0..1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int f(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    /*@
        loop invariant 0 <= j <= 4;
        loop invariant 0 <= i <= j;
        loop assigns j, i;
    */
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    return i == 1;
}
