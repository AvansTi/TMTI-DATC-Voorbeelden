#include <iostream>
#include <string>
#include "LinkedList.h"

int main()
{
	{
		LinkedList<double> linkedlist;
		linkedlist.insertFront(10.0);
		linkedlist.insertFront(20.0);
		//linkedlist.insertEnd(12.1);
	}
	{
		LinkedList<std::string> linkedlist;
		linkedlist.insertFront("");
	}

	//cout << "LinkedList size: " << lList.size();


	return 0;
}

