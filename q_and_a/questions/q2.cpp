#include <iostream>
#include <cassert>

void get_q_r(int x, int y, int *q_v, int *r_v) {
	assert((0 <= x) && (y > 0));	// Avoid negative x otherwise it fails
	int r = x, q = 0;
	while (r >= y) {	// Check r >= y
		r = r - y; q = q += 1;
	}
	assert((x == y * q + r) && (r < y));	// Also assert if remainder is not less than divisor

	*q_v = q;
	*r_v = r;
}

int main() {
	int q, r;
	get_q_r(6, 3, &q, &r);
	std::cout << "q: " << q << " r: " << r << std::endl;
	return 0;
}

/*
Output:

q: 2 r: 0
*/

/*
It should be:
    while(r >= q)
*/