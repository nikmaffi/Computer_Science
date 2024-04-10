#include <merge_sort.h>

#include <stdint.h>
#include <string.h>

void shift(void *left, unsigned ln, void *right, size_t size) {
    void *tmp = malloc(size);

    memcpy(tmp, (uint8_t *)left + (ln - 1) * size, size);
    memmove((uint8_t *)left + size, left, (ln - 1) * size);
    memcpy(left, right, size);
    memcpy(right, tmp, size);

    free(tmp);
}

void merge(void *left, unsigned ln, void *right, unsigned rn, size_t size, int (*cmp)(const void *, const void *)) {
    if(ln == 0 || rn == 0) {
        return;
    }

    if(cmp(left, right) <= 0) {
        merge((uint8_t *)left + size, ln - 1, right, rn, size, cmp);
        return;
    }

    merge(left, ln, (uint8_t *)right + size, rn - 1, size, cmp);
    shift(left, ln, right, size);
}

void merge_sort(void *buffer, unsigned n, size_t size, int (*cmp)(const void *, const void *)) {
    unsigned k = 0;

    if(n == 1) {
        return;
    }

    k = n / 2;

    merge_sort(buffer, k, size, cmp);
    merge_sort((uint8_t *)buffer + k * size, n - k, size, cmp);
    merge(buffer, k, (uint8_t *)buffer + k * size, n - k, size, cmp);
}