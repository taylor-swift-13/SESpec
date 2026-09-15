/*@
    requires args_len >= 0;
    requires \valid_read(args + (0..args_len-1));
    ensures \result == (args != \null);
    assigns \nothing;
*/
int f(const char **args, int args_len) {
    return args != 0;
}

/*@
    requires args_len >= 0;
    requires \valid_read(args + (0..args_len-1));
    assigns \nothing;
*/
void main(const char **args, int args_len) {
    f(args, args_len);
}
