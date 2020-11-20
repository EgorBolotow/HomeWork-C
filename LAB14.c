#include "stdio.h"

void swapInt(int* x, int* y){
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void swapPointers(void **x, void **y){
	void *t = *x;
	*x = *y;
	*y = t;
}

int main(int argc, char** argv){
	int x = 5;
	int y = 10;

	printf("%d %d\n", x, y);
	swapInt(&x, &y);
	printf("%d %d\n", x, y);

	char *a = "hi";
	char *b = "hello";
	printf("%s %s\n", a, b);
	swapPointers((void**)&a, (void**)&b);
	printf("%s %s\n", a, b);
	return 0;
}
