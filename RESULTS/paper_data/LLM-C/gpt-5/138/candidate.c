int notCommonFactor(int a, int b, int factor);

/*@ 
  requires factor != 0;
  assigns \nothing;
  behavior some_not_divisible:
    assumes factor != 0 && (a % factor != 0 || b % factor != 0);
    ensures \result == 1;
  behavior both_divisible:
    assumes factor != 0 && (a % factor == 0 && b % factor == 0);
    ensures \result == 0;
  ensures \result == 1 <==> (a % factor != 0 || b % factor != 0);
  ensures \result == 0 <==> (a % factor == 0 && b % factor == 0);
  ensures 0 <= \result && \result <= 1;
  complete behaviors;
  disjoint behaviors;
*/
int notCommonFactor(int a, int b, int factor) {

        if(a % factor != 0) {
            return 1;
        }
        if(b % factor != 0) {
            return 1;
        }
        return 0;
}
