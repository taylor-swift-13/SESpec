int f(const char **args, int args_len);
/*@ assigns \nothing;
    ensures (\result != 0) <==> (args != \null);
    ensures 0 <= \result <= 1;
*/
int f(const char **args, int args_len) {
    return args != 0;
}

/*@ assigns \nothing;
    ensures \true;
*/
void main(const char **args, int args_len) {
    f(args, args_len);
}
