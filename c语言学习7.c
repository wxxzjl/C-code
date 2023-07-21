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
