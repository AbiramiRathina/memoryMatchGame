#include <iostream>
#include <time.h>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
#include "memory_game.h"
using namespace std;
#define MAX 1000
int point;
char str[16][MAX]={"phone","table","book","pencil","bottle","laptop","car","chocolate","phone","table","book","pencil","bottle","laptop","car","chocolate"};
int i=0;
int memory_game::pos =0;
int memory_game::o =0;
memory_game::memory_game()
{
    root=NULL;
}
int memory_game::height(card * t)const
{
    return (t==NULL)?-1:t->height;
}
void memory_game::insert(char* w,const int &n)
{
    insert(w,n,root);
}
void memory_game::insert( char* w,const int &n,card *& t)
{
    if(t==NULL)
    {
        t=new card(w,n,NULL,NULL,-1);
    }
    else if(n<t->number)
    {
        insert(w,n,t->left);
        if(height(t->left)-height(t->right)==2)
        {
            if(n<t->left->number)
            {
                singlerotatewithleft(t);
            }
            else
            {
                doublerotatewithleft(t);
            }
        }
    }
    else if(n>t->number)
    {
        insert(w,n,t->right);
        if(height(t->right)-height(t->left)==2)
        {
            if(n>t->right->number)
            {
                singlerotatewithright(t);
            }
            else
            {
                doublerotatewithright(t);
            }
        }
    }
    else
    {
        ;
    }
    t->height=max(height(t->left),height(t->right))+1;
}
void memory_game::singlerotatewithleft(card *& k2)
{
    card* k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),k2->height)+1;
    k2=k1;
}
void memory_game::singlerotatewithright(card *& k2)
{
    card* k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->right),k2->height)+1;
    k2=k1;
}
void memory_game::doublerotatewithleft(card *& k3)
{
    singlerotatewithright(k3->left);
    singlerotatewithleft(k3);
}
void memory_game::doublerotatewithright(card *& k3)
{
    singlerotatewithleft(k3->right);
    singlerotatewithright(k3);
}
void memory_game::check_before_removing(int num1,int num2)
{
    card* c1;
    card* c2;
    c1=get_node(num1);
    c2=get_node(num2);
    if(c1==NULL || c2==NULL)
    {
        cout<<"\t\t\t\t\toops card was already deleted, try again"<<endl<<endl;
        return;
    }
    else if(strcmp(c1->word,c2->word)==0)
    {
        point+=10;
        remove(num1,root);
        remove(num2,root);
    }
    else
    {
        display3(num1,num2);
    }
}
void memory_game::remove(const int &n,card *& t)
{
    if(t==NULL)
    {
        return;
    }
    if(n<t->number)
    {
        remove(n,t->left);
    }
    else if(n>t->number)
    {
        remove(n,t->right);
    }
    else if(t->left!=NULL && t->right!=NULL)
    {
        t->number=findmin(t->right)->number;
        t->word=findmin(t->right)->word;
        remove(t->number,t->right);
    }
    else
    {
        card *oldNode=t;
        t=(t->left!=NULL)?t->left:t->right;
        delete oldNode;
    }
    balance(t);
}
void memory_game::balance(card *& t)
{
    if(t==NULL)
    {
        return;
    }
    if(height(t->left)-height(t->right)==2)
    {
        if(height(t->left->left)>=height(t->left->right))
        {
            singlerotatewithleft(t);
        }
        else
        {
            doublerotatewithleft(t);
        }
    }
    else
    {
        if(height(t->right)-height(t->left)==2)
        {
            if(height(t->right->right)>=height(t->right->left))
            {
                singlerotatewithright(t);
            }
            else
            {
                doublerotatewithright(t);
            }
        }
        t->height=max(height(t->left),height(t->right))+1;
    }
}
void memory_game::display()
{
    int position=0;
    cout<<endl;
    for(int i=0;i<65;i++)
    {
        cout<<"_";
    }
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"|";
        for(int j=0;j<4;j++)
        {
            if(order_of_cards[position]==NULL)
            {
                cout<<"\t\t";
            }
            else if(strcmp(order_of_cards[position]->word,"phone")==0)
            {
                cout<<"\033[1;31m"<<order_of_cards[position]->word<<"\033[0m"<<"\t\t";
            }
            else if(strcmp(order_of_cards[position]->word,"table")==0)
            {
                cout<<"\033[1;32m"<<order_of_cards[position]->word<<"\033[0m"<<"\t\t";
            }
            else if(strcmp(order_of_cards[position]->word,"book")==0)
            {
                cout<<"\033[1;33m"<<order_of_cards[position]->word<<"\033[0m"<<"\t\t";
            }
            else if(strcmp(order_of_cards[position]->word,"pencil")==0)
            {
                cout<<"\033[1;34m"<<order_of_cards[position]->word<<"\033[0m"<<"\t\t";
            }
            else if(strcmp(order_of_cards[position]->word,"bottle")==0)
            {
                cout<<"\033[1;35m"<<order_of_cards[position]->word<<"\033[0m"<<"\t\t";
            }
            else if(strcmp(order_of_cards[position]->word,"laptop")==0)
            {
                cout<<"\033[1;36m"<<order_of_cards[position]->word<<"\033[0m"<<"\t\t";
            }
            else if(strcmp(order_of_cards[position]->word,"car")==0)
            {
                cout<<"\033[1;37m"<<order_of_cards[position]->word<<"\033[0m"<<"\t\t";
            }
            else if(strcmp(order_of_cards[position]->word,"chocolate")==0)
            {
                cout<<"\033[1;100m"<<order_of_cards[position]->word<<"\033[0m"<<"\t";
            }
            else
            {
                cout<<"\t\t";
            }
            position++;
        }
        cout<<"|"<<endl;
    }
    for(int i=0;i<65;i++)
    {
        cout<<"_";
    }
    cout<<endl;
}
void memory_game::placing_cards_in_order()
{
    placing_cards_in_order(root);
}
void memory_game::placing_cards_in_order(card *&t)
{
    if(t!=NULL)
    {
        placing_cards_in_order(t->left);
        order_of_cards[o]=t;
        o++;
        placing_cards_in_order(t->right);
    }
}
void memory_game::generate()
{
    srand((unsigned)time(NULL));
    int r_num;
    int order[16];
    for(int i=0;i<16;i++)
    {
        order[i]=i;
    }
    for(int i=15;i>0;i--)
    {
        int pos=rand()%(i+1);
        int temp=order[pos];
        order[pos]=order[i];
        order[i]=temp;
    }
    for(int i=0;i<16;i++)
    {
        insert(str[order[i]],pos);
        pos++;
    }
}
void memory_game::display2()
{
    pos=0;
    int flag=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            card *temp=get_node(pos);
            pos++;
            if(temp==NULL)
            {
                cout<<"\t\t\t";
                continue;
            }
            else
            {
                cout<<temp->number+1<<"\t\t\t";
            }
            if(pos>=16)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
}
void memory_game::display3(int num1,int num2)
{
    pos=0;
    int flag=0,flag2=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            card *temp=get_node(pos);
            if(pos==num1 || pos==num2 && temp!=NULL)
            {
                flag2=1;
                if(strcmp(temp->word,"phone")==0)
                {
                    cout<<"\033[1;31m"<<temp->word<<"\033[0m"<<"\t\t";
                }
                else if(strcmp(temp->word,"table")==0)
                {
                    cout<<"\033[1;32m"<<temp->word<<"\033[0m"<<"\t\t";
                }
                else if(strcmp(temp->word,"book")==0)
                {
                    cout<<"\033[1;33m"<<temp->word<<"\033[0m"<<"\t\t";
                }
                else if(strcmp(temp->word,"pencil")==0)
                {
                    cout<<"\033[1;34m"<<temp->word<<"\033[0m"<<"\t\t";
                }
                else if(strcmp(temp->word,"bottle")==0)
                {
                    cout<<"\033[1;35m"<<temp->word<<"\033[0m"<<"\t\t";
                }
                else if(strcmp(temp->word,"laptop")==0)
                {
                    cout<<"\033[1;36m"<<temp->word<<"\033[0m"<<"\t\t";
                }
                else if(strcmp(temp->word,"car")==0)
                {
                    cout<<"\033[1;37m"<<temp->word<<"\033[0m"<<"\t\t";
                }
                else if(strcmp(temp->word,"chocolate")==0)
                {
                    cout<<"\033[1;100m"<<temp->word<<"\033[0m"<<"\t";
                }
                else
                {
                    cout<<"\t\t";
                }
            } 
            else if(temp!=NULL)
            {
                cout<<temp->number+1<<"\t\t";
            }
            else
            {
                cout<<"\t\t";
            }
            pos++;
            if(pos>=16)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
    if(flag2==1)
    {
        sleep(1);
        system("clear");
    } 
}
void memory_game::choice()
{
    cout<<"Choose a level :D "<<endl<<endl;
    cout<<"1.EASY\n"<<"2.MEDIUM\n3.DIFFICULT\n\n";
    int n;
    cout<<"Enter choice : "<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            display();
            sleep(9);
            break;
        }
        case 2:
        {
            display();
            sleep(6);
            break;
        }
        case 3:
        {
            display();
            sleep(3);
            break;
        }
        default:
        {
            cout<<"Enter valid Level"<<endl;
        }
    }
}
void memory_game::instruction()
{
    cout<<endl<<"INSTRUCTION MANUAL"<<endl;
    cout<<endl;
    cout<<" ~ The objective is to collect the most pairs of cards."<<endl;
    cout<<" ~ User should choose a Level of difficulty"<<endl;
    cout<<" ~ The cards initially will be shuffled and displayed."<<endl;
    cout<<" ~ After few seconds the words will disappear and corresponding numbers will be displayed, on each turn, a player chooses any two numbers and for each matching pair a point will be awarded. "<<endl;
    cout<<endl<<"   \t\tALL THE BEST :)"<<endl<<endl<<endl;
}
void memory_game::user()
{
    int a,b;
    cout<<"Enter the card number 1 : ";
    cin>>a;
    cout<<"Enter the card number 2  : ";
    cin>>b;
    cout<<endl;if(a>16 || b>16)
    {
        cout<<"The card numbers are from 1-16"<<endl;
        return;
    }
    if(a!=b)
    {
        check_before_removing(a-1,b-1);
    }
    else
    {
        cout<<"\t\t\t\t\tEnter unique card numbers"<<endl<<endl<<endl;
    }
}
void memory_game::score()
{
    if(root!=NULL)
    {
        cout<<endl<<endl<<endl<<"Your score is "<<point<<" / "<<80<<endl;
        cout<<"Oops sorry you lost the game, better luck next time user :("<<endl<<endl<<endl;
    }
    else
    {
        cout<<endl<<endl<<endl<<"yeahhhh!!!!!YOu Won tHe GamE, yOUR SCore Is "<<point<<" / "<<80<<endl<<endl<<endl;
    }
}
int memory_game::checking_root_null()
{
    if(root!=NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}