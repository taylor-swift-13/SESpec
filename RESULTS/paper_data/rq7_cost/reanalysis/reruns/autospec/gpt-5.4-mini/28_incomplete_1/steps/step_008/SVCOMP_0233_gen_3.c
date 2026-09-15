/*@
    requires args != \null;
    assigns \nothing;
    ensures \result == 1;
*/
int f(const char **args, int args_len);

void main(const char **args, int args_len);

int f(const char **args, int args_len) {
    return args != 0;
}

void main(const char **args, int args_len) {
    f(args, args_len);
}