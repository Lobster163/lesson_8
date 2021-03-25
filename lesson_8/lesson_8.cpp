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
}
