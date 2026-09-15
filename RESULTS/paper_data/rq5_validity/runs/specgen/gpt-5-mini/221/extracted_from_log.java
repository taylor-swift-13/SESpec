import java.util.*;

class FindOddPair {

  /*@
    @ requires arr != null;
    @
    @ ensures \result == (\sum int i; 0 <= i && i < arr.length;
    @                        (\sum int j; i+1 <= j && j < arr.length;
    @                           (((arr[i] ^ arr[j]) % 2 == 1) ? 1 : 0)));
    @ ensures 0 <= \result && \result <= (arr.length * (arr.length - 1)) / 2;
    @*/
  public static int findOddPair(int[] arr) {
    int found = 0;
    int offset = arr.length;

    /*@
      @ loop_invariant 0 <= c && c <= offset;
      @ loop_invariant 0 < found && found < (offset * (offset - 1)) / 2;  
      @ loop_invariant found == (\sum int i; 0 <= i && i < c;
      @                               (\sum int j; i+1 <= j && j < offset;
      @                                  (((arr[i] ^ arr[j]) % 2 == 1) ? 1 : 0)));
      @ decreases offset - c;
      @*/
    for (int c = 0; c < offset; c++) {
      /*@
        @ loop_invariant c+1 <= index && index <= offset;
        @ loop_invariant found == (\sum int i; 0 <= i && i < c;
        @                              (\sum int j; i+1 <= j && j < offset;
        @                                 (((arr[i] ^ arr[j]) % 2 == 1) ? 1 : 0)))
        @                    + (\sum int j; c+1 <= j && j < index;
        @                                 (((arr[c] ^ arr[j]) % 2 == 1) ? 1 : 0));
        @ decreases offset - index;
        @*/
      for (int index = c + 1; index < offset; index++) {
        if ((arr[c] ^ arr[index]) % 2 == 1) {
          found++;
        }
      }
    }
    return found;
  }
}