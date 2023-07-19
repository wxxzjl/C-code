//例题
//输出：-1 -1 255 4294967168(整型提升，有无符号位)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	char a = -1;
	//内存中存的是补码
	//-1的补码：11111111111111111111111111111111
	//因为是char类型，内存中存的是一个字节：11111111
	//以%d打印要整型提升高位要补到四个字节，高位补符号位。
	//11111111111111111111111111111111----补码(内存中存的)
	//打印要转换成原码
	//10000000000000000000000000000001----原码(-1)
	char e = -128;
	//内存中存的是补码
	//-128的补码：10000000000000000000000010000000
	//因为是char类型，内存中存的是一个字节：1000000
	//以%u打印要整型提升高位要补到四个字节，高位补符号位。
	//11111111111111111111111110000000----补码(内存中存的)
	//打印要转换成原码,由于%u是打印十进制无符号数字，原反补一样
	//11111111111111111111111110000000----原码(4294967168)
	signed char b = -1;
	//11111111111111111111111111111111----补码(内存中存的)
	//打印要转换成原码
	//10000000000000000000000000000001----原码(-1)
	unsigned char c = -1;
	//无符号数高位补0
	//00000000000000000000000011111111----补码(内存中存的)
	//打印要转换成原码
	//00000000000000000000000011111111----原码(255)
	printf("%d %d %d %u ", a, b, c, e);
	return 0;
}


//例题
//答案：死循环
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
int main() {
	unsigned int i;	//-1放到无符号里是一个超级大的数
	for (i = 9; i >= 0; i--) {
		printf("%u\n", i);
		Sleep(1000);	//休息1s
	}
	return 0;	
}


//例题
//答案：255
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++) {
		a[i] = -1 - i;//-1--->-128--->127--->1--->0停止
	}
	printf("%d\n", strlen(a));//char打印成%d要截断
	return 0;	
}

//例题
//答案：死循环
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
unsigned char i = 0;//0-255
int main() {
	for (i = 0; i <= 255; i++) {	//恒成立
		printf("hello world\n");
	}
	return 0;	
}


//答案n的值为9
//* pfloat的值为0.000000
//n的值为1091567616
//* pfloat的值为9.000000
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n = 9;
	float* pfloat = (float*)&n;
	printf("n的值为%d\n", n);
	printf("* pfloat的值为%f\n", * pfloat);
	*pfloat = 9.0;
	printf("n的值为%d\n", n);
	printf("* pfloat的值为%f\n", *pfloat);
	return 0;	
}


//例题
(*(void (*)())0)();
//(void (*)()函数指针类型
//把0 int类型强转成函数指针类型-0就是一个函数地址
//调用0地址处的该函数

void(*signal(int, void(*)(int)))(int);
//函数指针里函数指针
//解释：signal是一个函数声明
//signal函数的参数有两个，第一个int，第二个函数指针，该函数指针指向的函数参数是int，返回类型是void。
//signal函数的返回类型也是一个函数指针，该函数指针指向的函数参数是int，返回类型是void。
//简化
typedef void(*pf)(int);
pf signal(int, pf);

//类似
typedef unsigned uint;
