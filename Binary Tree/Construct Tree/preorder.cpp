#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

Node *constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *root = NULL;
        int n;
        cin >> n;
        int pre[n];
        char preLN[n];
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        for (int i = 0; i < n; i++)
            cin >> preLN[i];
        root = constructTree(n, pre, preLN);
        printInorder(root);
        cout << endl;
    }
    return 0;
}

struct Node *solve(int n, int pre[], char preLN[], int &idx)
{
    if (idx == n)
        return NULL;

    struct Node *root = new Node(pre[idx]);

    if (preLN[idx] == 'L')
    {
        idx++;
        return root;
    }
    idx++;
    root->left = solve(n, pre, preLN, idx);
    root->right = solve(n, pre, preLN, idx);
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    if (n == 0)
        return NULL;
    int idx = 0;
    return solve(n, pre, preLN, idx);
}