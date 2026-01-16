
/*@
requires \true;
ensures \result == x + y;
assigns \nothing;
*/
int add(int x, int y) {
    return x+y;
}

void moo2() {
    int a = add(1, 43);
    //@ assert a == 44;
    int b = add(997, 997);
}