#ifndef __LIST_H__
#define __LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define LIST_SUCCESS 0
#define PUSHL_FAILED -1
#define LIST_EMPTY -2
#define APPENDL_FAILED -3
#define INSERTL_FAILED -4
#define LIST_OVERFLOW -5

#define LIST_SUCCESS        0
#define LIST_MALLOC_FAILED -1
#define LIST_POP_FAILED    -2

struct node {
    void *data;
    struct node *next;
};

struct list {
    size_t size;
    struct node *head;
};

struct list *new_list(size_t size);
int append_list(struct list *l, const void *data);
int append_sort_list(struct list *l, const void *data, int (*compare)(const void *, const void *));
int insert_list(struct list *l, size_t index, const void *data);
void *get_list(struct list *l, size_t index);
int remove_list(struct list *l, size_t index, void *data);
size_t size_list(struct list *l);
void free_list(struct list *l);

#ifdef __cplusplus
}
#endif

#endif //__LIST_H__
