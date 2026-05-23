int foo62_helper1_c13();
int foo62_c13(int depth);


int foo62_c13(int depth) {

    if (depth < 10) return foo62_c13(depth + 1) + 1;
    else return 0;
}