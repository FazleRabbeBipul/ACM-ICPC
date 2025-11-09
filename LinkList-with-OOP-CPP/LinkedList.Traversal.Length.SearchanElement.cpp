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

int LengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }

    return cnt;
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

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 5, 8, 9};

    // // Node y = Node(arr[0], nullptr);
    // Node *x = new Node(arr[0], nullptr);
    // // cout << y.data << endl;
    // cout << x->data << endl;

    Node *head = ArrayToLL(arr);

    TravarseLL(head);
    cout << endl;
    cout << "total length : " << LengthOfLL(head) << endl;
}