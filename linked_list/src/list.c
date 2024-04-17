#include <list.h>

#include <stdlib.h>
#include <string.h>

struct List *newl(size_t size) {
    struct List *l = (struct List *)malloc(sizeof(struct List));

    l->head = NULL;
    l->size = size;

    return l;
}

int appendl(struct List *l, void *data) {
    struct Node *tmp = l->head;

    if(!l->head) {
        l->head = (struct Node *)malloc(sizeof(struct Node));

        if(!l->head) return APPENDL_FAILED;

        l->head->data = malloc(l->size);

        if(!l->head->data) {
            free(l->head);
            return APPENDL_FAILED;
        }

        memcpy(l->head->data, data, l->size);
        l->head->next = NULL;

        return LIST_SUCCESS;
    }

    while(tmp->next) {
        tmp = tmp->next;
    }

    tmp->next = (struct Node *)malloc(sizeof(struct Node));

    if(!tmp->next) return APPENDL_FAILED;

    tmp->next->data = malloc(l->size);

    if(!tmp->next->data) {
        free(tmp->next);
        return APPENDL_FAILED;
    }

    memcpy(tmp->next->data, data, l->size);
    tmp->next->next = NULL;

    return LIST_SUCCESS;
}

int pushl(struct List *l, void *data) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    if(!new) return PUSHL_FAILED;

    new->data = malloc(l->size);

    if(!new->data) {
        free(new);
        return PUSHL_FAILED;
    }

    memcpy(new->data, data, l->size);
    new->next = l->head;

    l->head = new;

    return LIST_SUCCESS;
}

int insertl(struct List *l, void *data, unsigned i) {
    struct Node *cur = l->head, *prv = l->head;

    if(i == 0) {
        return pushl(l, data);
    }

    for(; i > 0; i--) {
        if(!cur) return LIST_OVERFLOW;

        prv = cur;
        cur = cur->next;
    }

    prv->next = (struct Node *)malloc(sizeof(struct Node));

    if(!prv->next) return INSERTL_FAILED;

    prv->next->data = malloc(l->size);

    if(!prv->next->data) {
        free(prv->next);
        return INSERTL_FAILED;
    }

    memcpy(prv->next->data, data, l->size);
    prv->next->next = cur;

    return LIST_SUCCESS;
}

void *getl(struct List *l, unsigned i) {
    struct Node *tmp = l->head;

    for(; i > 0 && tmp; i--) {
        tmp = tmp->next;
    }

    if(!tmp) return NULL;

    return tmp->data;
}

int popl(struct List *l, void *data) {
    struct Node *tmp = NULL;

    if(!l->head) return LIST_EMPTY;

    tmp = l->head;

    memcpy(data, tmp->data, l->size);
    l->head = tmp->next;

    free(tmp->data);
    free(tmp);

    return LIST_SUCCESS;
}

int deletel(struct List *l, unsigned i) {
    struct Node *cur = l->head, *prv = l->head;

    if(i == 0) {
        l->head = l->head->next;

        free(cur->data);
        free(cur);

        return LIST_SUCCESS;
    }

    for(; i > 0 && cur; i--) {
        prv = cur;
        cur = cur->next;
    }

    if(!cur) return LIST_OVERFLOW;

    prv->next = cur->next;

    free(cur->data);
    free(cur);

    return LIST_SUCCESS;
}

size_t diml(struct List *l) {
    size_t size = 0;
    struct Node *tmp = l->head;

    while(tmp) {
        tmp = tmp->next;
        size++;
    }

    return size;
}

void freel(struct List *l) {
    struct Node *tmp = l->head;

    while(tmp) {
        tmp = tmp->next;
        free(l->head);
        l->head = tmp;
    }

    free(l);
}