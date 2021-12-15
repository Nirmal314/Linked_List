#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} linkedList;

linkedList *createNode(int key)
{
    linkedList *tmp = malloc(sizeof(linkedList));
    tmp->data = key;
    tmp->next = NULL;
    return tmp;
}
void display(linkedList *l)
{
    if (l == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    else
    {
        linkedList *i = l;
        while (i != NULL)
        {
            printf("%d -> ", i->data);
            i = i->next;
        }
    }
}
linkedList *insertAtFirst(linkedList *l, int key)
{
    if (l == NULL)
        return createNode(key);
    else
    {
        linkedList *tmp = createNode(key);
        tmp->next = l;
        l = tmp;
        return l;
    }
}
linkedList *insertAtLast(linkedList *l, int key)
{
    if (l == NULL)
        return createNode(key);
    else
    {
        linkedList *i = l;
        linkedList *tmp = createNode(key);
        while (i->next != NULL)
            i = i->next;
        i->next = tmp;
        return l;
    }
}
int searchNode(linkedList *l, int val)
{
    int flag = 0;
    if (l == NULL)
        printf("Create a linked list first.\n");
    else
    {
        linkedList *i = l;
        while (i->next != NULL)
        {
            if (i->data == val)
            {
                flag = 1;
                break;
            }
            i = i->next;
        }
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}
int sizeOfLinkedList(linkedList *l)
{
    int count = 0;
    if (l == NULL)
        return 0;
    else
    {
        for (linkedList *i = l; i != NULL;)
        {
            i = i->next;
            count++;
        }
        return count;
    }
}
linkedList *insertAtPosition(linkedList *l, int pos, int key)
{
    if (l == NULL)
        return createNode(key);

    else if (pos == 1)
    {
        return insertAtFirst(l, key);
    }
    else if (pos > sizeOfLinkedList(l))
    {
        printf("Position is invalid, You can't insert.\n");
        return l;
    }
    else
    {
        linkedList *tmp = createNode(key);
        linkedList *ptr = l;
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        tmp->next = ptr->next;
        ptr->next = tmp;
        return l;
    }
}
linkedList *insertAfter(linkedList *l, int n, int key)
{
    int flag = 0;

    if (l == NULL)
        return createNode(key);
    else
    {
        linkedList *i = l;

        while (i != NULL)
        {
            if (i->data == n)
            {
                flag = 1;
                break;
            }
            i = i->next;
        }
    }
    if (flag == 0)
    {
        printf("%d not found, so where to insert? I'm returning you linkedlist at it is.\n",n);
        return l;
    }
    else
    {
        linkedList *ptr = l;
        linkedList *tmp = createNode(key);
        while (ptr->data != n && ptr != NULL)
        {
            ptr = ptr->next;
        }
        tmp->next = ptr->next;
        ptr->next = tmp;
        return l;
    }
}
linkedList *insertBefore(linkedList *l, int n, int key)
{
    int flag = 0;

    if (l == NULL)
        return createNode(key);
    else
    {
        linkedList *i = l;

        while (i != NULL)
        {
            if (i->data == n)
            {
                flag = 1;
                break;
            }
            i = i->next;
        }
    }
    if (flag == 0)
    {
        printf("%d not found, so where to insert? I'm returning you linkedlist at it is.\n",n);
        return l;
    }
    else
    {
        linkedList *ptr = l;
        linkedList *tmp = createNode(key);

        while (ptr->next->data != n && ptr != NULL)
        {
            ptr = ptr->next;
        }
        tmp->next = ptr->next;
        ptr->next = tmp;
        return l;
    }
}

linkedList *deleteAtFirst(linkedList *l)
{
    if (l == NULL)
    {
        printf("What to delete?\n");
        return l;
    }
    else
    {
        linkedList *tmp = l;
        l = l->next;
        free(tmp);
        return l;
    }
}
linkedList *deleteAtLast(linkedList *l)
{
    if (l == NULL)
    {
        printf("What to delete?\n");
        return l;
    }
    else
    {
        linkedList *i = l;
        while (i->next->next)
        {
            i = i->next;
        }
        i->next = NULL;
        return l;
    }
}
linkedList *deleteAtPosition(linkedList *l, int pos)
{
    if (l == NULL)
    {
        printf("What to delete?\n");
        return l;
    }
    else if (pos == 1)
        return deleteAtFirst(l);
    else
    {
        linkedList *ptr = l;
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return l;
    }
}
linkedList *deleteBefore(linkedList *l, int n)
{
    int flag = 0;
    if (l == NULL)
    {
        printf("What to delete?\n");
        return l;
    }
    else
    {
        linkedList *i = l;

        while (i != NULL)
        {
            if (i->data == n)
            {
                flag = 1;
                break;
            }
            i = i->next;
        }
    }
    if (flag == 0)
    {
        printf("%d not found.\n", n);
        return l;
    }
    else
    {
        linkedList *ptr = l;
        while (ptr->next->next->data != n && ptr != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return l;
    }
}

linkedList *deleteAfter(linkedList *l, int n)
{
    int flag = 0;
    if (l == NULL)
    {
        printf("What to delete?\n");
        return l;
    }
    else
    {
        linkedList *i = l;

        while (i != NULL)
        {
            if (i->data == n)
            {
                flag = 1;
                break;
            }
            i = i->next;
        }
    }
    if (flag == 0)
    {
        printf("%d not found.\n", n);
        return l;
    }
    else
    {
        linkedList *ptr = l;
        while (ptr->data != n && ptr != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return l;
    }
}
void main()
{
    linkedList *l = createNode(3);
    l = insertAtLast(l, 4);
    l = insertAtLast(l, 5);
    l = insertAtLast(l, 6);
    l = insertAtLast(l, 7);
    l = deleteAfter(l, 3);
    printf("Size of LL : %d\n", sizeOfLinkedList(l));
    display(l);
}