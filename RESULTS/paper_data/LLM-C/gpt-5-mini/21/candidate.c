int starts_with_te(const char *s);
int f(const char **args, int args_len);

/*@
    requires \valid_read(s + (0..1));
    assigns \nothing;
    ensures \result == 1 <==> (s[0] == 't' && s[1] == 'e');
    ensures \result == 0 || \result == 1;
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}

/*@
    requires args != \null;
    behavior short_args:
        assumes args_len < 4;
        assigns \nothing;
        ensures \result == 0;
    behavior enough_args:
        assumes args_len >= 4;
        requires \valid(args + (0..3));
        requires \forall integer j; 0 <= j < 4 ==> \valid_read(args[j] + (0..1));
        assigns \nothing;
        ensures \result == 1 <==> (
            \exists integer j; 0 <= j < 4 &&
                args[j][0] == 't' && args[j][1] == 'e' &&
                (\forall integer k; 0 <= k < 4 && k != j ==> !(args[k][0] == 't' && args[k][1] == 'e'))
        );
        ensures \result == 0 || \result == 1;
    complete behaviors short_args, enough_args;
    disjoint behaviors short_args, enough_args;
*/
int f(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    /*@
        loop invariant 0 <= j <= 4;
        loop invariant 0 <= i <= j;
        loop assigns j, i;
        loop variant 4 - j;
    */
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    return i == 1;
}
