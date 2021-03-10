// WilsonNoah_Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <string>

void IntAddress(int num, int* pointer);


enum Colors
{
    White = 1,
    Black,
    Gray,
    Silver,
    Red,
    Blue,
    Brown,
    Green,
    Orange
};

struct Car
{
    char make[32];
    char model[32];
    int year;
    int mileage;
    int Colour;
};
Colors DetermineColour(Car vehicle, bool print);
void RepaintCar(Car* car, Colors colour);
void PrintCar(Car car, int carnum);
void PrintCarPointer(Car* car, int carnum);
void AddMileage(Car* car, int miles);

int main()
{
#pragma region Program 1
    int nums[15];
    srand(time(0));
    /*for (int i = 0; i < 15; i++)
    {
        nums[i] = rand();
        std::cout << "Number: " << nums[i] << '\t' << "Address: " << &nums[i] << std::endl;
    }*/
#pragma endregion 

#pragma region Program 2
    /*for (int i = 0; i < 15; i++)
    {
        nums[i] = rand();
        IntAddress(nums[i], &nums[i]);
    }*/
#pragma endregion

#pragma region Program 3
    Car cars[3];
    for (int i = 0; i < 3; i++)
    {
        while (true) //Make
        {
            std::cout << "Please input the Make of your vehicle: ";
            std::cin >> cars[i].make;
            if (std::cin.fail())
            {
                std::cin.clear(CHAR_MAX, '\0');
                std::cout << "Please input a valid make.";
                continue;
            }
            break;
        }
        while (true) //Model
        {
            std::cout << "Please input the Model of your vehicle: ";
            std::cin.clear();
            std::cin >> cars[i].model;
            if (std::cin.fail())
            {
                std::cin.clear(CHAR_MAX, '\0');
                std::cout << "Please input a valid model.";
                continue;
            }
            break;
        }
        while (true) //Color
        {
            std::cout << "Please input the Colour of your vehicle: " << std::endl;
            std::cout << "1) White" << '\t' << "2) Black" <<'\t' << "3) Gray" << std::endl;
            std::cout << "4) Silver" << '\t' << "5) Red" << '\t' << '\t' << "6) Blue" << std::endl;
            std::cout << "7) Brown" << '\t' << "8) Green" << '\t' << "9) Orange" << std::endl;
            int userinput;
            std::cin.clear();
            std::cin >> userinput;
            if (std::cin.fail())
            {
                std::cin.clear(INT_MAX, '\0');
                std::cout << "Please choose a valid number for the color of your vehicle." << std::endl;
                continue;
            }
            else
            {
                cars[i].Colour = userinput;
                DetermineColour(cars[i],false);
            }
            break;
        }
        while (true) //Year
        {
            std::cout << "Please input the Year of your vehicle: ";
            std::cin.clear();
            std::cin >> cars[i].year;
            if (std::cin.fail() || cars[i].year > 2022 || cars[i].year < 1885)
            {
                std::cin.clear(INT_MAX, '\0');
                std::cout << "Please input a valid year." << std::endl;
                continue;
            }
            break;
        }
        while (true) //Mileage
        {
            std::cout << "Please input the Mileage of your vehicle: ";
            std::cin.clear();
            std::cin >> cars[i].mileage;
            if (std::cin.fail() || cars[i].mileage < 0)
            {
                std::cin.clear(INT_MAX, '\0');
                std::cout << "Please input a valid Mileage." << std::endl;
                continue;
            }
            break;
        }
    }
    for (int i = 0; i < 3; i++) //Printing the cars
    {
        PrintCar(cars[i], i+1);
        PrintCarPointer(&cars[i], i+1);
    }
#pragma endregion
//part 2
#pragma region Repaint Car
    while (true)
    {
        char userinput = ' ';
        int iinput = 0;
        Colors color = White;
        std::cout << "Would you like to change the color of any of the vehicles?" << std::endl;
        std::cout << "(Y)es or (N)o: ";
        std::cin >> userinput;
        if (std::cin.fail())
        {
            std::cin.clear(CHAR_MAX, '\0');
            std::cout << "Please input Y for yes, or N for no." << std::endl;
            continue;
        }
        else
        {
            if (userinput == 'Y' || userinput == 'y')
            {
                std::cout << "Please select a vehicle: " << std::endl;
                for (int i = 0; i < 3; i++)
                {
                    std::cout << "Car " << i + 1 << " - " << cars[i].year << " ";
                    DetermineColour(cars[i], true);
                    std::cout << " " << cars[i].make << " " << cars[i].model << " with " << cars[i].mileage << " miles." << std::endl;

                }
                std::cin.clear();
                std::cin >> iinput;
                if (std::cin.fail())
                {
                    std::cin.clear(INT_MAX, '\0');
                    std::cout << "Please input a valid integer for your vehicle selection." << std::endl;
                    continue;
                }
                else
                {
                    std::cout << "Please input the new Colour of your vehicle: " << std::endl;
                    std::cout << "1) White" << '\t' << "2) Black" << '\t' << "3) Gray" << std::endl;
                    std::cout << "4) Silver" << '\t' << "5) Red" << '\t' << '\t' << "6) Blue" << std::endl;
                    std::cout << "7) Brown" << '\t' << "8) Green" << '\t' << "9) Orange" << std::endl;
                    std::cin.clear();
                    std::cin >> cars[iinput - 1].Colour;
                    if (std::cin.fail())
                    {
                        std::cin.clear(INT_MAX, '\0');
                        std::cout << "Please choose a valid number for the color of your vehicle." << std::endl;
                        continue;
                    }
                    else {
                        DetermineColour(cars[iinput - 1], false);
                    }
                }
            }
        }
        RepaintCar(&cars[iinput - 1], DetermineColour(cars[iinput-1],false));
        std::cout << cars[iinput-1].year << " ";
        DetermineColour(cars[iinput-1], true);
        std::cout << " " << cars[iinput-1].make << " " << cars[iinput-1].model << " with " << cars[iinput-1].mileage << " miles." << std::endl;

        break;
    }
#pragma endregion

#pragma region Part 4
    for (int i = 0; i < 3; i++) 
    {
        AddMileage(&cars[i], 500);
        PrintCar(cars[i], i + 1);
    }
#pragma endregion
}

