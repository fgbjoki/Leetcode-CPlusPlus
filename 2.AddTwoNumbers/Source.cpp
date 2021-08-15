#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    bool overFlowValueModification(int* value, bool overflow)
    {
        if (overflow)
        {
            ++(*value);
        }

        if (*value >= 10)
        {
            *value %= 10;
            return true;
        }
        else
        {
            return false;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newList = NULL;
        ListNode* newTail = NULL;

        bool overflow = false;
        for (; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next)
        {
            int newNumber = l1->val + l2->val;

            listAdditionCreation(overflow, newNumber, newList, newTail);
        }

        for (; l1 != NULL; l1 = l1->next)
        {
            int newNumber = l1->val;

            listAdditionCreation(overflow, newNumber, newList, newTail);
        }

        for (; l2 != NULL; l2 = l2->next)
        {
            int newNumber = l2->val;

            listAdditionCreation(overflow, newNumber, newList, newTail);
        }

        if (overflow)
        {
            int newNumber = 0;
            listAdditionCreation(overflow, newNumber, newList, newTail);
        }

        return newList;
    }
    void listAdditionCreation(bool& overflow, int& newNumber, ListNode*& newList, ListNode*& newTail)
    {
        overflow = overFlowValueModification(&newNumber, overflow);

        ListNode* newNode = new ListNode(newNumber);

        if (newList == NULL)
        {
            newList = newNode;
            newTail = newNode;
        }
        else
        {
            newTail->next = newNode;
            newTail = newNode;
        }
    }
};