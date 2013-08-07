//
//  main.c
//  ezCalc
//
//  Created by Keith on 8/6/13.
//  Copyright (c) 2013 Appology. All rights reserved.
//

#include <ctype.h>
#include <stdio.h>
double getNumber(void);
char getResponse(void);


int main(int argc, const char * argv[])
{
    
    char ch;
    double number1, number2;
    
    printf("Enter the operation of your choice:\n");
    printf("a. add        s. subtract\n");
    printf("m. multiply   d. divide\n");
    printf("q. quit\n");
    while ((ch = getResponse()) != 'q')
    {
        
        number1 = getNumber();
        printf("Next number:\n");
        number2 = getNumber();
        
        switch (ch)
        {
            case 'a':
                printf("%.1f + %.1f = %.1f\n", number1, number2, number1 + number2);
                break;
            case 's':
                printf("%.1f - %.1f = %.1f\n", number1, number2, number1 - number2);
                break;
            case 'm':
                printf("%.1f * %.1f = %.1f\n", number1, number2, number1 * number2);
                break;
            case 'd':
                while (number2 == 0)
                {
                    printf("Division by 0 not allowed.\n");
                    number2 = getNumber();
                }
                printf("%.1f / %.1f = %.1f\n", number1, number2, number1 / number2);
                break;
                
        }
        
        printf("Enter the operation of your choice:\n");
        printf("a. add        s. subtract\n");
        printf("m. multiply   d. divide\n");
        printf("q. quit\n");
        
    }
    
    return 0;
}

char getResponse(void)
{
    char ch;
    while((ch = tolower(getchar())) )
    {
        
        
        switch (ch)
        {
            case 'a':
                break;
            case 's':
                break;
            case 'm':
                break;
            case 'd':
                break;
            case 'q':
                break;
            default:
                
                printf("%c is not a valid response.\nPlease choose a, b, c, d , or q to quit.\n", ch);
                
                //clear buffer of extra input (add, instead of a)
                while (getchar()!='\n')
                {
                    continue;
                }
                
                continue;
        }
        //clear buffer of extra input (add, instead of a)
        while (getchar()!='\n')
        {
            continue;
        }
        return ch;
    }
    
    return ch;
}



double getNumber(void)
{
    double number;
    int ch;
    printf("Enter a number:\n");
    while(scanf("%lf", &number) != 1)
    {
        //clears buffer
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a number.\n");
        printf("Please enter another number.\n");
    }
    getchar();//if scanf works, it will put back the newline which we need to clear.
    
    return number;
}

