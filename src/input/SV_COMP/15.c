int foo15(int x, int z);

int foo15(int x, int z) {

    int y = 3;
    x = z + y;
    if (!(z >= 0)) {
      return 0;
    }
    if (!(x >= 0))
      return 0;

    return 1;
}
