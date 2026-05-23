int notCommonFactor(int a, int b, int factor);

 /*@
   requires factor != 0;
   assigns \nothing;
   ensures \result == 0 || \result == 1;
   ensures (\result != 0) <=> ((a % factor != 0) || (b % factor != 0));

   behavior both_divisible:
     assumes a % factor == 0 && b % factor == 0;
     ensures \result == 0;

   behavior at_least_one_not_divisible:
     assumes a % factor != 0 || b % factor != 0;
     ensures \result == 1;

   complete behaviors;
   disjoint behaviors;
 */
int notCommonFactor(int a, int b, int factor) {

        return a % factor != 0 || b % factor != 0;
}
