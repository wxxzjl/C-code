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


//猜数字游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu(){
    printf("####################\n");
    printf("## 1玩游戏  0不完了##\n");
    printf("####################\n");
}
void game(){
    int ret =0;
    int guess=0;    //接收猜的数字
    ret=rand()%100+1;   //生成一个1-100的随机数
    while (1)
    {
        printf("请输入一个数：");
        scanf("%d",&guess);
        if(guess>ret){
            printf("猜大了\n");
        }else if(guess<ret){
            printf("猜小了\n");
        }else{
            printf("恭喜你，猜对了\n");
            break;
        }
    }
    
}
int main()
{
    int input=0;
    srand((unsigned int)time(NULL));    //时间戳
    do{
        menu();     //调用游戏选项
        printf("请选择：");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();     //调用游戏函数
            break;
        case 0:
            printf("游戏结束\n");
            break;
        default:
            printf("输入错误\n");
            break;
        }

    }while (input);
    return 0;
}
   


//计算机关机程序
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char input[20]={0};
    //shutdown -s -t 60 系统60秒关机程序
    //system() 执行系统命令的
    system("shutdown -s -t 60");    //系统关机命令
    again:
    printf("请注意，你的电脑将在60秒后自动关机，如果输入：我是猪，就取消关机\n请输入：");
    scanf("%s",input);
    if(strcmp(input,"我是猪")==0)   //比较两个字符串strcmp
    {
        system("shutdown -a");     //系统取消关机命令
    }else{
        goto again;                //goto语句跳转
    }
    return 0;
}
