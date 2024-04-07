#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;
// insert link at the first location
void insert(int data)
{
    // Allocate memory for new node;
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    // If head is empty, create new list
    if (head == NULL)
    {
        head = link;
        head->next = link;
        return;
    }
    current = head;

    // move to the end of the list
    while (current->next != head)
        current = current->next;
    // Insert link at the end of the list
    current->next = link;
    // Link the last node back to head
    link->next = head;
}
// display the list
void find_data(int item)
{
    int pos = 0;
    if (head == NULL)
    {
        printf("Linked List not initialized");
        return;
    }
    current = head;
    while (current->next != head)
    {
        if (current->data == item)
        {
            printf("%d found at position %d\n", item, pos);
            return;
        }
        current = current->next;
        pos++;
    }
    if (current->data == item)
    {
        printf("%d found at position %d\n", item, pos);
        return;
    }
    printf("%d does not exist in the list", item);
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(1);
    insert(40);
    insert(56);

    find_data(56);
    return 0;
}
