int foo12(int x, int z);

int foo12(int x, int z) {

    x = z++;
    if (!(z > 0)) {
      return 0;
    }
    if (!(x > 0)) {
      return 0;
    }
    return 1;
}
