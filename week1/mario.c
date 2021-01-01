#include<stdio.h>
#include<cs50.h>

int main(void)
{
    // get height and prevent the limitation
    int height;
    do
    {
        height = get_int("Height: \n");    
    }
    while(1>height || height>8);
    
    // build the pyramid
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<height-i-1;j++)
        {
            printf(" ");
        }
        for(int j=height-i-1; j<height+2; j++)
        {
            if(j ==  height || j == height+1)
                printf(" ");
            else
                printf("#");
        }
        for(int j=height+2; j<height+3+i; j++)
        {
            printf("#");
        }
        for(int j=height+3+i; j<2*height+2; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    
}