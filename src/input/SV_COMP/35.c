int foo35(const char * * args, int args_len);

int starts_with(const char *s, const char *prefix) {
    while (*prefix != '\0') {
      if (*s != *prefix) return 0;
      s++;
      prefix++;
    }
    return 1;
}

int foo35(const char * * args, int args_len) {

    if (args_len < 4)
      return 0;
    int i = 0;

    for (int j = 0; j < 4; j++) {
      if (starts_with(args[j], "te"))
        ++i;
    }

    return i == 1;
}
