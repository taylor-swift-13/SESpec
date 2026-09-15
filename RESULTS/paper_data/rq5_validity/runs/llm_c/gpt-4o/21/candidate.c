/*@
    requires \valid_read(s+(0..1));
    ensures \result == 1 <==> (s[0] == 't' && s[1] == 'e');
    ensures \result == 0 <==> !(s[0] == 't' && s[1] == 'e');
    assigns \nothing;
*/
int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}

/*@
    requires args_len >= 0;
    requires args_len <==> \valid_read(args+(0..args_len-1));
    requires \forall integer i; 0 <= i < args_len ==> \valid_read(args[i]+(0..1));
    ensures \result == 0 || \result == 1;
    ensures args_len < 4 ==> \result == 0;
    ensures args_len >= 4 ==> \result == 1 <==> (\exists integer k; 0 <= k < 4 && starts_with_te(args[k]) &&
                                                (\forall integer l; 0 <= l < 4 && l != k ==> !starts_with_te(args[l])));
    assigns \nothing;
*/
int f(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    /*@
        loop invariant 0 <= j <= 4;
        loop invariant i >= 0 && i <= j;
        loop invariant i == \sum(0 <= k < j, starts_with_te(args[k]));
        loop assigns j, i;
        loop variant 4 - j;
    */
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    return i == 1;
}
