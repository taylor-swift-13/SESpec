int fun(int input);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 1;
*/
int fun(int input) {
    char c = (char)(input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}
