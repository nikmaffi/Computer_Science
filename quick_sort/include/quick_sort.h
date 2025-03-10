#include <stdlib.h>

#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#ifdef __cplusplus
extern "C" {
#endif

void quick_sort(void *buffer, unsigned n, size_t size, int (*cmp)(const void *, const void *));
unsigned partition(void *buffer, unsigned n, size_t size, int (*cmp)(const void *, const void *));
void swap(void *a, void *b, size_t size);

#ifdef __cplusplus
}
#endif

#endif //__QUICK_SORT_H__