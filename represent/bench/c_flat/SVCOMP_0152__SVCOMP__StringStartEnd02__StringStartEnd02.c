int f(const char * * args, int args_len);

int f(const char * * args, int args_len) {

    if (args_len < 4)
      return 0;
    int i = 0;

    for (int j = 0; j < 4; j++) {
      if (args[j].startsWith("te"))
        ++i;
    }

    return i == 1;
}
