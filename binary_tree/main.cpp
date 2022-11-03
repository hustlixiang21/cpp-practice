#include <iostream>
#include <queue>

using namespace std;


template <class T>
class BinaryTreeNode  //二叉树的结点类型
{
public:
    //三个构造函数的重载
    BinaryTreeNode() {LeftChild = RightChild = nullptr;}
    BinaryTreeNode(const T& e) {data = e; LeftChild = RightChild = nullptr;}
    BinaryTreeNode(const T& e, BinaryTreeNode *l,BinaryTreeNode *r){data = e; LeftChild = l; RightChild = r;}

    //数据域
    T data;
    BinaryTreeNode<T> *LeftChild;  //左孩子
    BinaryTreeNode<T> *RightChild; //右孩子
};

template <class T>
class BinaryTree
{
public:
    BinaryTree() {root = new BinaryTreeNode<T>();}  //构造函数

    ~BinaryTree() = default;  //析构函数

    bool IsEmpty() const{return !(root);}  //判断树是否为空

    void Change_Root(T x,BinaryTreeNode<T> *left,BinaryTreeNode<T> *right); //如果根结点存在的话，则为其数据域赋值x

    void PreOrder(BinaryTreeNode<T> *t); //前序遍历

    void InOrder(BinaryTreeNode<T> *t);  //中序遍历

    void PostOrder(BinaryTreeNode<T> *t);  //后序遍历

    void SwapTree(BinaryTreeNode<T> *t);  //交换树的左孩子和右孩子，递归交换

    void Find(BinaryTreeNode<T> *t,T key,int &flag); //查找值为key的结点，并输出该结点的所有祖先结点

    BinaryTreeNode<T> *PreOrder_input(); //实现前序输入创建一个二叉树

    BinaryTreeNode<T> *LevelOrder_input(); //实现层次输入创建一个二叉树

    BinaryTreeNode<T> *PIOrderCreateTree(const char* t1,int &c2,char* t2);  //利用前序和中序创建一个唯一的二叉树

    static void Visit(BinaryTreeNode<T> *t){cout << t->data << ' ';}  //用于访问并打印结点的数据域

    //数据域
    BinaryTreeNode<T> *root;  //私有数据包括树的根结点
};
//ABC##DE#G##F###
//ABC##DE#G##F###
int main()
{
    BinaryTree<char> BiTree1;
    cout << "前序输入：";
    BinaryTreeNode<char> *root_node1 =  BiTree1.PreOrder_input();
    BiTree1.Change_Root(root_node1->data,root_node1->LeftChild,root_node1->RightChild);
    cout << "前序遍历：";
    BiTree1.PreOrder(BiTree1.root);
    cout << endl;

    BinaryTree<char> BiTree2;
    cout << "层次输入：";
    BinaryTreeNode<char> *root_node2 =  BiTree2.LevelOrder_input();
    BiTree2.Change_Root(root_node2->data,root_node2->LeftChild,root_node2->RightChild);
    cout << "前序遍历：";
    BiTree2.PreOrder(BiTree2.root);
    cout << endl;

    //层次输入树和
    BiTree1.SwapTree(BiTree1.root);
    cout << "交换前序输入树左子树和右子树并进行前序遍历：";
    BiTree1.PreOrder(BiTree1.root);
    cout << endl;
    BiTree2.SwapTree(BiTree2.root);
    cout << "交换层次输入树左子树和右子树并进行前序遍历：";
    BiTree1.PreOrder(BiTree1.root);
    cout << endl;

    int flag = 0;
    cout << "前序构造树E的祖先：";
    BiTree1.Find(BiTree1.root,'E',flag);
    cout << endl;
    cout << "层次构造树E的祖先：";
    BiTree2.Find(BiTree2.root,'E',flag);
    cout << endl;
    return 0;
}


template <class T>
void BinaryTree<T>::Change_Root(T x,BinaryTreeNode<T> *left,BinaryTreeNode<T> *right)
{
        root->data = x;
        root->LeftChild = left;
        root->RightChild = right;
}

