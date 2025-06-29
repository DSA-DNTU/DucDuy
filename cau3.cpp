#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct LinkedList
{
	Node* head;
	Node* tail;
};

Node* CreateNode(int init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}

void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void AddTail(LinkedList& l, int x)
{
    Node* node = CreateNode(x);
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}

void PrintList(LinkedList l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			cout << node->data << " -> ";
			node = node->next;
		}
	}
    cout << "NULL" << endl;
}

int main()
{
    LinkedList list;
    CreateList(list);
    
    // Danh sách ban đầu: 1 -> 2 -> NULL, thêm 3
    AddTail(list, 1);
    AddTail(list, 2);
    AddTail(list, 3); // thêm phần tử mới

    cout << "Danh sach sau khi them 3: ";
    PrintList(list); // Kết quả: 1 -> 2 -> 3 -> NULL

    // Danh sách rỗng ban đầu, thêm 5
    LinkedList emptyList;
    CreateList(emptyList);
    AddTail(emptyList, 5);

    cout << "Danh sach ban dau rong, sau khi them 5: ";
    PrintList(emptyList); // Kết quả: 5 -> NULL

    return 0;
}