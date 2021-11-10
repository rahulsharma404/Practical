#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void insert_in_Front(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void insert_at_Back(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *temp = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}
void insert_After(Node *head, int prev_data, int new_data)
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    Node *prev_node = head;
    while (prev_node->data != prev_data)
    {
        prev_node = prev_node->next;
        if (prev_node == NULL)
        {
            cout << prev_data << " is not in the linked-list" << endl;
            return;
        }
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void deleteNode(Node **head_ref, int key)
{

    Node *temp = *head_ref;
    Node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "The given key is not present in Linkded list"<<endl;
            return;
        }

        prev->next = temp->next;

        delete temp;
    }
}
void printList(Node *node)
{
    cout << "Linkded List :  ";
    if (node == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    int x = 1;
    int new_data;
    int prev_data;
    int delete_data;
    int next_data;

    while (x)
    {
        int choice;
        cout << "-----------------------------------------" << endl;
        cout << "1. Insert element in front" << endl;
        cout << "2. Insert element at back" << endl;
        cout << "3. Insert After the given data" << endl;
        cout << "4. Delete given data from Linked List" << endl;
        cout << "5. Display Linked list" << endl;
        cout << "0. To exit" << endl;
        cout << "-----------------------------------------" << endl << endl;
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            x = 0;
            cout << "Exit..." << endl;
            break;
        case 1:
            cout << "Enter the element to add in front of the linked list : ";
            cin >> new_data;
            cout << endl;
            insert_in_Front(&head, new_data);
            printList(head);

            cout << endl;
            break;
        case 2:
            cout << "Enter the element to add at the back of the linked list : ";
            cin >> new_data;
            cout << endl;
            insert_at_Back(&head, new_data);
            printList(head);
            cout << endl;
            break;
        case 3:
            cout << "Enter the data of the previous node : ";
            cin >> prev_data;
            cout << "Enter the element to be added after the element " << prev_data << " : ";
            cin >> new_data;
            insert_After(head, prev_data, new_data);
            printList(head);
            cout << endl;
            break;
        case 4:
            cout << "Enter the key to be deleted : ";
            cin >> delete_data;
            deleteNode(&head, delete_data);
            printList(head);
            cout << endl;
            break;
        case 5:
            printList(head);
            cout << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
