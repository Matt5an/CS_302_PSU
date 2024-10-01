/*  
Matthew Sandberg
dd-mm-yyyy

CS 302
Program #

Purpose of code in file:
To test out various parts of C++ that I am either rusty at or unfamiliar with

*/

//Comment on how to maintain each implemented function, discussing implementation of the functions and how they solve the task at hand

//Comment on each class implementation, how they support the data structure and algorithms used for functions. If a function is modifying data members, it should be outlined in header comments. If it returns info back to client program, document it as well.

#include <iostream>

using namespace std;

/*This class is used as an example for how to make a class and how it might be implemented, for instance, on a sheet of paper at the top corner for identification of the owner,
date started, and what class it was created for, as well as the program number to identify which program it is
*/
class Example
{
private:

    string name;            //string name - stores the name of the owning person
    string date;            //string date - stores the date at the start of the writing
    string class_name;      //string class_name - stores the name of the class 
    string program_name;    //string program_name - stores the program name for program identification purposes

public:
    
    //print_example is a function that prints out the name, date, class, and program number using cout
    void print_example()
    {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Class: " << class_name << endl;
        cout << "Program: " << program_name << endl << endl;
    };

    //create example class constructor initializer for the variables (default)
    Example()
    {
        cout << "Example Default Constructor Executing!" << endl;
        name = "Unknown";
        date = "Unknown";
        class_name = "Unknown";
        program_name = "Unknown";
    };

    //create example class constructor prototype that can take in parameters for the variables
    Example(string n, string d = "Unknown", string cn = "Unknown", string p = "Unknown");    

    //create example class deconstructor
    ~Example()
    {
        cout << "Example Destructor Executing!" << endl;
        cout << name << " " << date << " " << class_name << " " << program_name << endl;
        cout << endl;
    };

};

//create example class constructor definition for prototype
Example::Example(string n, string d, string cn, string p)
{
    cout << "Example Prototype Constructor Executing!" << endl;
    name = n;
    date = d;
    class_name = cn;
    program_name = p;
};

/*This class is used as an example for how to make a class that call allocate and free memory used as well as practice with pointers
*/
class Allocate
{
private:

    double *number;       //**number - pointer to a double value

public:

    //create allocate class constructor initializer for the variables (default)
    Allocate()
    {
        number = (double *) malloc(sizeof(double));     //number - malloc will allocate enough space on the heap for a double and return a memory address, (double *) will cast the memory address, so that number will point to a double (number is now a pointer)
        cout << "Allocate Constructor Executing" << endl;
        cout << "Enter a Number: ";
        if (cin >> *number)
        {
            cout << "Number Address: " << number << endl;
            cout << "Number: " << *number << endl << endl;
        } 
        else 
        {
            cin.clear();
            cout << "Invalid Input, make sure to use an integer value!" << endl << endl;
        }

        cin.ignore(9999, '\n');
        
        // while (not (cin >> *number))
        // {
        //     cin.clear();
        //     cout << "Invalid input, make sure to use an integer value!" << endl << endl;
        // }
        // cout << "Number Address: " << number << endl;
        // cout << "Number: " << *number << endl << endl;

    };  

    //create allocate class constructor initializer for the variables
    Allocate(double num)
    {
        number = (double *) malloc(sizeof(double));     //number - malloc will allocate enough space on the heap for a double and return a memory address, (double *) will cast the memory address, so that number will point to a double (number is now a pointer)
        *number = num;                                  //**number - set to the above double memory addess the num value
        cout << "Allocate Constructor Executing" << endl;
        cout << "Number Address: " << number << endl;
        cout << "Number: " << *number << endl << endl;
    };  

    //create allocate class deconstructor
    ~Allocate()
    {
        cout << "Allocate Deconstructor Executing" << endl;
        cout << "Number Address: " << number << endl;
        cout << "Number: " << *number << endl << endl;
        free(number);                                   //gives back the previously allocated memory used to store the double number variable
    };

};

//test is a function used to test out the construct and deconstruct functions of c++
void test()
{
    //construct a first function example
    Example exfunc1;

    cout << "EXAMPLE FUNCTION 1:" << endl;
    exfunc1.print_example();

    //construct a second function example
    Example exfunc2("Hotdog");

    cout << "EXAMPLE FUNCTION 2:" << endl;
    exfunc2.print_example();
}

//main is the main function of the main.cpp file, which is the first thing you want to initialize
int main() 
{

    Allocate *ten = new Allocate(10);   //dynamically allocate space for an Allocate object on the heap, and creates the object. ten is the pointer to that object
    delete ten;                         //destroy the object and free the space that it was taking up on the heap (destructor)

    //construct a first allocate
    Allocate ac1(15);

    //construct a second allocate
    Allocate ac2;

    //construct a third allocate
    Allocate ac3;

    test();

    //construct a first example
    Example ex1;

    cout << "EXAMPLE 1:" << endl;
    ex1.print_example();

    //construct a second example
    Example ex2("Matthew Sandberg", "29-Sep-2024");

    cout << "EXAMPLE 2:" << endl;
    ex2.print_example();

    //construct a third example
    Example ex3("Matthew Sandberg", "29-Sep-2024", "CS 302", "#0");

    cout << "EXAMPLE 3:" << endl;
    ex3.print_example();

    return 0;

};