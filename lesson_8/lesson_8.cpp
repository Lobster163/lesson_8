#include "include/lesson_8.h"


int main()
{
    std::cout << "punkt_1:" << endl;
    cout << check(2, 2) << endl;
    std::cout << "---------------------------" << endl;


    std::cout << "punkt_2:" << endl;
    //bar;// = make_unique<Bar>(5)
    bool work = true;
    unique_ptr<Bar> bar = make_unique<Bar>();
    while (work)
    {
        try
        {
            string n;
            int status = true;
            cout << "Enter N = ";
            cin >> n;
            for (char v : n)
            {
                if ((int)v < 48 || (int)v > 57)
                {                    
                    status = 0;
                    break;
                }

                if ((int)v == 48 && n.size() == 1)
                {
                    status = 2;
                    break;
                }

                status = 1;
            }

            if (status == 1)
            {
                bar->Set(stof(n));
                cout << bar->Get() << endl;
            }
            else if (status == 2)
                work = false;

        }
        catch (EX& ex)
        {
            cout <<"Ex " << ex.m_x << endl;
        }
    }
    std::cout << "---------------------------" << endl;

    std::cout << "punkt_3:" << endl;
    Robot* robot = new Robot(0, 0);
    int cmd;
    bool game = true;
   
    
    while (game)
    {
        
        system("cls");
        cout << "press button \"Enter\" ror \"Esc\" for exit" << endl;
        robot->PrintDeck(); //рисуем доску
        
        cmd = _getch();    
        try
        {
            switch (cmd)
            {
            case 72:
                robot->ChangePosition(CMD::up);
                break;
            case 80:
                robot->ChangePosition(CMD::down);
                break;
            case 75:
                robot->ChangePosition(CMD::left);
                break;
            case 77:
                robot->ChangePosition(CMD::right);
                break;
            case 27: //Esc
            case 13: //exit enter
                game = false;
                break;
            }
        }
        catch (OffTheField& exOffTheField)
        {
            position = { 0, 11 };
            SetConsoleCursorPosition(hConsole, position);
            cout << "Out of range matrix" << endl;            
            cout << "Current Position (x:"<<exOffTheField.m_pos_x+1;
            cout << ", y:" << exOffTheField.m_pos_y+1 <<")" << endl;
            cout << "CMD-> " << GetNameCMD(exOffTheField.m_cmd) << endl;
            system("pause");

        }
        catch (IllegalCommand& exIllegalCommand)
        {

        }

    }
    system("cls");
    //robot->PrintDeck();
    delete robot;
    std::cout << "---------------------------" << endl;
}

void ExceptionFunct()
{

}