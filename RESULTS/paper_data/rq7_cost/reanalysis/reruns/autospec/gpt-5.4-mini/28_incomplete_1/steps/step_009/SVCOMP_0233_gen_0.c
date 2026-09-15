/*@
    requires args_len >= 0;
    assigns \nothing;
    ensures \result == (args != \null);
*/
int f(const char **args, int args_len);

void main(const char **args, int args_len);

/*@
    requires args_len >= 0;
    assigns \nothing;
    ensures \result == (args != \null);
*/
int f(const char **args, int args_len) {
    return args != 0;
}

/*@
    requires args_len >= 0;
    assigns \nothing;
*/
void main(const char **args, int args_len) {
    f(args, args_len);
}