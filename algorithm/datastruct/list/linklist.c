#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define OK          1
#define ERROR       0


typedef struct _node {
    int data;
    struct _node *next;
} node, *linklist;


int visit(int e)
{
    printf("%d ", e);

    return OK;
}

int linklist_init(linklist *l)
{
    *l = (linklist)malloc(sizeof(node));

    if (!(*l))
    {
        return ERROR;
    }

    (*l)->next = NULL;

    return OK;
}

int linklist_empty(linklist l)
{
    if (NULL == l->next)
        return OK;
    else
        return ERROR;
}

int linklist_clear(linklist *l)
{
    linklist p, q;

    p = (*l)->next;

    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    (*l)->next = NULL;

    return OK;
}

int linklist_length(linklist l)
{
    int i = 0;
    linklist p = l->next;

    while (p)
    {
        i++;
        p = p->next;
    }

    return i;
}

int linklist_get_elem(linklist l, int pos, int *e)
{
    int i = 1;
    linklist p = l->next;

    while (p && (i < pos))
    {
        p = p->next;
        ++i;
    }

    if (!p || i > pos)
        return ERROR;

    *e = p->data;

    return OK;
}

int linklist_locate(linklist l, int e)
{
    int i = 0;
    linklist p = l->next;

    while (p)
    {
        ++i;

        if (p->data == e)
            return i;

        p = p->next;
    }

    return ERROR;
}

int linklist_insert(linklist *l, int pos, int e)
{
    int i = 1;
    linklist p, q;

    p = (*l);

    while (p && (i < pos))
    {
        p = p->next; 
        i++;
    }

    if (!p || i > pos)
        return ERROR;

    q = (linklist)malloc(sizeof(node));

    q->data = e;
    q->next = p->next;
    p->next = q;

    return OK;
}

int linklist_delete(linklist *l, int pos, int *e)
{
    int i = 1;
    linklist p, q;

    p = (*l);

    while (p->next && (i < pos))
    {
        p = p->next;
        i++;
    }

    if (!(p->next) || i > pos)
        return ERROR;

    q = p->next;
    p->next = q->next;
    *e = q->data;

    return OK;
}

int linklist_traval(linklist l)
{
    linklist p = l->next;

    while (p)
    {
        visit(p->data);
        p = p->next;
    }

    printf("\r\n");

    return OK;
}

int linklist_create_head(linklist *l, int n)
{
    linklist p;
    int i;

    srand(time(0));

    *l = (linklist)malloc(sizeof(node));
    (*l)->next = NULL;

    for (i = 0; i < n; i++)
    {
        p = (linklist)malloc(sizeof(node));
        p->data = rand() % 100 + 1;
        p->next = (*l)->next;
        (*l)->next = p;
    }

    return OK;
}

int linklist_create_tail(linklist *l, int n)
{
    linklist p, q;
    int i;

    srand(time(0));
    *l = (linklist)malloc(sizeof(node));
    q = (*l);

    for (i = 0; i < n; i++)
    {
        p = (linklist)malloc(sizeof(node));
        p->data = rand() % 100 + 1;
        q->next = p;
        q = p;
    }

    q->next = NULL;

    return OK;
}

int main(int argc, char *argv[])
{
    printf("linklist demo...\r\n");

    linklist l;
    int i, j, k;

    i = linklist_init(&l);
    printf(" init linklist length: %d \r\n", linklist_length(l));

    for (j = 1; j < 5; j++)
    {
        i = linklist_insert(&l, 1, j);
    }
    printf(" insert 1-5: ");
    linklist_traval(l);

    printf(" now linklist length: %d \r\n", linklist_length(l));

    i = linklist_empty(l);
    printf(" l is empty %d (1 yes, 0 no) \r\n", i);

    return 0;
}
