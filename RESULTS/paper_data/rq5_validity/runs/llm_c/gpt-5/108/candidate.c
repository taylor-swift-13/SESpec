int fizzBuzz(int n);

 /*@
   assigns \nothing;
   ensures \result == ((n % 3 == 0 ? 3 : 0) + (n % 5 == 0 ? 5 : 0));
   ensures 0 <= \result <= 8;
   behavior none {
     assumes n % 3 != 0 && n % 5 != 0;
     ensures \result == 0;
   }
   behavior div3 {
     assumes n % 3 == 0 && n % 5 != 0;
     ensures \result == 3;
   }
   behavior div5 {
     assumes n % 3 != 0 && n % 5 == 0;
     ensures \result == 5;
   }
   behavior div15 {
     assumes n % 3 == 0 && n % 5 == 0;
     ensures \result == 8;
   }
   complete behaviors none, div3, div5, div15;
   disjoint behaviors none, div3, div5, div15;
 */
int fizzBuzz(int n) {

        int res = 0;
        if (n % 3 == 0) {
            res += 3;
        }
        if (n % 5 == 0) {
            res += 5;
        }
        return res;
}
