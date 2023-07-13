//利用递归简单打印1 2 3 4
#include <stdio.h>
#include <string.h>
void print(int n){
	if (n > 9) {
		print(n / 10);	//递归调用
	}
	printf("%d ", n % 10);
}
int main() {
	int num = 0;
	scanf("%d", &num);
	print(num);	//函数调用
	return 0;
}


//自定义求字符串长度，创建零时变量
#include <stdio.h>
#include <string.h>
int my_strlen(char * str) {
	int count = 0;
	while(*str != '\0') {	//解引用
		count++;
		str++;
}
	return count;
}
int main() {
	char arr[] = "bit";
	//int len = strlen(arr);	求字符串长度
	//printf("%d\n", len);
	int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
	printf("len= %d\n", len);
	return 0;
}


//自定义求字符串长度，不创建零时变量
#include <stdio.h>
#include <string.h>
int my_strlen(char * str) {
		if(*str != '\0') {
			return 1 + my_strlen(str + 1);	//递归调用
		}
		else {
			return 0;
		}
}
int main() {
	char arr[] = "bit";
	//int len = strlen(arr);	求字符串长度
	//printf("%d\n", len);
	int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
	printf("len= %d\n", len);
	return 0;
}

//利用指针求字符串长度
#include <stdio.h>
int my_strlen(char* str) {
	char *start = str;
	char *end = str;
	while (*end != '\0') {
		end++;
	}
	return end-start;
}
int main() {
	char arr[] = "fantastic";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}

//计算第n个斐波那契数
//1 1 2 3 5 8 13 21 34 55
//递归方法，容易溢出
#include <stdio.h>
#include <string.h>
int Fib(int n) {
	if (n < 3)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2); //计算量巨大，会溢出
}
int main(){
	int n = 0;
	scanf("%d", &n);
	int rest = Fib(n);
	printf("rest = %d\n", rest);
	return 0;
}

//迭代方法
#include <stdio.h>
int Fib(int n){
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	int rest = Fib(n);
	printf("rest = %d\n", rest);
	return 0;
}


//当然，我知道汉诺塔问题。汉诺塔是一个经典的数学问题或者说是游戏，来自于印度的传说。
//在这个问题中，你有三个柱子和若干个大小不一的盘子。初始时，所有的盘子都在一个柱子上，且由下到上按大小排列。
//问题的目标是将所有的盘子移动到另一个柱子上，每次只能移动一个盘子，且任何时刻大盘子都不能在小盘子上面。
//这个问题的解法是递归的：首先解决 n-1 个盘子的问题，然后移动最大的盘子，再解决 n-1 个盘子的问题。

//在这个代码中，hanoi函数用于移动盘子。
//当只有一个盘子时，直接将盘子从源柱子移到目标柱子。
//当有多于一个盘子时，先将n-1个盘子从源柱子移动到辅助柱子，
//然后将最大的盘子从源柱子移动到目标柱子，
//最后再将n-1个盘子从辅助柱子移动到目标柱子。
#include <stdio.h>

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 4;  // Number of disks
    hanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}


//#define _CRT_SECURE_NO_WARNINGS 1
//交换a和b，不要使用零时变量
#include <stdio.h>
int main() {
	int a = 3;
	int b = 5;
	printf("a=%d,b=%d\n", a, b);
	//^按（二进制位）位异或：相同为0，相异为1
	//3的二进制位011，5的二进制位101
	a = a ^ b;//011+101---->110
	b = a ^ b;//110+101---->011  是3
	a = a ^ b;//110+011---->101  是5
	printf("a=%d,b=%d\n", a, b);
	return 0;
}


//查找数组中的单生狗
#include <stdio.h>
int main() {
	int arr[] = { 1,2,3,4,1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++) {
		int count = 0;
		for (int j = 0; j < sz; j++) {
			if (arr[i] == arr[j]) {
				count++;
			}
		}
		if (count == 1) {
			printf("%d\n", arr[i]);
		}
	}
	return 0;
}

//优化代码
#include <stdio.h>
int main() {
	int arr[] = { 1,2,3,4,1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int flag = 0;
	for (int i = 0; i < sz; i++) {	
		//异或满足交换律
		flag = flag ^ arr[i];
	}
	printf("%d\n", flag);
	return 0;
}


//求一个整数存储在内存中的二进制中的1的个数
//解法一：与1&得1该位就是1
#include <stdio.h>
int main() {
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	for (int i = 0; i < 32; i++) {
		if (1 == ((num >> i) & 1)) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}


//解法二
//-1时这种方法有问题
#include <stdio.h>
int main() {
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	while (num) {
		if (num % 2 == 1) 
			count++;
		num = num / 2;
		
	}
	printf("%d\n", count);
	return 0;
}


//例题
#include <stdio.h>
int i;
int main() {
	i--;
	if (i > sizeof(i)) {	//sizeof()计算变量/类型所占内存空间大小>=0 无符号数
		printf(">\n");		//-1和无符号数比较，符号位不看负数，-1的无符号数看类型计算
	}						
	else {
		printf("<\n");
	}
	return 0;
}
//在C语言中, -1的无符号数表示方式由两个部分组成:
//1. 无符号数(unsigned)关键字
//2. 整数类型(如unsigned int)
//对于不同的整数类型, 表示 - 1的无符号数的值会不同。
//例如 :
//1. unsigned int : -1的无符号数是4294967295(32位)
//2. unsigned short : -1的无符号数是65535(16位)
//3. unsigned char : -1的无符号数是255(8位)
//这是因为无符号数使用补码形式表示, 当给一个有符号整数的二进制表示取反后, 就得到了相应的无符号数。
//具体来说, -1的二进制表示全为1, 取反后就是全0, 该无符号数的值就是该整数类型能表示的最大值。
//所以对于不同位数的无符号整数类型, 表示 - 1的值都不相同, 但统一的规律是它们对应的最大值。
