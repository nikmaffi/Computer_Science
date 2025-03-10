#include <stdlib.h>

#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#ifdef __cplusplus
extern "C" {
#endif

void merge_sort(void *buffer, unsigned n, size_t size, int (*cmp)(const void *, const void *));
void merge(void *left, unsigned ln, void *right, unsigned rn, size_t size, int (*cmp)(const void *, const void *));
void shift(void *left, unsigned ln, void *right, size_t size);

#ifdef __cplusplus
}
#endif

#endif //__MERGE_SORT_H__