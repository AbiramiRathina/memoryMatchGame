#include <iostream>
#include <time.h>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;
class memory_game
{
    struct card
    {
        char *word;
        int number;
        card *left;
        card *right;
        int height;
        card( char * w,const int &n,card* l,card* r,int h):number(n),left(l),right(r),height(h){
            int size=strlen(w);
            word=new char[size+1];
            strcpy(word,w);
        }
    };
    card* order_of_cards[16];
    card *root;
    static int pos;
    static int o;
    public:
        memory_game();
        int height(card * t)const;
        void insert(char* w,const int &n);
        void insert( char* w,const int &n,card *& t);
        void singlerotatewithleft(card *& k2);
        void singlerotatewithright(card *& k2);
        void doublerotatewithleft(card *& k3);
        void doublerotatewithright(card *& k3);
        void check_before_removing(int num1,int num2);
        void remove(const int &n,card *& t);
        void balance(card *& t);
        card* findmin(card *t)const
        {
            if(t==NULL)
            {
                return NULL;
            }
            if(t->left==NULL)
            {
                return t;
            }
            return findmin(t->left);
        }
        void display();
        void placing_cards_in_order();
        void placing_cards_in_order(card *&t);
        void generate();
        void display2();
        void display3(int num1,int num2);
        void choice();
        void instruction();
        void user();
        void score();
        int checking_root_null();
        card* get_node(int num)
        {
            card* t=root;
            while(t!=NULL)
            {
                if(num<t->number)
                {
                    t=t->left;
                }
                else if(num>t->number)
                {
                    t=t->right;
                }
                else
                {
                    return t;
                }
            }
            return NULL;
        }
};