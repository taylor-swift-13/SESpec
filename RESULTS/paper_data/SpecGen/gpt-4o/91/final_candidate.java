/*@ requires arr != null;
  @ requires (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1]); // Array must be sorted
  @ ensures \result == -1 || (0 <= \result && \result < arr.length && arr[\result] == key);
  @*/