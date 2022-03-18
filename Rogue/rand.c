int get_rand_range_int(const int min, const int max) {
    return rand() % (max - min + 1) + min;
}