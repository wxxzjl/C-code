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

//例题
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
int main() {
	int arr[] = { 1,2,3,4 };
	//数组名是首元素的地址
	//1 sizeof(数组名) 表示：数组名是整个数组，计算的是整个数组的大小，单位字节
	//2 & 数组名，数组名代表整个数组，取出的是整个数组的地址
	printf("%d\n", sizeof(arr));//16 sizeof(数组名),计算的是整个数组的大小，单位字节
	printf("%d\n", sizeof(arr+0));//（4/8）数组名这里表示首元素地址，a+0还是首元素地址，4/8 32/64平台
	printf("%d\n", sizeof(*arr));//4 数组名表示首元素地址，*arr就是首元素，sizeof(*arr)就是4
	printf("%d\n", sizeof(arr+1));//（4/8） 数组名这里表示首元素地址，a+1是第二个元素地址
	printf("%d\n", sizeof(arr[1]));//4 第二个元素大小
	printf("%d\n", sizeof(&arr));//（4/8） &arr取出的是数组的地址，但数组的地址也是地址，地址大小就是4/8
	printf("%d\n", sizeof(*&arr));//16  &arr是数组的地址，数组的地址解引用访问的数组，sizeof计算的就是数组的大小
	printf("%d\n", sizeof(&arr+1));//（4/8）&arr是数组的地址，&arr+1跳过整个数组，但还是地址
	printf("%d\n", sizeof(&arr[0]));//（4/8）&arr[0]取出第一个元素的地址
	printf("%d\n", sizeof(&arr[0]+1));//（4/8）&arr[0]+1取出第二个元素的地址
	return 0;
}

//qsort函数

qsort函数是C语言中的快速排序函数,可以用来对数组进行排序。
qsort函数的原型为:
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
其中参数含义如下:
- base: 待排序数组的首地址
- nitems: 数组中待排序元素的个数
- size: 每个元素的大小(单位字节)
- compar: 用来比较两个元素的函数指针,需要程序员自己实现
使用qsort函数排序数组的步骤是:
1. 定义一个比较函数compar,该函数负责比较两个元素的大小,并返回比较结果(大于、等于、小于)。
2. 调用qsort函数,传入数组名、数组元素数量、每个元素的大小和比较函数compar。
3. qsort根据compar函数的结果对数组进行排序。
例如:
#include <stdio.h>  
#include <stdlib.h>
int compar(const void *a, const void *b) {
  return (*(int*)a - *(int*)b); 
}
int main() {
  int arr[] = {4, 2, 1, 5, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  qsort(arr, n, sizeof(int), compar);
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
以上程序首先定义了一个compar函数用于比较两个int类型的大小,然后调用qsort函数排序数组arr,最后打印出排序后的结果。


//例题
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
int main() {
	char arr[] = { 'a','b','c','d','e','f'};
	printf("%d\n", sizeof(arr));//6 sizeof计算的是数组大小 
	printf("%d\n", sizeof(arr+0));//（4/8）arr是首元素地址，arr+0还是首元素地址
	printf("%d\n", sizeof(*arr));//1 arr是首元素地址，*arr是首元素 
	printf("%d\n", sizeof(arr[1]));//1 第二个元素
	printf("%d\n", sizeof(&arr));//（4/8）&arr虽是数组地址，但还是地址
	printf("%d\n", sizeof(&arr+1));//（4/8）&arr是数组的地址，&arr+1跳过整个数组，但还是地址
	printf("%d\n", sizeof(&arr[0]+1));//（4/8）&arr[0]+1取出第二个元素的地址
	return 0;
}


//例题
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include<string>
int main() {
	char arr[] = { 'a','b','c','d','e','f'};
	printf("%d\n", strlen(arr));//随机值
	printf("%d\n", strlen(arr+0));//随机值
	printf("%d\n", strlen(*arr));//'a'地址->97非法访问
	printf("%d\n", strlen(arr[1]));//'b'地址->98非法访问
	printf("%d\n", strlen(&arr));//随机值
	printf("%d\n", strlen(&arr+1));//随机值，从该数组末地址往后
	printf("%d\n", strlen(&arr[0]+1));//随机值，从第二个元素往后
	return 0;
}

//例题
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
int main() {
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//7 计算的是数组的大小
	printf("%d\n", sizeof(arr+0));//(4/8) 计算的是地址，arr+0是首元素地址
	printf("%d\n", sizeof(*arr));//1 计算的是首元素大小
	printf("%d\n", sizeof(arr[1]));//1 arr[1]是第二个元素
	printf("%d\n", sizeof(&arr));//(4/8) &arr虽然是数组的地址，但也是地址
	printf("%d\n", sizeof(&arr+1));//(4/8) &arr是数组的地址，&arr+1跳过整个数组，但还是地址
	printf("%d\n", sizeof(&arr[0]+1));//(4/8) &arr[0]+1取出第二个元素的地址
	return 0;
}


计算
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <string.h>
int main() {
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr));//6 计算的是数组的长度
	printf("%d\n", strlen(arr+0));//6 arr+0是首元素地址
	printf("%d\n", strlen(*arr));// 'a'->97非法访问
	printf("%d\n", strlen(arr[1]));//'b'->98非法访问
	printf("%d\n", strlen(&arr));//6 计算的是数组的长度
	printf("%d\n", strlen(&arr+1));//随机值
	printf("%d\n", strlen(&arr[0]+1));//5 从b往后
	return 0;
}

//例题
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <string.h>
int main() {
	const char *p = "abcdef";//只能把a的地址存进去
	printf("%d\n", sizeof(p));//(4/8) 计算的是指针变量p的大小
	printf("%d\n", sizeof(p+1));//(4/8) 计算的是b的地址
	printf("%d\n", sizeof(*p));//1 *p就是字符串第一个字符a
	printf("%d\n", sizeof(p[0]));//1  p[0]==*(p+0)=='a'
	printf("%d\n", sizeof(&p));//(4/8) 
	printf("%d\n", sizeof(&p+1));//(4/8)
	printf("%d\n", sizeof(&p[0]+1));//(4/8) b的地址
	return 0;
}

//例题
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <string.h>
int main() {
	 char *p = "abcdef";//只能把a的地址存进去
	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p+1));//5
	printf("%d\n", strlen(*p));//'a'->97非法访问
	printf("%d\n", strlen(p[0]));//'a'->97非法访问
	printf("%d\n", strlen(&p));//随机值 存的是a的地址
	printf("%d\n", strlen(&p+1));//随机值
	printf("%d\n", strlen(&p[0]+1));//5
	return 0;
}


//计算
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <string.h>
int main() {
	int a [3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4 第一个元素大小
	printf("%d\n", sizeof(a[0]));//16 第一行数据大小
	printf("%d\n", sizeof(a[0]+1));//(4/8) 第一行第二个元素的地址
	printf("%d\n", sizeof(*(a[0] + 1)));//4 第一行第二个元素的大小
	printf("%d\n", sizeof(a + 1));//(4/8) a是首元素地址在二维数组里是第一行(首元素)地址，a+1是第二行地址
	printf("%d\n", sizeof(*(a + 1)));//16 第二行的大小
	printf("%d\n", sizeof(&a[0] + 1));//(4/8) 第二行地址
	printf("%d\n", sizeof(*( & a[0] + 1)));//16 第二行元素大小
	printf("%d\n", sizeof(*a));//16 第一行元素大小
	printf("%d\n", sizeof(a[3]));//16 第四行地址，虽然没有，但不影响
	return 0;
}
