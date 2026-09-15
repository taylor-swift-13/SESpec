/*@
    requires -1073741824 <= input <= 1073741823;
    ensures \result == 1;
    assigns \nothing;
*/
int fun(int input);

int fun(int input) {
    char c = (char)(input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}
