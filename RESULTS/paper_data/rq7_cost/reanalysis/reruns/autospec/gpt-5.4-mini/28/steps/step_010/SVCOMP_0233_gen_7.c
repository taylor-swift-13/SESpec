/*@ 
    requires args_len >= 0;
    ensures \result == (args != \null);
    assigns \nothing;
*/
int f(const char **args, int args_len);
void main(const char **args, int args_len);

/*@ 
    requires args_len >= 0;
    ensures \result == (args != \null);
    assigns \nothing;
*/
int f(const char **args, int args_len) {
    return args != 0;
}

void main(const char **args, int args_len) {
    f(args, args_len);
}