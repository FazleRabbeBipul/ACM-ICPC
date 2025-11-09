#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const long long mod = 1e9 + 7;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
const long long maxN = 2e5 + 5;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long int, long long int>

#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define show(x) cout << #x << " : " << x << endl

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

Node *removek(Node *head, int k)
{
    if (k == 1)
    {
        Node *temp = head;
        head = temp->next;
        free(temp);

        return head;
    }

    int cnt = 1;
    Node *temp = head;
    Node *pre = NULL;

    while (temp->next != NULL)
    {
        if (k == cnt)
        {
            pre->next = temp->next;
            free(temp);
            break;
        }
        pre = temp;
        temp = temp->next;
        cnt++;
    }

    return head;
}

Node *removeEL(Node *head, int val)
{
    Node *temp = head;
    Node *pre = NULL;

    if (head->data == val)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp->next != NULL)
    {
        if (temp->data == val)
        {
            pre->next = temp->next;
            free(temp);
            break;
        }
        pre = temp;
        temp = temp->next;
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

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 5, 8, 9};

    Node *head = ArrayToLL(arr);

    int k = 2;

    head = removeEL(head, k); // 2 5 8 9  ----> 5 8 9
    head = removek(head, k);  // 5 8 9 -----> 5 9
    TravarseLL(head);
}