#include <stdio.h>
#include <math.h>



int main(){

	int array[4] = { 1,1,0,1 };
	int count = 0;
	double pow_sum = 0;

	for (int i = sizeof(array) / sizeof(int) - 1; i >= 0; i--) {
		if (array[i]) {
			pow_sum += pow(2, count);
		}
			count++;
	}
	printf("%.0f", pow_sum);

	return 0;
}