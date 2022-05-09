#include "currency.h"
#include "dollar.h"

class LinkNode
{
public:
	Currency * data;
	LinkNode* next;
};

class SinglyLinkedList
{
private:
	SinglyLinkedList* count;
	LinkNode* start;
	LinkNode* end;
public:
	SinglyLinkedList* getCount() { return count; };
	void setCount(SinglyLinkedList* x) { count = x; };

	LinkNode* getStart() { return start; };
	void setStart(LinkNode* x) { start = x; };

	LinkNode* getEnd() { return end; };
	void setEnd(LinkNode* x) { end = x; };

	SinglyLinkedList()
	{
	//constructor
	}
	~SinglyLinkedList()
	{
	//destructor
	}

	/*Optional, constructor-like method*/
	//void createList() {}

	/*Optional, destructor-like method*/
	//void destoryList() {}

	void addCurrency(SinglyLinkedList* list, LinkNode* newNode, LinkNode* curNode) 
	{
		if (list->start == NULL)
		{
			list->start = newNode;
			list->end = newNode;
		}
		else if (newNode == list->end)
		{
			list->end->next = newNode;
			list->end = newNode;
		}
		else 
		{
			newNode->next = curNode->next;
			curNode->next = newNode;
		}
	}

	Currency removeCurrency(SinglyLinkedList* list, Currency* curCurrency)
	{
		LinkNode* sucNode;
		if (curCurrency == NULL && list->start != NULL)
		{
			sucNode = list->start->next;
			list->start = sucNode;

			if (sucNode == NULL)
				list->end = NULL;
		}
		
	}

};



int main()
{
	std::cout << "Welcome to a demonstration of ADTs (abstract data types) " << endl;
	std::cout << "-------Nathan Brunnett------" << endl;
	Currency* array[20];

	//populate array
	for (int i = 0; i < 20; ++i)
	{
		array[i] = new Dollar();
	}


	array[0]->setBills(57); array[0]->setCents(12);
	array[1]->setBills(23); array[1]->setCents(44);
	array[2]->setBills(87); array[2]->setCents(43);
	array[3]->setBills(68); array[3]->setCents(99);
	array[4]->setBills(111); array[4]->setCents(22);
	array[5]->setBills(44); array[5]->setCents(55);
	array[6]->setBills(77); array[6]->setCents(77);
	array[7]->setBills(18); array[7]->setCents(36);
	array[8]->setBills(543); array[8]->setCents(21);
	array[9]->setBills(20); array[9]->setCents(21);
	array[10]->setBills(345); array[10]->setCents(67);
	array[11]->setBills(36); array[11]->setCents(18);
	array[12]->setBills(48); array[12]->setCents(48);
	array[13]->setBills(101); array[13]->setCents(0);
	array[14]->setBills(11); array[14]->setCents(0);
	array[15]->setBills(21); array[15]->setCents(0);
	array[16]->setBills(51); array[16]->setCents(0);
	array[17]->setBills(1); array[17]->setCents(0);
	array[18]->setBills(251); array[18]->setCents(0);
	array[19]->setBills(151); array[19]->setCents(0);
	
	SinglyLinkedList x;
	//Stack y
	//Queue z


	return 0;
}