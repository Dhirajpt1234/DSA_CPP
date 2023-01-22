#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
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
        new_node->next = NULL;
        new_node->prev = NULL;

        head = new_node;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = new_node;
        new_node->prev = p;
        new_node->next = NULL;
    }

    return head;
}

void display(Node *head)
{
    cout << "The elements are as follows : ";
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

Node *delet(Node *head)
{
    Node *p = head;
    cout << "Enter the index you want to delete: ";
    int pos;
    cin >> pos;

    if (pos == 1)
    {
        head = p->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete p;
    }
    else
    {
        while (--pos)
        {
            p = p->next;
        }
        p->prev->next = p->next;

        if (p->next)
        {
            p->next->prev = p->prev;
        }

        delete p;
    }

    return head;
}

Node *reverse(Node *head)
{
    vector<int> v;
    Node *p = head;

    while (p != NULL)
    {
        v.push_back(p->data);
        p = p->next;
    }

    Node *q = head;
    int i = v.size();
    while (q != NULL)
    {
        q->data = v[i - 1];
        i--;
        q = q->next;
    }

    return head;
}

Node *reverseUsingPoi(Node *head)
{
    Node *p = head;
    Node *temp;

    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;

        if (p->prev == NULL)
        {
            head = p;
        }
    }

    return head;
}

int main()
{
    int repeat = 1;
    int choice;
    Node *head = NULL;

    cout << "Circular Linked list created successfully ! \n";
    cout << "\nselect one of the option \n1. create \n2. display \n3.Delete the node  \n3.count no of nodes \n4. sum of all elements \n5. max element \n6. search  \n7.Inserting at first \n8.Inserting after given node \n9. Sorted or not ? \n10. Remove dublicates  \n11. Revesrse the linked list using reversing the elemets  \n12. Reverse the list using sliding pointers \n13. reverse using recursion   \n14. create 2nd list    \n15. Merge the first and second itno the third \n16. Display second \n17. Display third\n";

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
            reverse(head);
            break;

        case 5:
            head = reverseUsingPoi(head);

        default:
            cout
                << "\nSpecify the correct range!";
        }
    } while (repeat);

    return 0;
}