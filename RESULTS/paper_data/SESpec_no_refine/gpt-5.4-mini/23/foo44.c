
/*@ 
  logic integer bit_at(int *bits, integer i) = bits[i];
*/

/*@
  requires \valid(&bits[0] + (0..bits_len-1));
  requires \forall integer i; 0 <= i < bits_len ==> 0 <= bits[i] <= 100;
  requires bits_len > 0;
  requires bits_len < 100;
  assigns \nothing;
  ensures (bits_len == 1 ==> \result == 0);
  ensures (bits_len > 1 ==> (\exists integer t; 0 <= t < bits_len - 1 &&
          (\let s0 = \at(bits[0],Pre);
           \let s1 = \at(bits[s0 + 1],Pre);
           \let s2 = \at(bits[s0 + 1 + s1 + 1],Pre);
           \let s3 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1],Pre);
           \let s4 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1],Pre);
           \let s5 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1],Pre);
           \let s6 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1],Pre);
           \let s7 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1],Pre);
           \let s8 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1],Pre);
           \let s9 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1],Pre);
           \let s10 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1],Pre);
           \let s11 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1],Pre);
           \let s12 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1],Pre);
           \let s13 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1 + s12 + 1],Pre);
           \let s14 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1 + s12 + 1 + s13 + 1],Pre);
           \let s15 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1 + s12 + 1 + s13 + 1 + s14 + 1],Pre);
           \let s16 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1 + s12 + 1 + s13 + 1 + s14 + 1 + s15 + 1],Pre);
           \let s17 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1 + s12 + 1 + s13 + 1 + s14 + 1 + s15 + 1 + s16 + 1],Pre);
           \let s18 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1 + s12 + 1 + s13 + 1 + s14 + 1 + s15 + 1 + s16 + 1 + s17 + 1],Pre);
           \let s19 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1 + s12 + 1 + s13 + 1 + s14 + 1 + s15 + 1 + s16 + 1 + s17 + 1 + s18 + 1],Pre);
           \let s20 = \at(bits[s0 + 1 + s1 + 1 + s2 + 1 + s3 + 1 + s4 + 1 + s5 + 1 + s6 + 1 + s7 + 1 + s8 + 1 + s9 + 1 + s10 + 1 + s11 + 1 + s12 + 1 + s13 + 1 + s14 + 1 + s15 + 1 + s16 + 1 + s17 + 1 + s18 + 1 + s19 + 1],Pre);
           \result == 1));
*/
int foo44(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        
            
        /*@
          loop invariant (!(0 < \at(bits_len,Pre) - 1)) ==> ((i == 0)&&(n == \at(bits_len,Pre))&&(bits_len == \at(bits_len,Pre))&&(bits == \at(bits,Pre)));
          loop invariant n == \at(bits_len,Pre);
          loop invariant bits_len == \at(bits_len,Pre);
          loop invariant bits == \at(bits,Pre);
          loop invariant \forall integer k; 0 <= k < \at(bits_len,Pre) ==> bits[k] == \at(bits[k],Pre);
          loop assigns i;
            */
            while (i < n - 1) {
            i += bits[i] + 1;
        }
            
        return i == n - 1;
}
