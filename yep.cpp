#include <iostream>
#include <limits>  //for cin.ignore
#include <cstdint> //if i want ex: int_16t (-32768 to 32767)
#include <stdio.h> //printf

void ignoreNewline()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    while (true) 
    {
        printf("Enter a double(number): ");
        double x{};
        std::cin >> x;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            ignoreNewline();
            std::cerr << "Input invalid, Idiot!\n";
        }
        else
        {
            ignoreNewline();
            return x;
        }
    }
}

char getOperator()
{
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation;
        default:
            std::cerr << "Input invalid, Idiot!\n";

        }
    }
}

void doMathBitch(double x, char operation, double y) 
{
    double resAdd = x + y;
    double resSub = x - y;
    double resMul = x * y;
    double resDiv = x / y;
    switch (operation)
    {
    case '+':
        printf("%f + %f = %f\n", x, y, resAdd);
        //std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        printf("%f - %f = %f\n", x, y, resSub);
        break;
    case '*':
        printf("%f * %f = %f\n", x, y, resMul);
        break;
    case '/':
        printf("%f / %f = %f\n", x, y, resDiv);
        break;
    default:
        std::cerr << "doMathBitch() failed for some obscure.\n";
    }
}

int main()
{
    printf("Welcome to doMathBitch\n \n");
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };
    doMathBitch(x, operation, y);
    system("pause");
    return 0;
}
