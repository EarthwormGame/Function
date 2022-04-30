#include<stdio.h>

int bigNum(int num01, int num02) 
{
    if (num01 >= num02)
    {
        return num01;
    }
    else if (num01 == num02)
    {
        printf("값이 동일합니다.");
    }
    else
    {
        return num02;
    }
}

int main(void)
{
    int result;  

    result = bigNum(3, 4); // 함수 호출

    printf("두 수 중 더 큰수는 %d입니다.\n", result);

    result = bigNum(5, 2); 

    printf("두 수 중 더 큰수는 %d입니다.\n", result);

    result = bigNum(10, 5); 

    printf("두 수 중 더 큰수는 %d입니다.\n", result);

    result = bigNum(7,7);

    return 0;

}  