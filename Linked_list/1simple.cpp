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

Node *removeDub(Node *head) //ll needs to be sorted.
{
    Node *p = head;
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

    return head;
}

void reverseUsingElement(Node *head)
{
    vector<int> v;
    Node *p = head;
    int i = 0;

    while (p != NULL)
    {
        v.push_back(p->data);
        p = p->next;
        i++;
    }

    Node *q = head;

    for (int j = i - 1; j >= 0; j--)
    {
        q->data = v[j];
        q = q->next;
    }
}

Node *reverseUsingSlidingPoi(Node *head)
{
    Node *p = head, *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    head = q;
    return head;
}

Node *reverseIt(Node *q, Node *p)
{
    if (p != NULL)
    {
        reverseIt(p, p->next);
        p->next = q;
    }
    else
    {
        Node *head = q;
    }
}

Node *reverseUsingRecursion(Node *head)
{
    Node *q = NULL;
}

Node *merge(Node *first, Node *second, Node *third)
{
    Node *last = NULL;

    if (first->data <= second->data)
    {
        third = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = second;
        last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if (first != NULL)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }

    return third;
}

int main()
{
    int repeat = 1;
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    cout << "Linked list created successfully ! \n";
    cout << "\nselect one of the option \n1. create \n2. display \n3.count no of nodes \n4. sum of all elements \n5. max element \n6. search  \n7.Inserting at first \n8.Inserting after given node \n9. Sorted or not ? \n10. Remove dublicates  \n11. Revesrse the linked list using reversing the elemets  \n12. Reverse the list using sliding pointers \n13. reverse using recursion   \n14. create 2nd list    \n15. Merge the first and second itno the third \n16. Display second \n17. Display third\n";
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
            second = create(second);
            break;

        case 4:
            third = merge(head, second, third);
            break;

        case 14:
            count(head);
            break;

        case 15:
            add(head);
            break;

        case 5:
            maxelement(head);
            break;

        case 6:
            search(head);
            break;

        case 7:
            int num;
            cout << "Enter the no value : ";

            head = insertAtFirst(head, num);

        case 8:
            int num2, pos;
            cout << "Enter the no value : ";

            cin >> num2;
            cout << "Enter the no position of node : ";
            cin >> pos;
            head = insertAtNode(head, num2, pos);

        case 9:
            if (sortedOrNot(head))
            {
                cout << "Linked list is sorted !";
            }
            else
            {
                cout << "LL is not sorted";
            }
            break;

        case 10:
            head = removeDub(head);
            break;

        case 11:
            reverseUsingElement(head);
            break;

        case 12:
            head = reverseUsingSlidingPoi(head);

        case 13:
            head = reverseUsingRecursion(head);

        case 16:
            display(second);
            break;

        case 17:
            display(third);
            break;

        default:
            break;
        }

    } while (repeat);

    return 0;
}
