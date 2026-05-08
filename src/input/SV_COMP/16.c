int foo16(int x, int z);

int foo16(int x, int z) {

    int y = 3;
    z = x + y + 4;
    if (!(z >= 0))
      return 0;
    if (!(y >= 0)) {
      return 0;
    }
    return 1;
}
