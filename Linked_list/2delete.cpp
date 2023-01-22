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
    new_node->next = NULL;

    if (head == NULL)
    {
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
    }

    return head;
}

void display(Node *head)
{
    Node *p = head;

    cout << "The elements are as follows : \n";

    while (p != NULL)
    {

        cout << p->data << endl;
        p = p->next;
    }
}

void count(Node *head)
{
    int n = 0;
    Node *p = head;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }

    cout << "The total no of nodes in the LL is " << n << endl;
}

void add(Node *head)
{
    int sum = 0;
    Node *p = head;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }

    cout << "The total sum of elements in the LL is " << sum << endl;
}

void maxelement(Node *head)
{
    int n = 0;
    Node *p = head;
    while (p != NULL)
    {
        if (n < p->data)
        {
            n = p->data;
        }
        p = p->next;
    }

    cout << "The max element in the LL is " << n << endl;
}

void search(Node *head)
{
    int n = 0;
    int key;
    bool flag = false;
    cout << "Enter the element you want to search : ";
    cin >> key;

    Node *p = head;
    while (p != NULL)
    {
        n++;
        if (key == p->data)
        {
            flag = true;
            break;
        }
        p = p->next;
    }

    if (flag)
    {
        cout << "The element is present at " << n << "th node" << endl;
    }
    else
    {
        cout << "The element is not present";
    }
}

Node *insertAtNode(Node *head, int num, int pos)
{
    Node *p = head;
    while (--pos)
    {
        p = p->next;
    }

    Node *new_node = new Node();
    new_node->data = num;
    new_node->next = p->next;
    p->next = new_node;

    return head;
}

Node *insertAtFirst(Node *head, int num)
{
    Node *p = head;
    Node *new_node = new Node();
    new_node->data = num;
    new_node->next = p;
    head = new_node;
    return head;
}

bool sortedOrNot(Node *head)
{
    while (head->next != NULL)
    {
        if (head->data > head->next->data)
            return false;
        else
            head = head->next;
    }
    return true;
}

void removeDub(Node *head)
{
    Node *p;
    Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{
    int repeat = 1;
    Node *head = NULL;

    cout << "Linked list created successfully ! \n";
    cout << "select one of the option \n1. create \n2. display \n3. sorted or not \n4.delete dublicate \n5. max element \n6. search  \n7.Inserting at first \n8.Inserting after given node \n9. Sorted or not ? \n10. Remove dublicates  \n";
    do
    {

        int choice;
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
            if (sortedOrNot(head))
            {
                cout << "Linked list is sorted !";
            }
            else
            {
                cout << "LL is not sorted";
            }
            break;

        case 4:
            removeDub(head);
            break;

        default:
            break;
        }

    } while (repeat);

    return 0;
}
