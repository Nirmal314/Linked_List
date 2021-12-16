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
    }
    else
    {
        linkedList *i = l;
        printf("\n");
        while (i != NULL)
        {
            printf("%d -> ", i->data);
            i = i->next;
        }
        printf("\n\n");
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
    else if (pos > sizeOfLinkedList(l) || pos < 0)
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
        printf("%d not found, so where to insert? I'm returning you linkedlist at it is.\n", n);
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
        printf("%d not found, so where to insert? I'm returning you linkedlist at it is.\n", n);
        return l;
    }
    else
    {
        linkedList *ptr = l;
        linkedList *tmp = createNode(key);

        if (n == l->data)
            return insertAtFirst(l, key);
        else
        {
            while (ptr->next->data != n && ptr != NULL)
            {
                ptr = ptr->next;
            }
            tmp->next = ptr->next;
            ptr->next = tmp;
            return l;
        }
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
    else if (pos > sizeOfLinkedList(l) || pos < 0)
    {
        printf("Position is invalid, You can't delete.\n");
        return l;
    }
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
    else if (l->next->data == n)
    {
        return deleteAtFirst(l);
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
        if (l->data == n)
        {
            printf("Nothind to delete before %d.\n", n);
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
        linkedList *i = l;

        while (i->next != NULL)
            i = i->next;
        if (i->data == n)
        {
            printf("Nothind to delete after %d.\n", n);
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
}
int numberOfNodes(linkedList *l, int key)
{
    int count = 0;
    if (searchNode(l, key))
    {
        linkedList *i = l;
        while (i->next != NULL)
        {
            if (i->data == key)
            {
                count++;
            }
            i = i->next;
        }
        return count;
    }
    else
    {
        return count;
    }
}
linkedList *deleteFirstOccurence(linkedList *l, int key)
{
    if (l == NULL)
        printf("Nothing to delete, Linked list is empty.\n");
    else if (searchNode(l, key))
    {
        if (numberOfNodes(l, key) >= 2)
        {
            linkedList *i = l;
            while (i->next != NULL)
            {
                if (i->next->data == key)
                {
                    break;
                }
                i = i->next;
            }

            i->next = i->next->next;
            return i;
        }
        else
        {
            printf("You have only one node, can't delete.\n");
            return l;
        }
    }
    else
    {
        printf("Data you want to delete not found.\n");
        return l;
    }
}
int lastNode(linkedList *l)
{
    linkedList *i = l;
    while (i->next != NULL)
        i = i->next;
    return i->data;
}
linkedList *deleteAllOccurence(linkedList *l, int key)
{
    if (l == NULL)
        printf("Nothing to delete, Linked list is empty.\n");
    else if (searchNode(l, key))
    {
        if (l->data == key)
        {
            l = deleteAtFirst(l);
            l = deleteAllOccurence(l, key);
        }
        else if (lastNode(l) == key)
        {
            l = deleteAtLast(l);
            l = deleteAllOccurence(l, key);
        }
        else
        {
            linkedList *i = l;
            while (i->next != NULL)
            {
                if (i->next->data == key)
                {
                    break;
                }
                i = i->next;
            }

            i->next = i->next->next;
            l = deleteAllOccurence(l, key); // that golden line
            return i;
        }
    }
    
}
void main()
{
    linkedList *l = NULL;

    l = insertAtLast(l, 20); //
    l = insertAtLast(l, 10);
    l = insertAtLast(l, 30);
    l = insertAtLast(l, 20); //
    l = insertAtLast(l, 50);
    l = insertAtLast(l, 60);
    l = insertAtLast(l, 20); //

    l = deleteAllOccurence(l, 20);
    display(l);
}

// 20 -> 10 -> 30 -> 20 -> 50 -> 60 -> 20 ->
