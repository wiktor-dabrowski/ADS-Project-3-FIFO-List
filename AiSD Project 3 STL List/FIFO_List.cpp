#include "FIFO_List.h"

FIFO_List::FIFO_List() {

}
FIFO_List::~FIFO_List() {
	lst.clear();
}

void FIFO_List::add_beg(int value) {
	lst.emplace_front(value);
}
void FIFO_List::add_end(int value) {
	lst.emplace_back(value);
}

void FIFO_List::del_beg() {
	del(lst.begin());
}
void FIFO_List::del_end() {
	del(--lst.end());
}

void FIFO_List::print_forward() {
	if (lst.empty())
		cout << "NULL" << endl;
	else {
		list<int>::iterator it = lst.begin();
		for (int i = 0; i < lst.size(); ++i) {
			print_value(it);
			cout << " ";
			it = it_next(it);
		}
		cout << endl;
	}
}
void FIFO_List::print_backward() {
	if (lst.empty())
		cout << "NULL" << endl;
	else {
		list<int>::iterator it = --lst.end();
		for (int i = 0; i < lst.size(); i++) {
			print_value(it);
			cout << " ";
			it = it_prev(it);
		}
		cout << endl;
	}
}
void FIFO_List::size() {
	cout << lst.size() << endl;
}


void FIFO_List::push(int value) {
	list<int>::iterator act = back;
	if (queue_empty) {
		if (lst.empty()) {
			lst.emplace_front(value);
			act = lst.begin();
		}
		else {
			act = --lst.end();
			*act = value;
		}

		front = act;
		back = act;
		queue_empty = false;
	}
	else if(it_prev(back) == front){
		back = lst.emplace(act, value);
	}
	else {
		act = it_prev(act);
		*act = value;
		back = act;
	}
}
void FIFO_List::pop() {
	if (queue_empty)
		cout << "NULL" << endl;
	else {
		print_value(front);
		cout << endl;
		if (front == back)
			queue_empty = true;
		front = it_prev(front);
	}
}

void FIFO_List::print_queue() {
	if (queue_empty)
		cout << "NULL" << endl;
	else {
		list<int>::iterator it = front;
		if (front != back) {
			do {
				print_value(it);
				cout << " ";

				it = it_prev(it);
			} while (it != back);
		}
		print_value(it);
		cout << endl;
	}
}
void FIFO_List::count() {
	cout << count_help() << endl;
}

void FIFO_List::garbage_soft() {
	if (!lst.empty()) {
		if (!count_help()) {
			list<int>::iterator it = lst.begin();
			for (int i = 0; i < lst.size(); i++) {
				*it = 0;
				it = it_next(it);
			}
		}
		else {
			list<int>::iterator it = it_next(front);
			while (it != back) {
				*it = 0;
				it = it_next(it);
			}
		}
	}
}
void FIFO_List::garbage_hard() {
	garbage_soft();
	lst.remove(0);
}

void FIFO_List::print_value(list<int>::iterator it) {
		cout << *it;
}

list<int>::iterator FIFO_List::it_next(list<int>::iterator it) {
	list<int>::iterator next = it;
	if (next == --lst.end())
		next = lst.begin();
	else
		++next;
	return next;
}
list<int>::iterator FIFO_List::it_prev(list<int>::iterator it) {
	list<int>::iterator prev = it;
	if (prev == lst.begin())
		prev = --lst.end();
	else
		--prev;
	return prev;
}

int FIFO_List::count_help() {
	int size = 0;
	list<int>::iterator it = front;
	if (!queue_empty) {
		if (front != back) {
			while (it != back) {
				++size;

				it = it_prev(it);
			}
		}
		++size;
	}

	return size;
}
void FIFO_List::del(list<int>::iterator to_del) {
	if (!lst.empty()) {
		if (!queue_empty) {
			if (to_del == front && to_del == back)
				queue_empty = true;
			if (to_del == front)
				front = it_prev(front);
			if (to_del == back)
				back = it_next(back);
		}
		
		lst.erase(to_del);
	}
}