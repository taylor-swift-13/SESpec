/*@
x == old_a && y == old_b && z == old_c &&;
requires \valid(a) && \valid(b) && \valid(c);
int old_a = \old(*a), old_b = \old(*b), old_c = \old(*c);
ensures {;
ensures *a <= *b && *b <= *c;
assigns *a, *b, *c;
\exists int x, y, z;;
(*c == x || *c == y || *c == z)) &&;
(*b == x || *b == y || *b == z) &&;
(*a != *b || *b != *c || *a == *c);;
((*a == x || *a == y || *a == z) &&;
*/
void order_3(int *a, int *b, int *c) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {    
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
}

void moo18(){
    
    int a1 = 5, b1 = 3, c1 = 4 ;
    order_3(&a1, &b1, &c1) ;
    // @ assert a1 == 3 && b1 == 4 && c1 == 5;
    
    int a2 = 2, b2 = 2, c2 = 2 ;
    order_3(&a2, &b2, &c2) ;
    // @ assert a2 == 2 && b2 == 2 && c2 == 2 ;

    int a3 = 4, b3 = 3, c3 = 4 ;
    order_3(&a3, &b3, &c3) ;
    // @ assert a3 == 3 && b3 == 4 && c3 == 4 ;

    int a4 = 4, b4 = 5, c4 = 4 ;
    order_3(&a4, &b4, &c4) ;
    // @ assert a4 == 4 && b4 == 4 && c4 == 5 ;
}