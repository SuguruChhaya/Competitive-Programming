// CppCrashCourse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
//enum EyeColor {Brown, Blue, Green, Gray, Other};
int a = 5;
//I don't think I really have to even declare a function. 
//Could assign default which may sometimes come in handy. 
int sum(int a=1, int b=1) {
    return a + b;
}
//What types are mutable tho?
void
yo(int a) {
    a++;
}

void celebrateBirthday(int *age) {
    //To receive pointer, use "*"
    //De-reference pointer also "*
    (*age)++;
    cout << "Happy " << *age << "th birthday" <<"\n";
}

//Don't need to know about fancy class stuff. 
class Car {
//Need to make certain variables public. 
public:
    string Name;
    string Color;
    double Price;

    //Build constructors. 
    Car(string name, string color, double price) {
        Name = name;
        Color = color;
        Price = price;
    }

    void getName() {
        cout << "Name: " << Name << "\n";
    }
};

int main()
{
    Car myCar("Ford", "red", 50000);
    myCar.getName();
    /*
    myCar.Name = "Ford";
    myCar.Color = "red";
    myCar.Price = 50000;
    */

    //By default, class properties are private. 

    //No matter if declared globally or locally, integers aren't mutable. 
    yo(a);
    cout << a << "\n";
    cout << sum(2, 3) << "\n";
    /*
    //std is a namespace?
    //If I specify the namespace, I can just do a cout. 
    cout << "Hello World!\n";
    //Can remove the remaining message. 
    //In C++ I need to specify newline or else printed in the same line. 
    //std:: cout << "Yo";
    //std::cout << "What's up";
    //cout << "Newline";
    

    int age = 25;
    //constants vs variables huh?
    //const int age = 25;
    age = 26;
    float weight = 65.5;
    //double can store higher precision.
    //Single quatation is char
    char gender = 'm';
    string username = "a";
    //Cannot contain different size. Only same type.
    //If I assign straight up, I can omit size. 
    string colors[] = { "red", "green", "blue" };
    //string colors = { "red", "green", "blue" };
    //colors->append("black");
    cout << colors[0]; //Cannot print arrays just like python. 
    //Reassign
    //cin is essentially just input()
    cin >> colors[0];
    cout << colors[0];
    //signed unsigned stuff. Check later. 



    
    */
    bool  isTodaySunny = true;
    if (isTodaySunny) {
        //Don't care too much about low level \n will work. 
        cout << "Go to park" << "\n";
    }

    //Shorter. Need to have an else? Inconvenient so don't use. 
    isTodaySunny ? cout << "Go to park" << "\n": cout << "Do nothing" << "\n";

    //! is not. 

    

    //Switch cases. Probably never use it. 
    //Enumeration.

    //EyeColor eyeColor = Brown;
    //Really integer index. 
    /*
    switch (99)
    {
    //Other cases are not going to be checked. 
    case Brown:
        break;
    case Blue:
        break;
    case Green:
        break;
    case Gray:
        break;
    case Other:
        break;
    default:
        break;
    }
    */

    //while vs dowhile
    int counter = 1;
    //cout << "WHILE:\n";
    while (counter < 1) {
        cout << counter <<"\n";
        counter++;
    }

    counter = 1;
    //Do while executes at least once. 
    do {
        cout << counter << "\n";
        counter += 1;
    } while (counter <= 10);

    string animals[] = { "cat", "dog", "cow" };

    //Can I have negatives?
    /*
    for (int i = 0; i < 3; i--) {
        cout << animals[i] << "\n";
    }
    */
    //cout << animals[-1];
    //No negative index. Undefined behaviour. 

    //Pointer stores address of variable. 
    //Functions or arr. 
    //Pointers kind of like mutable integer??
    int myAge = 25;
    cout << "Before function " << myAge << "\n";
    celebrateBirthday(&myAge);
    cout << "After function " << myAge << "\n";

    //Name of arr: address of first element. 
    int arr[] = { 1,3,5,7,9 };
    cout << arr << "\n";
    cout << &arr[0] << "\n";

    int* pointer = arr;
    cout << "Pointing to " << pointer << ", value: " << *pointer << "\n";
    pointer++;

    //Let me try to write a simple program that prints all values. 
    //int* pointer2 = arr;
    //for ()


    //I am guessing that if I am just copying value then I don't need to specify the type. Not really. 
   
    //*For running the CPP code in terminal, g++ try.cpp -o try.exe always works. 
    //*There are several other ways to compile all this. 
    //*Can compile right from vs code itself. 

    system("pause>0");
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
