//打印水仙花数（100000以内）
//水仙花数：用来描述一个N位非负整数，其各位数字的N次方和等于该数本身。
//答案：0 1 2 3 4 5 6 7 8 9 153 370 371 407 1634 8208 9474 54748 92727 93084
//比较是否相等
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <math.h>
int main() {
	int i = 0;
	for (i = 0; i < 100000; i++) {
		int n = 1;
		int tmp = i;
		int sum = 0;
		//判断位数
		while (tmp /= 10) {
			n++;
		}
		//计算每一位的n次方之和
		tmp = i;
		while (tmp) {
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		//
		if (i == sum) {
			printf("%d ", i);
		}
	}
	return 0;
}

//打印菱形
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
int main() {
	int line = 0;
	while (1) {
		printf("请输入想要的几行菱形位数(奇数)：");
		scanf("%d", &line);
		if (line % 2 == 0) {
			printf("请输入奇数！谢谢\n");
		}
		else {
			line = (line / 2) + 1;
			break;
		}
	}
	int i = 0;
	for (i = 0; i <= line - 1; i++) {
		int j = 0;
		for (j = 0; j < line - 1 - i; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = line - 1; i >0; i--) {
		int j = 0;
		for (j = 0; j < line-i; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}	
	return 0;
}
