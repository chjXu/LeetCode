#include <iostream>
using namespace std;

struct Tree{
    int val;
    Tree *left;
    Tree *right;
    Tree():val(0), left(nullptr), right(nullptr){}
    Tree(int x):val(x), left(nullptr), right(nullptr){}
    Tree(int x, Tree *left, Tree *right):val(x), left(left), right(right){}
}

int main()
{
    Tree t1 = Tree(0);
    Tree t2 = Tree(1);

    cout << t1.left << endl;

    return 0;
}