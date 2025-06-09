#include <iostream>

using namespace std;
//---heapSort--
void heapify(int arr[], int n, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

//---treeSort---
struct Node
{
    int key;
    struct Node* left, * right;
};

struct Node* newNode(int item)
{
    struct Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void storeSorted(Node* root, int arr[], int& i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void treeSort(int arr[], int n)
{
    struct Node* root = NULL;

    root = insert(root, arr[0]);
    for (int i = 1; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    int i = 0;
    storeSorted(root, arr, i);
}

//демонстрация
int main()
{
    int arr[] = { 4, 10, 3, 5, 1, 0, 7, 8 };
    heapSort(arr, size(arr));
    for (int i = 0; i < size(arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    int arr2[] = { 4, 10, 3, 5, 1, 0, 7, 8 };
    treeSort(arr2, size(arr2));
    for (int i = 0; i < size(arr); i++)
    {
        cout << arr2[i] << " ";
    }
}