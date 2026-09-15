class Sespec0023 {
    /*@ 
      @ requires arg != null;
      @ ensures (arg.length() < 1) ==> \result == -1;
      @ ensures (arg.length() >= 1) ==> \result == 0;
      @*/
    /*@ spec_public @*/ static int foo23(String arg) {
        if (((int) arg.length()) < 1) return -1;
        char my_char = arg.charAt(0);
        int x = my_char;
        if (!(x >= 0 && x <= 65535)) return 0;
        my_char = (char) 65535;
        my_char++;
        if (my_char == 0) return 0;
        return 1;
    }
}