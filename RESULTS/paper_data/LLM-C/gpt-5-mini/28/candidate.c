int f(const char **args, int args_len);
void main(const char **args, int args_len);

/*@
    assigns \nothing;
    ensures \result == (args != \null);
*/
int f(const char **args, int args_len) {
    return args != 0;
}

void main(const char **args, int args_len) {
    f(args, args_len);
}
