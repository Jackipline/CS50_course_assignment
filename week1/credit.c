#include<stdio.h>
#include<cs50.h>
#include<math.h>

int calculate(long);
int length(long);

int main(void)
{
    long n = get_long("Your credit number: \n");
    int length_n;
    int check_sum;
    int check_n;
    
    check_sum = calculate(n);
    length_n = length(n);
    
    if(length_n == 13)
    {
        check_n = n / pow(10,12);
        if(check_n == 4 && check_sum % 10 == 0)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else if(length_n == 15)
    {
        check_n = n / pow(10,13);
        if((check_n == 34 || check_n == 37) && check_sum % 10 == 0)
            printf("AMEX\n");
        else
            printf("INVALID\n");
    }
    else if(length_n == 16)
    {
        check_n = n /pow(10,14);
        if((check_n == 51 || check_n == 52 || check_n == 53 || check_n == 54 || check_n == 55) && check_sum % 10 == 0)
            printf("MASTERCARD\n");
        else if(check_n / 10 == 4 && check_sum % 10 == 0)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}

int length(long n)
{
    int i = 0;
    while(n>0)
    {
        n /= 10;
        i++;
    }
    return i;
}

int calculate(long n)
{
    int i = 1;
    int sum = 0;
    while(n>0)
    {
        int even_n = 0;
        int even_n_sum = 0;
        if(i % 2 == 0)
        {
            even_n = 2 * (n % 10);
            while(even_n > 0)
            {
                even_n_sum += even_n % 10;
                even_n /= 10;
            }
            sum += even_n_sum;
        }
        else
            sum += n % 10;
        n /= 10;
        i++;
    }
    return sum;
}