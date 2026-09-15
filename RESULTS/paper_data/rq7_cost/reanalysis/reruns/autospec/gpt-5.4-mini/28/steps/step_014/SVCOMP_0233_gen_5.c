/*@
    requires \valid_read(args) || args == \null;
    assigns \nothing;
    ensures \result == (args != \null);
*/
int f(const char **args, int args_len);

void main(const char **args, int args_len);

/*@
    requires \valid_read(args) || args == \null;
    assigns \nothing;
    ensures \result == (args != \null);
*/
int f(const char **args, int args_len) {
    return args != 0;
}

/*@
    requires \valid_read(args) || args == \null;
    assigns \nothing;
*/
void main(const char **args, int args_len) {
    f(args, args_len);
}