template <class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *t)
{ // 前序遍历
    if (t)
    {
        Visit(t);
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

template <class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> *t)
{ // Inorder traversal.
    if (t)
    {
        InOrder(t->LeftChild);
        Visit(t);
        InOrder(t->RightChild);
    }
}

template <class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *t)
{ // Postorder traversal.
    if (t)
    {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        Visit(t);
    }
}

template <class T>
void BinaryTree<T>::SwapTree(BinaryTreeNode<T> *t)
{
    if (t)
    {
        BinaryTreeNode<char> *left;
        BinaryTreeNode<char> *right;
        left = t->LeftChild;
        right = t->RightChild;
        t->LeftChild = right;
        t->RightChild = left;
        SwapTree(t->LeftChild);
        SwapTree(t->RightChild);
    }
}


template <class T>
BinaryTreeNode<T> *BinaryTree<T>::PIOrderCreateTree(const char *t1 ,int &c2, char *t2)
{
    auto *root =  new BinaryTreeNode<T> ;
    int index = 0;
    int index1 = 0;
    int index2 = 0;
    char *LeftTemp1 = new char[64];
    char *RightTemp1 = new char[64];
    char *LeftTemp2 = new char[64];
    char *RightTemp2 = new char[64];
    if (c2 == 0)
        return 0;
    else if (c2 == 1)
    {
        root->data = t1[0];
        return root;
    }
    else
    {
        root->data = t1[0];
        for (index = 0; index < strlen(t2); index++)
        {
            if (t1[0] == t2[index])
            {
                index1 = index;
                break;
            }
        }
        for (int i = 0; i < index1; i++)
        {
            LeftTemp1[i] = t1[i + 1];
            RightTemp1[i] = t2[i];
        }
        index2 = c2 - index1 - 1;
        for (int j = 0; j < index2; j++)
        {
            LeftTemp2[j] = t1[j + index1 + 1];
            RightTemp2[j] = t2[j + index1 + 1];
        }
        root->LeftChild = PIOrderCreateTree(LeftTemp1, index1, RightTemp1);
        root->RightChild = PIOrderCreateTree(LeftTemp2, index2, RightTemp2);
        return root;
    }
}

template<class T>
void BinaryTree<T>::Find(BinaryTreeNode<T> *t,T key,int &flag)
{
    if(flag == 1 || t == nullptr)
        return;
    else
    {
        Find(t->LeftChild,key,flag);
        Find(t->RightChild,key,flag);

        if(t->data == key)        //如果当前结点是x，则更换标志位
            flag = 1;

        if(flag == 1 && t->data != key)
        {
            cout<<t->data<<" ";

            if(t == root)         //如果输出到根结点，则再次更换标志位，否则可能会输出根节点右子树的元素（如果x在左子树的情况下）
                flag = 0;
        }
    }
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::PreOrder_input()
{
    BinaryTreeNode<T> *node;
    char x;
    cin >> x;
    if (x == '#') {
        return nullptr;
    }
    else
    {
        node = new BinaryTreeNode<T>();
        //开创结点空间
        node->data = x;
        node->LeftChild = PreOrder_input();
        node->RightChild = PreOrder_input();
    }
    return node;
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::LevelOrder_input()
{
    T input;
    queue<BinaryTreeNode<T>*> q;
    cin >> input;
    if (input == '#')    //如果第一个节点为空，就直接返回空树
        return nullptr;
    auto *root_node = new BinaryTreeNode<T>();
    root_node->data = input;
    q.push(root_node);      //根节点入队
    while (!q.empty())
    {
        BinaryTreeNode<T> *p = q.front();
        q.pop();
        cin >> input;
        if(input == '#')
            p->LeftChild = nullptr;
        else
        {
            p->LeftChild = new BinaryTreeNode<T>();
            p->LeftChild->data = input;
            q.push(p->LeftChild);  //左孩子入队
        }
        cin >> input;
        if (input == '#')   //右孩子为空
            p->RightChild = nullptr;
        else
        {
            p->RightChild = new BinaryTreeNode<T>();
            p->RightChild->data = input;
            q.push(p->RightChild);  //右孩子入队
        }
    }
    return root_node;
}

