#include <iostream>
#include <cstdlib>
using namespace std;
class rb
{
    int n=10;
    int arr[100][3];
    int c;
public:
    rb()
    {
        for(int i=0;i<n;i++)
        {
            arr[i][0]=0;
            arr[i][1]=-1;
            arr[i][2]=-1;
        }
        c=0;
    }
    void add(int,int);
    int find_key(int);
    void display();
    void update_val(int,int);
};
void rb::add(int key,int value)
{
    int new_hash_addr1,new_hash_addr2,main_hash_addr=-1,j=0;
    if(this->find_key(key)!=-1)
    {
        cout<<"Key already exists\n";
        return;
    }
    if(c==(n-1))
    {
        cout<<"Table full, request denied\n";
    }
    new_hash_addr1=(key)%n;
    new_hash_addr1=1+(key%(n-1));
    if(arr[new_hash_addr1][1]==-1)
    {
        arr[new_hash_addr1][0]=key;
        arr[new_hash_addr1][1]=value;
    }
    else if(arr[new_hash_addr2][1]==-1)
    {
        arr[new_hash_addr2][0]=key;
        arr[new_hash_addr2][1]=value;
    }
    else
    {
        while(arr[new_hash_addr2][2]!=-1)
        {
            main_hash_addr=new_hash_addr2;
            new_hash_addr2=arr[main_hash_addr][2];
        }
        main_hash_addr=new_hash_addr2;
        for(int i=0;i<n;i++)
        {
            new_hash_addr2=(main_hash_addr+i)%n;
            if(arr[new_hash_addr2][1]==-1)
            {
                arr[new_hash_addr2][0]=key;
                arr[new_hash_addr2][1]=value;
                arr[main_hash_addr][2]=new_hash_addr2;
                c++;
                break;
            }
        }
    }
}
void rb::display()
{
    cout<<"Key\t\tValue\t\tChain\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i][0]<<"\t\t"<<arr[i][1]<<"\t\t"<<arr[i][2]<<endl;
    }
}
int rb::find_key(int key)
{
    int search_addr=key%n,f=0;
    while(arr[search_addr][0]!=key && arr[search_addr][2]!=-1)
    {
        search_addr=arr[search_addr][2];
    }
    if(arr[search_addr][0]==key)
    {
        return arr[search_addr][1];
    }
    else if(arr[search_addr][2]==-1)
    {
        return -1;
    }
}
int main()
{
    system("COLOR FC");
    system("cls");
    char r;
    do
    {
        char op;
        rb table;
        int c;
        do
        {
            cout<<"\n=======================Menu==================\n";
            cout<<"1] Insert value\n2] Display\n";
            cout<<"\n=============================================\n";
            cout<<"\nEnter your choice - ";
            cin>>c;
            switch(c)
            {
                case 1: {
                            int key,val;
                            cout<<"\nEnter key - ";
                            cin>>key;
                            cout<<"\nEnter value - ";
                            cin>>val;
                            table.add(key,val);
                        }
                        break;
                case 2: table.display();
                        break;
                default:cout<<"ERROR....Invalid\n";
            }
            cout<<"\nDo you want to continue -  ";
            cin>>op;
        }while(op=='y' || op=='Y');
        }while(r=='n' || r=='N');
    return 0;
}
