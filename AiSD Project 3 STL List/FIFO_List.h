#pragma once
#include <iostream>
#include <list>

using namespace std;

class FIFO_List
{
	list<int> lst;
	list<int>::iterator front, back;
	bool queue_empty = true;

public:
	FIFO_List();
	~FIFO_List();

	void add_beg(int);
	void add_end(int);

	void del_beg();
	void del_end();

	void print_forward();
	void print_backward();
	void size();


	void push(int);
	void pop();

	void print_queue();
	void count();

	void garbage_soft();
	void garbage_hard();

private:
	void print_value(list<int>::iterator);

	list<int>::iterator it_next(list<int>::iterator);
	list<int>::iterator it_prev(list<int>::iterator);

	int count_help();
	void del(list<int>::iterator);
};

