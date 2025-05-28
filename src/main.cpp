/*
Universidad Amerike
Author: José Sierra
Final Math Project
Date: 28/05/25
Description: This is my final math project
*/
#include <iostream>
#include <limits>
using namespace std;

int Decision;
float K_Keeper, N_Keeper;

//Useful function to skip printing steps in the console
void printinconsole(string text){cout << text << "\n";}

//Function applying the combination formula
void Combinations(float N, float K, float Subtraction)
{
    float Result;

    Result = N/(K * Subtraction);
    system("cls");
    cout << "Result: " << Result << "\n";
}
//Function applying the permutation formula
void Permutation(float N, float Subtraction)
{
    float Result;

    Result = N/Subtraction;
    system("cls");
    cout << "Result: " << Result << "\n";
}

//This function returns the factorial of each value entered in the parameters.
float Factorial(int N)
{
    float Result = N;
    float CycleN = N;
    if (N < 1)
    {
        printinconsole("N cant be lower than 1");
        cin.ignore();
        cin.get();
        exit(0);
    }
    
    for (int i = 0; i < N-1; i++)
    {
        Result = Result * (CycleN-1);
        CycleN = CycleN - 1;
    }
    
    return Result;
}

//This function allows you to enter the value of N
void Recieve_Value_N()
{
    float N, K;
    bool Loop = true;
    bool Loop2 = true;
    system("cls");
    while (Loop)
    {
        cout << "Input (N) Value:\n";
        cin >> N;


        if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                system("cls");
            }
            if (N <= 0)
            {
                system("cls");
                cout << "That is not a valid value\n";
                cin.ignore();
                cin.get();
            }
            else
            {
                Loop = false;
            }
    }

    N_Keeper = N;
}

//This function allows you to enter the value of K
void Recieve_Value_K()
{
    float K;
    bool Loop = true;
    system("cls");
    while (Loop)
    {
        cout << "Input (K) Value:\n";
        cin >> K;


        if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                system("cls");
            }
        if (K <= 0)
            {
                system("cls");
                cout << "That is not a valid value\n";
                cin.ignore();
                cin.get();
            }
        else if (K > N_Keeper)
            {
                system("cls");
                cout << "K cannot be bigger than N\n";
                cin.ignore();
                cin.get();
            }
        
        else
            {
                Loop = false;
            }
    }

    K_Keeper = K;

}

int main()
{    
    bool MasterLoop = true;
    while(MasterLoop)
    {
        
        float N, K, Subtraction;
        bool Loop = true;
        while (Loop)
        {   
            system("cls");
            printinconsole("---------------------CALCULATOR---------------------");
            printinconsole("What do you want to do?");
            printinconsole("1-Combinations");
            printinconsole("2-Permutations");
            printinconsole("3-Leave");
            cin >> Decision;
            if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    system("cls");
                }
                if (Decision <= 0 || Decision >= 4)
                {
                    system("cls");
                    cout << "That is not a valid value\n";
                    cin.ignore();
                    cin.get();
                }
                else
                {
                    Loop = false;
                }

        }

    //This verifies the entered decision
    if (Decision != 3)
    {
        Recieve_Value_N();
        Recieve_Value_K();
        N = Factorial(N_Keeper);
        K = Factorial(K_Keeper);
        Subtraction = Factorial(N_Keeper - K_Keeper);
    }
    
    switch (Decision)
    {
    case 1:
        Combinations(N, K, Subtraction);
        cin.ignore();
        cin.get();
        break;
    
    case 2:
        Permutation(N, Subtraction);
        cin.ignore();
        cin.get();
        break;
    case 3:
        MasterLoop = false; //This breaks the loop
        break;
    }
    
}
    return 0;

}