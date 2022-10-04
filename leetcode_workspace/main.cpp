class Solution
{
public:
    struct Status
    {
        int val;
        ListNode *ptr;
        bool operator<(const Status &rhs)
        {
            return val > rhs.val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        //需要创建一个优先级队列
        priority_queue<Status> q;
    }
};