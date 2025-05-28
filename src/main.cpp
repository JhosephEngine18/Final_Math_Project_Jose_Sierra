
#include <iostream>
#include <limits>
using namespace std;


int Required_possibilities = 0;
int Max_possibilities = 4;
float FactRQ = 0;
float FactMax = 0;
float SubstractedRequired_possibilities = Required_possibilities;
float HoldRequired_Posibilities = Required_possibilities;
int Decision;

void Start()
{
}

void Operations()
{
    bool Loop = true;
    bool Loop2 = true;
    system("cls");
    while (Loop)
    {
        cout << "Input (N) Value:\n";
        cin >> Max_possibilities;


        if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                system("cls");
            }
            if (Max_possibilities <= 0)
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

    while (Loop2)
    {
        system("cls");
        cout << "Input (K) Value:\n";
        cin >> Required_possibilities;


        if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                system("cls");
            }
            if (Required_possibilities <= 0)
            {
                system("cls");
                cout << "That is not a valid value\n";
                cin.ignore();
                cin.get();
            }
            else
            {
                Loop2 = false;
            }
    }

}

void Restart()
    {
        bool Loop = true;
        int DecisionToRestart;    
        while (Loop)
        {
            cout << "Do you want to Calculate something else?\n";
            cout << "1-Yes\n";
            cout << "2-No\n";
            cin >> DecisionToRestart;


            if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    system("cls");
                }
                if (Max_possibilities <= 0)
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

        switch (DecisionToRestart)
        {
        case 1:
            Start();
            break;
        
        case 2:
            exit(0);
            break;
        }

    }


float SubtractandFactorialBetweenMaxandRequired()
{
    float Result = 0;
    Result = Max_possibilities - Required_possibilities;
    float SubstractedResult = Result;
    float HoldResult = Result;


    for (int i = 0; i < Result; i++)
    {
        SubstractedResult = SubstractedResult - 1;
        Result = HoldResult * SubstractedResult;
        HoldResult = Result;

        if (SubstractedResult == 1)
        {
            break;
        }
    }
    return Result;

}

void combinations()
{
    float Result = 0;
    Result = FactMax / (FactRQ * SubtractandFactorialBetweenMaxandRequired());


    cout << Result;
}

void permutations()
{
    float Result = 0;

    Result = FactMax / SubtractandFactorialBetweenMaxandRequired();

    cout << Result;
}

int main()
{

    bool Loop = true;
    
    while (Loop)
    {
        system("cls");
        cout << "|---------------------------------------------------CALCULATOR---------------------------------------------------|\n";
        cout << "What do you want to do?\n";
        cout << "1-Combinations\n";
        cout << "2-Permutations\n";
        cin >> Decision;


        if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                system("cls");
            }
            if (Decision <= 0 || Decision >= 6)
            {
                system("cls");
                cout << "You have not selected any option\n";
                cin.ignore();
                cin.get();
            }
            else
            {
                Loop = false;
            }

    }

    system("cls");
    Operations();
    
    //These lines of code calculates the factorial of the total possibilities (N)
    if (Required_possibilities > 1)
    {
        for (int i = 0; i < Required_possibilities - 1; i++)
        {
            SubstractedRequired_possibilities = SubstractedRequired_possibilities - 1;
            FactRQ = HoldRequired_Posibilities * SubstractedRequired_possibilities;
            HoldRequired_Posibilities = FactRQ;
        }
    }
    else if (Required_possibilities <= 1)
    {
        Required_possibilities = 1;
        FactRQ = Required_possibilities;
    }

    //These lines of code calculates the factorial of the total possibilities (N)
    float SubstractedMax_possibilities = Max_possibilities;
    float HoldMax_Posibilities = Max_possibilities;
    for (int i = 0; i < Max_possibilities - 1; i++)
    {
        SubstractedMax_possibilities = SubstractedMax_possibilities - 1;
        FactMax = HoldMax_Posibilities * SubstractedMax_possibilities;
        HoldMax_Posibilities = FactMax;
    }
    
    switch (Decision)
    {
    case 1:
        combinations();
        break;
    
    case 2:

        permutations();
        break;
    }
    cin.get();

    //Restart Calculator?
    Restart();

    return 0;
}