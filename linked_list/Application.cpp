#include "Application.h"

void Application::start()
{
	LinkedList<int> list;
	list.PushBack(10);
	list.PushBack(20);
	list.PushBack(30);
	list.PushBack(40);
	cout << "list:" << endl;
	list.Show();
	cout << "-----------------------------------------------" << endl;
	LinkedList<int> list2;
	list2.PushBack(5);
	list2.PushBack(15);
	list2.PushBack(25);
	cout << "list2:" << endl;
	list2.Show();
	cout << "-----------------------------------------------" << endl;
	LinkedList<int> list3;
	list3 = list + list2;
	cout << "list3:" << endl;
	list3.Show();
}