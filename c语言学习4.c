/*
判断1-100里有多少个9
答案:20
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int i=0;
    int count=0;
    for(i=1;i<=100;i++){
        if(i%10==9 || i/10==9){   //这个语法少算了一次99
            printf("%d\n",i);
            count++;
        }
    }
    printf("一共有%d个\n",count);
    return 0;
}

//正确的
#include <stdio.h>
#include <math.h>
int main()
{
    int i=0;
    int count=0;
    for(i=1;i<=100;i++){
        if(i%10==9){              //打印99一次
            printf("%d\n",i);
            count++;
        }if(i/10==9){             //打印99二次
            printf("%d\n",i);
            count++;
        }
    }
    printf("一共有%d个\n",count);
    return 0;
}


//计算1/1-1/2+1/3-1/4+1/5...-1/100=
#include <stdio.h>
int main()
{
    int i=0;
    double sum=0.0;
    int flag=1;
    for(i=1;i<=100;i++){
        sum+= flag*1.0/i;      
        flag=-flag;     //偶数位为-1
    }
    printf("%lf\n",sum);
    return 0;
}


//打印九九乘法表
#include <stdio.h>
int main()
{
    int i=0;
    int j=0;
    int sum=1;
    for(i=1;i<=9;i++){
        for(j=1;j<=i;j++){
            sum=i*j;
            printf("%d*%d=%-2d ",j,i,sum);  //%-2d表示两位左对齐，%2d表示两位右对齐     
        }
         printf("\n");
    }
    return 0;
}
