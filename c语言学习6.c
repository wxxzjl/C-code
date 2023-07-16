//例题
//输出：-1 -1 255(整型提升，有无符号位)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("%d %d %d ", a, b, c);
	return 0;
}
