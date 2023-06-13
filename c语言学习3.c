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


//
