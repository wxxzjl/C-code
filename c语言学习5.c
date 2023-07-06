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
