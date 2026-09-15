//
// Created by ctava on 9/4/2026.
//
//
#include <stdio.h>

#define NUM_LINES 3
#define LINE_LEN 40

#define row 11
#define col 10

void static explainVariables() {
    printf("Deez, \n");
    int x = 0;      //4 bytes    -2 billion to +2 billion       (4294967295)
    short h = 2;    //2 bytes    -32 thousand to +32 thousand   (65535)
    char z = 4;     //1 byte     -127 to 128                    (256)
    long whatever = 0;  //4 bytes
    long long whatever2 = 0; //8 byte 64-bit
    printf("mathematical, \n");
    //floating point (decimals)
    double y = 1.4;  //8 byte
    float f = 2.042F; //4 byte

    float f2 = 3.0f; //better to use float, takes up less memory
    char str[] = "nuts";
    printf("%s \n", str); //Format for Strings
    printf("%d \n", x);   //Format for Ints
    printf("%c \n",z);    //Format for Chars
    printf("%f \n", f);   //Format for Floats
    printf("%lf \n", y);  //Format for Doubles Long floats
    //you can also change the amount of decimal points used
    double pi = 3.14159265358979;
    double e = 2.7182818284590;
    printf("%.5lf \n", pi); // you can change the amount of decimal points
    printf("%.5lf \n", e);

}

void static doSomethingWithOperators()
{
    int x = 2, y = 5;

    x += y;
    printf("Result is: %d\n", x);
}

void static dataStructures() {
    int NUM_ROWS = 5;
    int MAX_LINE_LENGTH = 10;
    char lines[NUM_ROWS][MAX_LINE_LENGTH]; //2d String array
    //has to be declared first

    //Using define^^
    char lines2[NUM_LINES][LINE_LEN] = {
        " * * * * * * * * * * * * * * * *\n",
        "*                               *\n",
        " * * * * * * * * * * * * * * * *\n"
    };

}

void static switchExample()
{
    int day = 4;

    switch (day) {
        default:
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
    }
}

void static two_dimensional_ArrayTesting(){

    char testArray[row][col]= {
        "howdy doo",
        "Gundam   ",
        "Hulk Smas",
        "Chipotle ",
        "Fat Boys ",
        "Clocks   ",
        "money    ",
        "Night tie",
        "immortity",
        "Avenge rs",
        "Optimrime"
    };
    //Don't put \n new line in array, it makes c blow up
    testArray[1][4] = 'N';
    printf("%c",testArray[1][4]);
}

void static changeVarWithPointers(int* example) {
    //Benefits of using POINTERS
    // Less time in program execution
    // Working on the original variable
    // With the help of pointers, we can create data structures (linked-list, stack, queue).
    // Returning more than one values from functions.
    // Searching and sorting large data very easily
    // Dynamically allocate memory
    int age = 21;
    int* ageP = &age;
    //printf("Value of ageP: %p \n", ageP);
    //printf("Address of age: %p \n", &age);

    //printf("Value of age: %d \n", age);
    //printf("Value of age from ageP (the pointer): %i \n", *ageP);
    *example = 6;
    printf("in Function: %i \n", *example);


}

int main() {
    //explainVariables();
    //printf();
    //doSomethingWithOperators();
    //two_dimensional_ArrayTesting();
    int example1 = 5;
    printf("Value of Example Before function: %i \n", example1);
    changeVarWithPointers(&example1);
    printf("After Function: %i", example1);
    //printf("%i", example1);

    return 0;
}

