#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *create(Node *head)
{
    Node *new_node = new Node();

    cout << "Enter the data : ";
    cin >> new_node->data;

    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
    }
    else
    {
        Node *p = head;
        do
        {
            p = p->next;
        } while (p->next != head);

        p->next = new_node;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

void display(Node *head)
{
    Node *p = head;

    if (head == NULL)
    {
        cout << "\nLinked list is empty!";
    }
    else
    {
        do
        {
            cout << p->data << endl;
            p = p->next;

        } while (p != head);
    }
}

Node *delet(Node *head)
{
    Node *p = head, *q = head;
    int pos;
    cout << "Enter the position : ";
    cin >> pos;
    while (--pos)
    {
        q = p;
        p = p->next;
    }

    q->next = p->next;
    delete p;
    return head;
}

int main()
{
    int repeat = 1;
    int choice;
    Node *head = NULL;

    cout << "Circular Linked list created successfully ! \n";
    cout << "\nselect one of the option \n1. create \n2. display \n3.Delete the node  \n4.reverse the LL by elements \n4. sum of all elements \n5. reverse using pointers\n6. search  \n7.Inserting at first \n8.Inserting after given node \n9. Sorted or not ? \n10. Remove dublicates  \n11. Revesrse the linked list using reversing the elemets  \n12. Reverse the list using sliding pointers \n13. reverse using recursion   \n14. create 2nd list    \n15. Merge the first and second itno the third \n16. Display second \n17. Display third\n";

    do
    {

        cout << "\nyou chose :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            head = create(head);
            break;

        case 2:
            display(head);
            break;

        case 3:
            head = delet(head);
            break;

        case 4:
            // reverse(head);

        default:
            cout
                << "\nSpecify the correct range!";
        }
    } while (repeat);

    return 0;
}