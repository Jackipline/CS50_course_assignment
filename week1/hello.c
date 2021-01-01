#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string name = get_string("what is your name?\n"); //give me the name
    printf("hello,%scheck50 cs50/problems/2020/x/hello\n", name);
}