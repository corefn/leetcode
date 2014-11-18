/*
 * Author : Feng Wei
 * Date   : Nov 17, 2014
 *
 * You are given two linked lists representing two non-negative numbers.
 *
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 *
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *
 * Output: 7 -> 0 -> 8
 */

#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 * this problem is easy to solve, p1 points to l1 and p2 points to l2:
 *
 * 	1. if p1 != NULL and p2 != NULL, sum = *p1 + *p2 + carry;
 *
 * 	2. if p1 = NULL or p2 == NULL, sum = 0 + *p1 + carry or sum = *p1 + 0 + carry.
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int num1	= 0;
		int num2	= 0;
		int carry	= 0;

		ListNode *head	= NULL;
		ListNode *p	= NULL;

		ListNode *head_of_l1 = l1;
		ListNode *head_of_l2 = l2;

		while (head_of_l1 != NULL || head_of_l2 != NULL) {
			num1 = GetValueAndMoveNext(&head_of_l1); 
			num2 = GetValueAndMoveNext(&head_of_l2);

			int sum = num1 + num2 + carry;
			ListNode *node = new ListNode(sum % 10);

			if (head == NULL) {
				head = p = node;
			} else {
				p->next = node;
				p = node;
			}
			
			carry = sum / 10;
		}
		while (carry > 0) {
			ListNode *node = new ListNode(carry % 10);
			p->next = node;
			carry /= 10;
		}

		return head;
    }

private:
	int GetValueAndMoveNext(ListNode **rhs)
	{
		int value = 0;
		if ((*rhs) != NULL) {
			value = (*rhs)->val;
			*(rhs) = (*rhs)->next;
		}

		return value;
	}
};

int main()
{
	Solution s;
	ListNode *test1 = new ListNode(1);
	ListNode *test2 = new ListNode(8);
	//ListNode *test3 = new ListNode(3);
	test1->next = test2;
	//test2->next = test3;

	ListNode *test4 = new ListNode(0);
	//ListNode *test5 = new ListNode(6);
	//ListNode *test6 = new ListNode(4);
	//test4->next = test5;
	//test5->next = test6;

	ListNode * result = s.addTwoNumbers(test1, test4);

	while(result != NULL) {
		cout << result->val <<" ";
		result = result->next;
	}
	return 0;
}
