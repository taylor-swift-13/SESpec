/*@
    requires \true;
    ensures \result == (args != \null);
    assigns \nothing;
*/
int f(const char **args, int args_len);

/*@
    requires \true;
    assigns \nothing;
*/
void main(const char **args, int args_len);

int f(const char **args, int args_len) {
    return args != 0;
}

void main(const char **args, int args_len) {
    f(args, args_len);
}
