#include<iostream>
#include<iomanip>
using namespace std;
class contact
{
private:
    char name[50],mobile[50],email[50],insta[50],twitter[50];

public:
    void accept()
    {
        cout<<"enter name : ";
        cin>>name;
        cout<<"enter mobile no : ";
        cin>>mobile;
        cout<<"enter email : ";
        cin>>email;
        cout<<"enter insta id : ";
        cin>>insta;
        cout<<"enter twitter : ";
        cin>>twitter;
    }
    void display()
    {
        cout<<left;

        cout<<setw(20)<<name;
        cout<<"\t"<<setw(20)<<mobile;
        cout<<"\t"<<setw(20)<<email;
        cout<<"\t"<<setw(20)<<insta;
        cout<<"\t"<<setw(20)<<twitter<<endl;

    }
    friend void delete_contact();
    friend void update();
    friend void Search(int i);
    friend void add_contacts();
};
void delete_contact();
void update();
void Search(int i);
void add_contacts();
