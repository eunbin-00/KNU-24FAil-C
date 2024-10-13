#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main() {
	double x = 0;
	double y = 0;
	double pi;

	int count = 0 , circle = 0;
	int per=1;

	srand(time(NULL));

	while (count < 1000000000) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand()  / (double)RAND_MAX;
		count++;
		if ( sqrt( x*x + y*y) < 1) {
			circle++;
		}
		if (count % 10000000 == 0) {
			pi = ((double) circle / count) * 4;
			printf("%d%%진행.. 원주율: %f", per, pi);
			per++;
			
			int percent = count / 10000000;
			for (int j = 0; j < percent / 5; j++) {
				printf("■");
			}

			for (int j = 0; j < 20 - percent / 5; j++) {
				printf("□");
			}
			printf("\n");
		}

	}
	printf("원주율: %f", pi);
	return 0;
}

