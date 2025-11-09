#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *ArrayToLL(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *cur = new Node(arr[i]);
        mover->next = cur;

        mover = cur;
    }

    return head;
}

void TravarseLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *insertionFront(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    return temp;
}

Node *insertionBack(Node *head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;

    if (head == NULL)
        return newNode;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

Node *insertionKth(Node *head, int k, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        if (k == 1)
        {
            return newNode;
        }
    }

    if (k == 1)
    {
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;
    int cnt = 1;

    while (temp != NULL)
    {
        if (cnt == k - 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
        cnt++;
    }
    return head;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 5, 8, 9};

    Node *head = ArrayToLL(arr);
    head = insertionFront(head, 1); // 2 5 8 9 -----> 1 2 5 8 9
    head = insertionBack(head, 12); // 1 2 5 8 9 ----> 1 2 5 8 9 12

    int k = 3, val = 4;
    head = insertionKth(head, k, val); // 1 2 5 8 9 12 -----> 1 2 *4 5 8 9 12

    TravarseLL(head);
}