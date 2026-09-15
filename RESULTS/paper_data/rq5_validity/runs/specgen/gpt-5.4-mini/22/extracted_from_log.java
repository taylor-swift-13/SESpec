class arraylength1 {
  //@ ensures (size < 0) ==> (\result == -1);
  //@ ensures (size >= 0) ==> (\result == 1 || \result == 0);
  //@ ensures (size >= 0 && (\result == 1)) ==> (new int[size].length == size);
  public static int func(int size) {
    if (size < 0) return -1;
    int int_array[] = new int[size];

    if(int_array.length != size)
      return 0;
    return 1;
  }
}