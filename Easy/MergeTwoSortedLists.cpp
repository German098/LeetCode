#include <iostream>

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	bool end;
	ListNode *i, *ip, *j, *jp, *res;

	if(!list1) return list2;
	if(!list2) return list1;

	end = false;
	if(list1->val <= list2->val){
		i = ip = list1;
		j = jp = list2;
	}
	else{
		i = ip = list2;
		j = jp = list1;
	}
	res = i;
		
	while(!end){	
		while(i->val <= j->val){
			ip = i;
			if(!i->next) {
				end = true;
				ip->next = j;
				break;
			}
			i = i->next;
		}
		if(!end)
			ip->next = j;
	
		while(!end && j->val <= i->val){
			jp = j;
			if(!j->next) {
				end = true;
				jp->next = i;
				break;
			}
			j = j->next;
		}
		if(!end)
			jp->next = i;
	}

	return res;
}

int main(int argc, char const *argv[])
{
	ListNode *l11, *l12, *l13, *l21, *l22, *l23;

	l11 = new ListNode(1, l12);
	l12 = new ListNode(2, l11);
	l13 = new ListNode(4);

	l21 = new ListNode(1, l22);
	l22 = new ListNode(3, l21);
	l23 = new ListNode(4);

	std::cout<<mergeTwoLists(l11, l21)<<std::endl;

	delete l11;
	delete l12;
	delete l13;

	delete l21;
	delete l22;
	delete l23;

	return 0;
}