void RepaintCar(Car* car, Colors colour)
{
    (*car).Colour = colour;
}

#pragma region Part 3
void PrintCar(Car car, int carnum)
{
    std::cout << "Car " << carnum << " - " << car.year << " ";
    DetermineColour(car, true);
    std::cout << " " << car.make << " " << car.model << " with " << car.mileage << " miles." << std::endl;
}

void PrintCarPointer(Car* car, int carnum)
{
    std::cout << "*Car " << carnum << " - " << (*car).year << " ";
    DetermineColour(*car, true);
    std::cout << " " << (*car).make << " " << (*car).model << " with " << (*car).mileage << " miles." << std::endl;
}
#pragma endregion

void AddMileage(Car* car,int miles)
{
    (*car).mileage += miles;
}

Colors DetermineColour(Car vehicle, bool print)
{
    Colors returncolor = White;
    switch (vehicle.Colour)
    {
    case 1:
    {
        if (print)
        {
            std::cout << "White";
        }
        else vehicle.Colour = White;

        returncolor = White;
        break;
    }
    case 2:
    {
        if (print)
        {
            std::cout << "Black";
        }
        else vehicle.Colour = Black;
        returncolor = Black;
        break;
    }
    case 3:
    {
        if (print)
        {
            std::cout << "Gray";
        }
        else vehicle.Colour = Gray;
        returncolor = Gray;
        break;
    }
    case 4:
    {
        if (print)
        {
            std::cout << "Silver";
        }
        else vehicle.Colour = Silver;
        returncolor = Silver;
        break;
    }
    case 5:
    {
        if (print)
        {
            std::cout << "Red";
        }
        else vehicle.Colour = Red;
        returncolor = Red;
        break;
    }
    case 6:
    {
        if (print)
        {
            std::cout << "Blue";
        }
        else vehicle.Colour = Blue;
        returncolor = Blue;
        break;
    }
    case 7:
    {
        if (print)
        {
            std::cout << "Brown";
        }
        else vehicle.Colour = Brown;
        returncolor = Brown;
        break;
    }
    case 8:
    {
        if (print)
        {
            std::cout << "Green";
        }
        else vehicle.Colour = Green;
        returncolor = Green;
        break;
    }
    case 9:
    {
        if (print)
        {
            std::cout << "Orange";
        }
        else vehicle.Colour = Orange;
        returncolor = Orange;
        break;
    }
    default:
        break;
    }
    return returncolor;
}
//Program 2
void IntAddress(int num, int *pointer)
{
    std::cout << "Number: " << num << '\t' << "Memory Address: " << &num << '\t' << std::endl;
    std::cout << "Pointer: " << pointer << '\t' << "Memory Address: " << &pointer << '\t' << std::endl;
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
