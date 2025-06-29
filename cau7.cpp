#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

struct Stack
{
    Node *top;
};

Node *createNode(int x) // Khởi tạo một node
{
    Node *p = new Node;
    if (p == NULL)
    {
        return 0;
    }
    p->info = x;
    p->next = NULL;
    return p;
}

void initStack(Stack &s)
{
    s.top = NULL;
}

int isEmpty(Stack s)
{
    if (s.top == NULL)
    {
        return 1; // stack đang rỗng
    }
    return 0; // stack có phần tử
}

int Push(Stack &s, Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (isEmpty(s) == 1)
    {
        s.top = p;
    }
    else
    {
        p->next = s.top;
        s.top = p;
    }
    return 1;
}

int Pop(Stack &s, int &x)
{
    if (isEmpty(s) == 1)
    {
        return 0;
    }
    Node *p = s.top;
    s.top = s.top->next;
    x = p->info;
    delete p;
    return 1;
}

int tinhgiaithua(int x)
{
    Stack s;
    int z;
    int y = 1;
    initStack(s); // Khởi tạo stack ban đầu = null

    while (x != 0)
    {
        Node *p = createNode(x);
        Push(s, p); // thêm phần tử vào stack
        x = x - 1;  // mỗi lần lặp giảm đi 1
    }
    while (s.top != NULL) // stack khác rỗng
    {
        Pop(s, z); // lấy phần tử ra khỏi stack
        y = y * z * 1;
    }
    return y;
}


int main()
{
    int x;
    cout << "Nhập x = ";
    scanf("%d", &x);
    cout << "Giai thừa "<< x <<" = " <<  tinhgiaithua(x);
    return 0;
}