
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
 
void add(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}
 

int Get(struct Node* head, int n)
{

    if (head == NULL)
        return -1;
 
    if (n == 0)
        return head->data;

    return Get(head->next, n - 1);
}

int size(struct Node* head) 
{ 
    if (head == NULL) 
        return 0; 
  
    return 1 + size(head->next);
}

// void insertAfter(Node* prev_node, int new_data) 
// {
//     if (prev_node == NULL) 
//     { 
//         cout<<"the given previous node cannot be NULL"; 
//         return; 
//     }
//     Node* new_node = new Node();
//     new_node->data = new_data; 
 
//     new_node->next = prev_node->next; 
 
//     prev_node->next = new_node; 

//     new_node->prev = prev_node; 

//     if (new_node->next != NULL) 
//         new_node->next->prev = new_node; 
// } 


int main()
{
    struct Node* head = NULL;
    add(&head, 1);
    add(&head, 4);
    add(&head, 1);
    add(&head, 12);
    add(&head, 1);
    cout<<"Count of nodes is "<< size(head) << endl;  
    cout<<"Element at index 3 is "<< Get(head, 3);
    getchar();
}
