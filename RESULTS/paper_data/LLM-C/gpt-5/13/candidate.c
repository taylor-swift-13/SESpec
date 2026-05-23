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
  decreases (depth < 10) ? (10 - depth) : 0;
  behavior base:
    assumes depth >= 10;
    ensures \result == 0;
  behavior rec:
    assumes depth < 10;
    ensures \result == 10 - depth;
  complete behaviors base, rec;
  disjoint behaviors base, rec;
*/
int recursion_test(int depth) {

    if (depth < 10) return recursion_test(depth + 1) + 1;
    else return 0;
}
