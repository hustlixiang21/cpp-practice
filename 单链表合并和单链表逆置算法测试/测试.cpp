#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//�ڵ�ģ�壬���������������ԣ����val��next�����ֲ�һ����ȫ�������滻һ�¾���
struct LinkNode
{
	int val;
	LinkNode *next;
	LinkNode(int x) : val(x), next(nullptr) {}
	LinkNode(int x, LinkNode *ptr) : val(x), next(ptr) {}
};

//ʹ�÷���
//���ؼ��������������������� ��LinkNode*������ʽ����
LinkNode *mergeTwoLists(LinkNode *list1, LinkNode *list2)
{
	LinkNode *head = new LinkNode(-1); //����һ���Ƶ㣬ʡȥ�����ж�
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



LinkNode *reverseList(LinkNode *head) //�ݹ�reverse����
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
	//ͨ������ָ���ҵ��м�
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

//���������ļ�����һ�д���������Ŀ
//������ÿ���зֱ���� ��һ������ �ڶ��������Լ����
//ÿ�еĵ�һ�����ִ���������
const char path[] = "TEST.dat";

int main()
{
	//��Merge��Reverse�ֱ��Ϊ��ĵ�����ϲ������͵��������ú���������
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
			cout << "ͨ����������" << i + 1 << endl;
		else
		{
			cout << "δ��������" << i + 1 << endl;
			cout << "��һ������" << endl;
			for (auto begin = numA.begin(); begin != numA.end(); begin++)
				cout << *begin << "->";
			cout << endl;
			cout << "�ڶ�������" << endl;
			for (auto begin = numB.begin(); begin != numB.end(); begin++)
				cout << *begin << "->";
			cout << endl;
		}
		cout << endl;
	}
}