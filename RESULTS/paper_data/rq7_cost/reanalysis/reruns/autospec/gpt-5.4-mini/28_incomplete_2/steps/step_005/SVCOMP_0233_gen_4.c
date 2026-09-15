/*@
    requires args == \null || \valid_read(args);
    assigns \nothing;
    ensures \result == (args != \null);
*/
int f(const char **args, int args_len);

void main(const char **args, int args_len);

/*@
    requires args == \null || \valid_read(args);
    assigns \nothing;
    ensures \result == (args != \null);
*/
int f(const char **args, int args_len) {
    return args != 0;
}

/*@
    requires args == \null || \valid_read(args);
    assigns \nothing;
*/
void main(const char **args, int args_len) {
    f(args, args_len);
}
