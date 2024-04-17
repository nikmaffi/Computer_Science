#ifndef __LIST_H__
#define __LIST_H__

#include <stddef.h>

#define LIST_SUCCESS 0
#define PUSHL_FAILED -1
#define LIST_EMPTY -2
#define APPENDL_FAILED -3
#define INSERTL_FAILED -4
#define LIST_OVERFLOW -5

struct Node {
    void *data;
    struct Node *next;
};

struct List {
    size_t size;
    struct Node *head;
};

struct List *newl(size_t size);
int appendl(struct List *l, void *data);
int pushl(struct List *l, void *data);
int insertl(struct List *l, void *data, unsigned i);
void *getl(struct List *l, unsigned i);
int popl(struct List *l, void *data);
int deletel(struct List *l, unsigned i);
size_t diml(struct List *l);
void freel(struct List *l);

#endif //__LIST_H__