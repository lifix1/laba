#include "processing.h"

double test_avg(Call test[], int n) {
	int total_sec = 0;
	double total_cost = 0;
	for (int i = 0; i < n; i++) {
		total_cost += ceil(test[i].duration / 60.) * test[i].cost;
		total_sec += test[i].duration;
	}
	return total_cost / total_sec;
}