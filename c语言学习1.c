#include <stdio.h>
#include <string.h>
struct Book
{
    char name[20];
    short price;
};

int main()
{   //利用结构体类型创建一个该类型的结构体变量
    struct Book b1 = {"C程序语言",55};
    printf("书名为：%s\n",b1.name);
    printf("价格为：%d元\n",b1.price);
    //更改书名价格
    strcpy(b1.name,"C++");	//这是数组，利用库函数string copy字符串拷贝
    b1.price = 15;	//变量可以直接改
    //利用指针打印出书名价格
    struct Book *pd = &b1;
    printf("书名为：%s\n",(*pd).name);
    printf("价格为：%d元\n",(*pd).price);
    //简化版
    printf("书名为：%s\n",pd->name);
    printf("价格为：%d元\n",pd->price);
    //区别
    //. 结构体变量.成员
    //- 结构体指针->成员
    return 0;
    
}
//用一个函数求两个整数中的较大者，打印输出。
#include <stdio.h>    //编译的预处理指令（标准输入输出函数）
int main()			  //定义主函数--程序的入口
{					 //主函数体开始
    int max(int x,int y);	//对被调用函数max的声明
    int a, b,c;				//定义变量a,b,c
    scanf("%d,%d",&a,&b);   //输入变量a,b的值
    c=max(a,b);				//调用max函数将得到的值赋给c，（）-->函数调用操作符
    printf("max number=%d\n",c);  //输出c的值
    return 0;				//返回函数值为0
}							//主体函数结束

int max(int x,int y) //定义一个max函数，函数值为整型，形式参数x,y为整型    
{
    int z =0;   //max函数中的声明部分，定义本函数中用到的变量z为整型
    if(x>y)z=x; //若x>y成立，将x的值赋值给变量z
    else z=y;   //否则，将y的值赋值给变量z
    return(z);  //将z的值作为max函数值，返回到调用max函数的位置
}
//
//
//代码分析
#include <stdio.h> //编译的预处理指令（标准输入输出函数）standard intput&output（.h）是头文件（header file）
int main()         //定义主函数--程序的入口（main函数有且只有一个）int表示main函数调用返回一个整型值
{                  //函数开始
    int a,b,sum;   //程序声明部分，定义a，b，sum为整型变量
    a=12;          //对a赋值
    b=12;          //对b赋值
    sum = a+b;     //进行a+b运算
    printf("sum=%d\n" ,sum); //输出结果，%d表示用十进制整数形式输出
    return 0;      //使函数返回值为0
}                  //函数结束
