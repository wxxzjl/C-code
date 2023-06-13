//请问循环了多少次？ 答案：0次
#include <stdio.h>
int main()
{
    int i =0;
    int k =0;
    for(i=0,k=0;k=0;i++,k++)  //k=0为假，循环不进去
    {
        k++;
    }
    return 0;
}


//计算n的阶乘
#include <stdio.h>
int main()
{
  int i=0;
  int j=0;
  int ret =1;
  printf("请输入一个数：");
  scanf("%d",&j);
  for(i=1;i<=j;i++)
  {
    ret=ret*i;
  }
    printf("%d\n",ret);
    return 0;
}



//计算1！+2！+3！+4！+5！...+10！=
#include <stdio.h>
int main()
{
  int i=0;
  int j=0;
  int sum =0;
  for(i=1;i<=10;i++)
  {
    int ret =1;
    for(j=1;j<=i;j++){
        ret =ret*j;
    }
    sum = sum+ret;
  }
    printf("%d\n",sum);
    return 0;
}

//优化代码
#include <stdio.h>
int main()
{
  int i=0;
  int ret=1;
  int sum =0;
  for(i=1;i<=10;i++)
  {
    ret =ret*i;
    
    sum = sum+ret;
  }
    printf("%d\n",sum);
    return 0;
}


//在一个有序数组中查找一个数
#include <stdio.h>
int main()
{
  int arr[]={1,2,3,4,5,6,7,8,910};
  int k=7;  //比如找7
  int i=0;
  int sz=sizeof(arr)/sizeof(arr[0]);
  for(i=0;i<sz;i++){
    if(k==arr[i])
    {
        printf("找到了，下标是%d\n",i);
        break;
    }
  }
  if(i==sz)
    printf("找不到\n");
    return 0;
}

//优化代码
//利用二分法查找有序列表
#include <stdio.h>
int main()
{
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int k=17;  //比如找7
  int sz=sizeof(arr)/sizeof(arr[0]);  //计算元素个数
  int left =0;      //左下标
  int right =sz-1;    //右下标
  while(left<=right){
     int mid =(left+right)/2;
    if(arr[mid]>k){
        right=mid-1;
    }else if(arr[mid]<k){
        left =mid+1;
    }else{
        printf("找到了,下标是%d\n",mid);
        break;
    }
  }if(left>right)
        printf("找不到\n");
    return 0;
}



//打印
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
int main()
{
    char arr1[] ="welcome to school!!!!";   //字符数组用引号
    char arr2[] ="                     ";
    int left =0;
    //int right =sizeof(arr1)/sizeof(arr1[0])-2;
    //有一个默认\0,再加上下标从0开始，所以-2
    int right =strlen(arr1)-1;    //也可以这样写
    while (left<=right)
    {
        arr2[left] =arr1[left];
        arr2[right] =arr1[right];
        printf("%s\n",arr2);
        Sleep(1000);    //休息1000毫秒=1秒
        system("cls");  //执行系统命令的一个函数cls--清空屏幕
        left++;
        right--;
    }
    return 0;
    
}


//用户输入密码3次机会
#include <stdio.h>
int main()
{
    int i=0;
    char password[20] = {0};    //字符数组本身就是地址，下面键盘录入不需要用&符号
    for(i=0;i<3;i++)
    {
        printf("请输入密码：");
        scanf("%s",password);
        //if(password == "123456")   字符串比较不能用==号
        if(strcmp(password,"123456")==0)    //字符串比较需要用strcmp库函数12
        {
            printf("登陆成功\n");
            break;
        }else{
            printf("输入错误\n");
        }
    }
    return 0;
}


//下面代码输出结果是什么？
//答案：8，10，12，14，16 
#include <stdio.h>
int sum(int a)
{
    int c=0;
    static int b=3;  //static修饰局部变量会延长生命周期，不会销毁。
    c += 1;
    b += 2;
    return(a+b+c);
}
int main()
{
    int i;
    int a=2;
    for(i=0;i<5;i++)
    {
        printf("%d\n",sum(a));
    }
    return 0;
}


//答案：打印5死循环
#include <stdio.h>
int main()
{
    int i=0;
    for(i=0;i<10;i++)
    {
        if(i=5){    //这是赋值，一直赋值5，打印5，且永远循环6
            printf("%d\n",i);
        }
    }
    return 0;
}


//求最大公约数
#include <stdio.h>

// 欧几里得算法实现求最大公约数
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    return 0;
}


//另一种写法
#include <stdio.h>
int main()
{
    int m=0;
    int n=0;
    int r=0;
    printf("请输入两个数：");
    scanf("%d%d",&m,&n);
    while(r=m%n){
        m=n;
        n=r;
    }
    printf("这两个数最大公约数是:%d\n",n);
    return 0;
}


//计算闰年
#include <stdio.h>
int main()
{
    int year=0;
    int count=0;
    for(year=1000;year<=2000;year++)
    {
        //判断year是否为闰年
        //1能被4整除并且不能被100整除是闰年
        //2能被400整除是闰年
        if((year%4==0 && year%100!=0) || (year%400==0))
        {
            printf("%d\n",year);
            count++;
        }
    }
    printf("一共有%d个闰年\n",count);
    return 0;
}


//判断质数
#include <stdio.h>
int main()
{
    int i=0;
    for(i=100;i<=200;i++){
        int j=0;
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }
        }
        if(j==i){
                printf("这个数是质数：%d\n",i);
            }
    }
    
    return 0;
}


//优化代码
#include <stdio.h>
#include <math.h>
int main()
{
    int i=0;
    int count=0;
    for(i=101;i<=200;i+=2){     //偶数不可能，直接+2，看奇数
        int j=0;
        for(j=2;j<sqrt(i);j++){     //sqrt开平方函数
            if(i%j==0){
                break;
            }
        }
        if(j>sqrt(i)){
                printf("这个数是质数：%d\n",i);
                count++;
            }
    }
    printf("一共有%d个质素\n",count);
    return 0;
}
