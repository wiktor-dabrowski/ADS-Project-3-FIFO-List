#include <iostream>
#include <string>
#include "FIFO_List.h"

using namespace std;

int main() {
	FIFO_List list;
	string x;
	int n;
	while (cin >> x) {
		if (x == "ADD_BEG") {
			cin >> n;
			list.add_beg(n);
		}
		else if (x == "ADD_END") {
			cin >> n;
			list.add_end(n);
		}

		else if (x == "DEL_BEG")
			list.del_beg();
		else if (x == "DEL_END")
			list.del_end();

		else if (x == "PRINT_FORWARD")
			list.print_forward();
		else if (x == "PRINT_BACKWARD")
			list.print_backward();
		else if (x == "SIZE")
			list.size();


		else if (x == "PUSH") {
			cin >> n;
			list.push(n);
		}
		else if (x == "POP")
			list.pop();

		else if (x == "PRINT_QUEUE")
			list.print_queue();
		else if (x == "COUNT")
			list.count();

		else if (x == "GARBAGE_SOFT")
			list.garbage_soft();
		else if (x == "GARBAGE_HARD")
			list.garbage_hard();


		else if (x == "Q")
			break;
	}

	return 0;
}