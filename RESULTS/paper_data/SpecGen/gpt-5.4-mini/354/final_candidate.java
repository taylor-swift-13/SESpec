/*@ public normal_behavior
  @   requires n >= 0;
  @   ensures \result >= 0;
  @   ensures (\result & 1) == 0 || (\result & 1) == 1;
  @   assignable \nothing;
  @*/
public static int evenBitSetNumber(int n) {
    int result = 0;
    int even = 0;

    /*@ loop invariant 0 <= even && even <= n;
      @ loop invariant result >= 0;
      @ loop invariant (\forall int k; 0 <= k && k < even; (k % 2 == 0) ==> ((result & (1 << k)) != 0));
      @ decreases n - even;
      @*/
    while (even < n) {
        if (even % 2 == 0) {
            /*@ assert 0 <= even && even < 31; @*/
            result |= (1 << even);
        }
        even++;
    }

    return result;
}