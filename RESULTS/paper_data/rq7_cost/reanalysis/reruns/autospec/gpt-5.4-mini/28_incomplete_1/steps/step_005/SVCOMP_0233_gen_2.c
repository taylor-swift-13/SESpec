/*@
    requires args_len >= 0;
    requires args_len == 0 || \valid_read(args + (0 .. args_len - 1));
    ensures \result == (args != \null);
    assigns \nothing;
*/
int f(const char **args, int args_len);

void main(const char **args, int args_len);

/*@
    requires args_len >= 0;
    requires args_len == 0 || \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
*/
int f(const char **args, int args_len) {
    return args != 0;
}

void main(const char **args, int args_len) {
    f(args, args_len);
}