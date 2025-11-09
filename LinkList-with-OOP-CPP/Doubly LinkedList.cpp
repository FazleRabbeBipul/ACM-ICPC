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
    Node *back;

public:
    Node(int data1, Node *back1, Node *next1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *ArrayToDoublyLL(vector<int> &arr)
{
    Node *head = new Node(arr[0], NULL, NULL);

    Node *pre = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], pre, nullptr);
        pre->next = temp;
        pre = temp;
    }
    return head;
}

void TraverseDLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 5, 8, 9};
    Node *head = ArrayToDoublyLL(arr);

    TraverseDLL(head);
}