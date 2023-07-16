//switch语句
#include <stdio.h>
int main()
{
    int day =0;
    scanf("%d",&day);
    switch(day)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("工作日\n");
            break;
        case 6:
        case 7:
            printf("休息日\n");
            break;
        default:
            printf("输入错误\n");
            break;
    }
    return 0;
}



//程序运行后的输出结果是(123，173)
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int m=0123, n = 123;
  printf("%o %o\n", m, n);
  return 0;
}
/*
解析：C o% 表示8进制进行输出int m=0123; m已经是8进制不需要进行转换  而n=123是10进制 需要进行8进制转换 得173
这段代码中，k=k>>1; 是一个右移操作，它将 k 的二进制表示向右移动一位。对于每次循环，k 都会被除以 2（忽略任何余数）。这个过程会一直持续到 k 小于或等于 1。
给定 k = 2000，我们可以把这个数字转化为二进制表示，2000 的二进制表示是 11111010000。这个数字有 11 位，所以 k 需要右移 10 次才能变成 1，即此代码循环了 10 次。
因此，这个 while 循环执行了 10 次。
*/



//下列代码，循环了多少次？
int k = 2000;
while (k > 1) {
    k = k >> 1;
}
/*
解析：这段代码中，k=k>>1; 是一个右移操作，它将 k 的二进制表示向右移动一位。对于每次循环，k 都会被除以 2（忽略任何余数）。这个过程会一直持续到 k 小于或等于 1。

给定 k = 2000，我们可以把这个数字转化为二进制表示，2000 的二进制表示是 11111010000。这个数字有 11 位，所以 k 需要右移 10 次才能变成 1，即此代码循环了 10 次。

因此，这个 while 循环执行了 10 次。（>>:右移运算符，num >> 1,相当于num除以2  ）

*/



//答案:m=5,n=3
#include <stdio.h>
int main()
{
    int n = 1;
    int m = 2;
    switch(n)
    {
        case 1:
        m++;
        case 2:
        n++;
        case 3:
            switch(n)
                {
                    case 1:
                    n++;
                    case 2:
                    m++;n++;
                    break;
                }
        case 4:
        m++;
        break;
        default:
            break;
    }
    printf("m = %d,n = %d\n",m,n);
    return 0;
}


/*
输出结果:
请输入密码：>123456
请确认(Y/N:>)确认失败
*/
#include <stdio.h>
int main()
{   
    int ret =0;
    char password[20] = {0};    //数组本身就是地址，下面的不需要加&符号
    printf("请输入密码：>");    //输入密码123按回车确认底层为123\n。
    scanf("%s",password);
    //缓存区还剩下一个'\n'
    //读取一下'\n'
    //getchar(); 
    //或则这样写
    //while((getchar() != '\n')){;}  
    printf("请确认(Y/N:>)");
    ret = getchar();            //此时输入缓存区剩下\n被读取
    if(ret == 'Y'){
        printf("确认成功\n");
    }
    else{
        printf("确认失败\n");
    }
    return 0;
}


