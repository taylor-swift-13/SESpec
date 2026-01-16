/*@
requires \valid(a) && \valid(b);
assigns *a, *b;
ensures *a == \old(*b);
ensures *b == \old(*a);
*/
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int moo5(){
    int a = 37;
    int b = 91;
    swap(&a, &b);
    // @ assert a == 91;
    // @ assert b == 37;
    return 0;
}