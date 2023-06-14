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


//
