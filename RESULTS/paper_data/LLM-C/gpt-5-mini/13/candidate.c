int f();
int recursion_test(int depth);

/*@
    assigns \nothing;
    ensures \result == 1;
*/
int f() {

    return recursion_test(0) == 10;
}

/*@
    assigns \nothing;
    ensures depth < 10  ==> \result == 10 - depth;
    ensures depth >= 10 ==> \result == 0;
    terminates \true;
    decreases (depth < 10 ? 10 - depth : 0);
*/
int recursion_test(int depth) {

    if (depth < 10) return recursion_test(depth + 1) + 1;
    else return 0;
}
