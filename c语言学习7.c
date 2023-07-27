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


//左旋字符串
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <assert.h>
#include <string.h>
void start_Move(char arr[], int step) {
	assert(arr != NULL);
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < step; i++) {
		int j = 0;
		char left = *arr;
		for (j = 0; j < len-1; j++) {
			*(arr + j) = *(arr + j + 1);
		}
		*(arr + len - 1) = left;
	}
};
int main() {
	char arr[] = "abcdef";
	int step = 0;
	printf("请输入左旋转步数：");
	scanf("%d", &step);
	start_Move(arr, step);
	printf("%s", arr);
	return 0;
}


//优化
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <assert.h>
#include <string.h>
void reverse(char* left, char* right) {
	assert(left != NULL);
	assert(right != NULL);
	char temp = *left;
	*left = *right;
	*right = temp;
}
void left_move(char*arr,int step) {
	assert(arr);
	int len = strlen(arr);
	assert(step <= len);
	reverse(arr,arr+step-1);//逆序左边
	reverse(arr+step,arr+len-1);//逆序右边
	reverse(arr,arr+len-1);//逆序全部
}
int main() {
	char arr[] = "abcdef";
	int step = 0;
	printf("请输入左移步数：");
	scanf("%d", &step);
	left_move(arr, step);
	printf("%s", arr);
	return 0;
}


/判断字符串是否是通过左旋得到
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <assert.h>
#include <string.h>
void reverse(char* left, char* right) {
	assert(left != NULL);
	assert(right != NULL);
	char temp = *left;
	*left = *right;
	*right = temp;
}
void left_move(char*arr,int step) {
	assert(arr);
	int len = strlen(arr);
	assert(step <= len);
	reverse(arr,arr+step-1);//逆序左边
	reverse(arr+step,arr+len-1);//逆序右边
	reverse(arr,arr+len-1);//逆序全部
}
int is_left_move(char* s1, char* s2) {
	int i = 0;
	int len = strlen(s1);
	for (i = 0; i <len ; i++) {
		left_move(s1, 1);
		int ret = strcmp(s1, s2);
		if (ret == 0)
			return 1;
	}
	return 0;
}
int main() {
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1) 
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}


//优化
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <assert.h>
#include <string.h>
int is_left_move(char* s1, char* s2) {
	int i = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)
		return 0;
	//1在s1添加一个自己
	//strcat(s1,s1);err
	//strncat
	strncat(s1, s1, 6);
	//2判断s2指向的字符串是否是s1的子串
	char* ret = strstr(s1, s2);
	if (ret == NULL)
		return 0;
	else
		return 1;
}
int main() {
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1) 
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}


//运行程序奔溃，程序存在内存泄漏问题
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void getMemory(char* p)
{
	p = (char*)malloc(100);//p是形参出去就销毁，没释放且找不到->内存泄漏
}
void test(void)
{
	char* str = NULL;
	getMemory(str);//依然为NULL
	strcpy(str, "hello world");//非法访问内存
	printf(str);
}
int main() {
	test();
	return 0;
}
