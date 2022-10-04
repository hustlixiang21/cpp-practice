#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//节点模板，定义成这样方便测试，如果val和next的名字不一样，全文搜索替换一下就行
struct LinkNode
{
	int val;
	LinkNode *next;
	LinkNode(int x) : val(x), next(nullptr) {}
	LinkNode(int x, LinkNode *ptr) : val(x), next(ptr) {}
};

//使用方法
//将关键函数放在这里，结果以链表 （LinkNode*）的形式返回
LinkNode *mergeTwoLists(LinkNode *list1, LinkNode *list2)
{
	LinkNode *head = new LinkNode(-1); //创建一个哑点，省去条件判断
	LinkNode *tail = head;
	while (list1 != nullptr && list2 != nullptr)
	{
		if (list1->val <= list2->val)
		{
			tail->next = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	if (list1 == nullptr)
		tail->next = list2;
	if (list2 == nullptr)
		tail->next = list1;

	return head->next;
}

struct LinkNode
{
	int val;
	LinkNode *next;
};



LinkNode *reverseList(LinkNode *head) //递归reverse函数
{
	if (head == nullptr || head->next == nullptr)
		return head;
	LinkNode *last = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return last;
}

int main()
{
	//通过快慢指针找到中间
	LinkNode *slow = nullptr;
	LinkNode *fast = nullptr;
	while(fast != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	slow->next = reverseList(slow->next);
	return 0;
}

//测试数据文件，第一行代表样例数目
//接下来每三行分别代表 第一条链表 第二条链表以及结果
//每行的第一个数字代表链表长度
const char path[] = "TEST.dat";

int main()
{
	//把Merge和Reverse分别改为你的单链表合并函数和单链表逆置函数的名字
	LinkNode *(*funA)(LinkNode *, LinkNode *) = mergeTwoLists;
	LinkNode *(*funB)(LinkNode *) = reverseList;

	ifstream file;
	file.open(path, ios::in);
	int count;
	file >> count;
	for (int i = 0; i < count; i++)
	{
		int nums;
		file >> nums;
		file.get();
		vector<int> numA;
		LinkNode *LinkA = nullptr;
		LinkNode *OperA = LinkA;
		for (int j = 0; j < nums; j++)
		{
			int num;
			file >> num;
			file.get();
			if (OperA)
			{
				OperA->next = new LinkNode(num, nullptr);
				OperA = OperA->next;
			}
			else
			{
				OperA = new LinkNode(num, nullptr);
				LinkA = OperA;
			}
			numA.push_back(num);
		}

		file >> nums;
		file.get();
		vector<int> numB;
		LinkNode *LinkB = nullptr;
		LinkNode *OperB = LinkB;
		for (int j = 0; j < nums; j++)
		{
			int num;
			file >> num;
			file.get();
			if (OperB)
			{
				OperB->next = new LinkNode(num, nullptr);
				OperB = OperB->next;
			}
			else
			{
				OperB = new LinkNode(num, nullptr);
				LinkB = OperB;
			}
			numB.push_back(num);
		}

		LinkNode *result = funB(funA(LinkA, LinkB));
		int count = 0;
		file >> nums;
		file.get();
		while (result && !file.eof())
		{
			int num;
			file >> num;
			file.get();
			if (num != result->val)
				break;
			LinkNode *del = result;
			result = result->next;
			delete del;
			count++;
		}

		if (count == nums)
			cout << "通过测试用例" << i + 1 << endl;
		else
		{
			cout << "未测试用例" << i + 1 << endl;
			cout << "第一条链表" << endl;
			for (auto begin = numA.begin(); begin != numA.end(); begin++)
				cout << *begin << "->";
			cout << endl;
			cout << "第二条链表" << endl;
			for (auto begin = numB.begin(); begin != numB.end(); begin++)
				cout << *begin << "->";
			cout << endl;
		}
		cout << endl;
	}
}