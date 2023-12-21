#include<iostream>
#include"contact.cpp"
#include<fstream>
#include<string.h>
using namespace std;
contact obj;
void Search(int i)
{

        if(i==1)
        {
           char name[50];
        cout<<"enter name to be searched : ";
        cin>>name;
        fstream rd;
        rd.open("mydata.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            obj.display();
        }
    }
        }
    else if(i==2)
    {
        char email[50];
        cout<<"enter email : ";
        cin>>email;
        fstream rd;
        rd.open("mydata.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.email,email)==0)
        {
            obj.display();
        }
    }
    }
    else if(i==3)
    {
        char mobile[50];
        cout<<"enter mobile number : ";
        cin>>mobile;
        fstream rd;
        rd.open("mydata.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.mobile,mobile)==0)
        {
            obj.display();
        }
    }
    }
}
void update()
{
    char name[50];
    cout<<"enter name to be updated : ";
    cin>>name;
    fstream rd;
    fstream wr;
    rd.open("mydata.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    wr.open("tempfile.txt",ios::app);
    int flag=0;
    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0)
        {
            flag=1;
            obj.accept();

        }
        wr.write((char *)&obj,sizeof(obj));

    }
    if(flag==0)
    {
        cout<<"contact not available "<<endl;
    }
    rd.close();
    wr.close();
    remove("mydata.txt");

    rename("tempfile.txt","mydata.txt");

}
void delete_contact()
{

    char name[50];
    cout<<"enter name to be deleted : ";
    cin>>name;
    fstream rd;
    fstream wr;
    rd.open("mydata.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    wr.open("tempfile.txt",ios::app);
    int flag=0;
    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&obj,sizeof(obj));

        if(strcmp(obj.name,name)==0)
        {
            flag=1;
            cout<<"contact removed ";
            cout<<endl;

        }
        else
        {


            wr.write((char *)&obj,sizeof(obj));
        }
    }
    if(flag==0)
    {
        cout<<"contact is not present "<<endl;
    }
    rd.close();
    wr.close();
    remove("mydata.txt");

    rename("tempfile.txt","mydata.txt");


}
void add_contacts()
{

    char name[50];
    //cout<<"enter name to be added : ";
    //cin>>name;
    fstream rd;
    rd.open("mydata.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    int flag=0;
    for(int i=1; i<=n; i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(name,obj.name)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        obj.accept();
         fstream wr;
    wr.open("mydata.txt",ios::app);

    wr.write((char *)&obj,sizeof(obj));
    wr.close();
    cout<<"content pushed "<<endl;
    }
    else
    {
        cout<<"duplicate name "<<endl;
    }



}
void view()
{
    fstream rd;
    rd.open("mydata.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
        cout<<left;

        cout<<setw(20)<<"Name";
        cout<<"\t"<<setw(20)<<"Mobile_no";
        cout<<"\t"<<setw(20)<<"Email_Address";
        cout<<"\t"<<setw(20)<<"Insta_Handle";
        cout<<"\t"<<setw(20)<<"Twitter_Handle"<<endl;
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=1; i<=n; i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        obj.display();
    }
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}
int main()
{
    while(1)
    {
        cout<<"enter 1 to add contact"<<endl;
        cout<<"enter 2 to delete contact"<<endl;
        cout<<"enter 3 to update contact"<<endl;
        cout<<"enter 4 to view all contacts"<<endl;
        cout<<"enter 5 to search"<<endl;
        cout<<"enter 6 to exit"<<endl;
        int choice;
        cout<<"enter choice : ";
        cin>>choice;
        if(choice==6)
        {
            break;
        }
        switch(choice)
        {
        case 1:
            {

                add_contacts();
                break;
            }
        case 2:
            {
                delete_contact();
                break;
            }
        case 3:
            {
               update();
               break;

            }
        case 4:
            {
                view();
                break;
            }
        case 5:
        {
            int n;
            cout<<"enter 1 to search by name "<<endl;
            cout<<"enter 2 to search by email "<<endl;
            cout<<"enter 3 to search by mobile number "<<endl;
            cout<<"enter choice : ";
            cin>>n;
            Search(n);
            break;
        }
        default:
        {
            break;
        }

        }
    }


}
