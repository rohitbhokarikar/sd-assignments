#include <iostream>
#include <cstdlib>
using namespace std;
class tnode
{
    int data;
    int l,r;
    tnode *lt,*rt;
    public:

    tnode *create(int item)
    {
        tnode *nn=new tnode;
        nn->data=item;
        nn->lt=nn->rt=NULL;
        nn->l=nn->r=1;
        return nn;
    }

    tnode *insert_r(tnode *r,int item)
    {
        tnode *rp=r;//current node
        tnode *p=NULL;//parent node of current
        while(rp!=NULL)
        {
            p=rp;
            if(item<rp->data)
            {
                if(rp->l==0)
                    rp=rp->lt;
                else
                    break;
            }
            else if(item>rp->data)
            {
                if(rp->r==0)
                    rp=rp->rt;
                else
                    break;
            }
        }
        tnode *nn;
        nn=nn->create(item);
        if(p==NULL)
        {
            r=nn;
        }
        else if(item<p->data)
        {
            nn->lt=p->lt;
            nn->rt=p;
            p->lt=nn;
            p->l=0;
        }
        else if(item>p->data)
        {
            nn->rt=p->rt;
            nn->lt=p;
            p->rt=nn;
            p->r=0;
        }
        return r;

    }

    void inorder(tnode *r)
    {
        tnode *temp=r;
        while(temp->l==0)
        {
            temp=temp->lt;
        }
        while(temp!=NULL)
        {

            cout<<temp->data<<endl;
            if(temp->r==1)
                temp=temp->rt;
            else
            {
                temp=temp->rt;
                while(temp->l==0)
                {
                    temp=temp->lt;
                }
            }
        }
    }

    void reverse_inorder(tnode *r)
    {
        tnode *temp=r;
        while(temp->r==0)
        {
            temp=temp->rt;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            if(temp->l==1)
                temp=temp->lt;
            else
            {
                temp=temp->lt;
                while(temp->r==0)
                {
                    temp=temp->rt;
                }
            }
        }
    }
};

tnode *root=NULL;
int main()
{
    system("COLOR FC");
    system("cls");
    char r;
    do
    {
        int flag=0;
        root=NULL;
        char op;
        do
        {
            if(flag==0)
            {
                int n;
                cout<<"\nEnter the total number of Elements - ";
                cin>>n;
                int a[n];
                cout<<"\nEnter The Elements - \n";
                for(int i =0;i<n;i++)
                {
                    cin>>a[i];
                    root=root->insert_r(root,a[i]);
                }
                flag=1;
            }
            int c;
            cout<<"\n======================Menu=========================\n";
            cout<<"\n1. Insert\n2. Display Ascending\n3. Display Descending\n";
            cout<<"\n===================================================\n";
            cout<<"\nEnter your choice - ";
            cin>>c;
            switch(c)
            {
                case 1: {
                            int item;
                            cout<<"\n=============================================\n";
                            cout<<"\nEnter the Data - ";
                            cin>>item;
                            cout<<"\n=============================================\n";
                            root=root->insert_r(root, item);
                        }
                        break;
                case 2: {
                            cout<<"\n=============================================\n";
                            root->inorder(root);
                            cout<<"\n=============================================\n";
                        }
                        break;
                case 3: {
                            cout<<"\n=============================================\n";
                            root->reverse_inorder(root);
                            cout<<"\n=============================================\n";
                        }
                        break;
                default:cout<<"\nInvalid\n";
        }
        cout<<"\nDo you want to continue - ";
        cin>>op;
        }while(op=='y' || op=='Y');
        }while(r=='n' || r=='N');
    return 0;
}

