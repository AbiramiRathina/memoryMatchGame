#include <iostream>
#include <time.h>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
#include "memory_game.h"
using namespace std;
int main()
{
    memory_game m;
    m.generate();
    cout<<endl;
    m.placing_cards_in_order();
    cout<<"*********************************************************************************************************************************************************************************************************"<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\t\tWELCOME TO PEXESO (MEMORY GAME)"<<endl<<endl;
    cout<<"*********************************************************************************************************************************************************************************************************"<<endl;
    m.instruction();
    m.choice();
    system("clear");
    int i;
    for(i=1;i<=10;i++)
    {
        if(m.checking_root_null()==1)
        {
            break;
        }
        m.display2();
        m.user();
    }
    m.score();
    return 0;
}