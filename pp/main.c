int main()  
{  
    int i=10;       //声明并初始化  
    int *p=&i;  
    int **pp=&p;  
 
    printf("二级指针变量pp指向地址:%d\n",pp); //输出  
    printf("变量p的地址:%d\n",&p);  
    printf("一级指针变量p指向地址:%d\n",p);  
    printf("变量i的地址:%d\n",&i);  
    printf("i=%d\n",i);  
    printf("p=%d\n",p);  
    printf("*p=%d\n",*p);  
    printf("pp=%d\n",pp);  
    printf("*pp=%d\n",*pp);  
    printf("**pp=%d\n",**pp);  
 
    system("pause");  
    return 0;  
} 
