#include<iostream>
using namespace std;
class HeapSort
{
   int heap[20],heap1[20],x,n1,i;
   public:
   HeapSort()
   {
       heap[0]=0;  heap1[0]=0;
   }
   void getdata();
   void insertMax(int heap[],int);
   void buildMax(int heap[],int);
   void insertMin(int heap1[],int);
   void buildMin(int heap1[],int);
   void minmax();
};
void HeapSort::getdata()
{
   cout<<"\nEnter no. of students -";
   cin>>n1;
   cout<<"\nEnter marks - ";
   for(i=0;i<n1;i++)
   {   cin>>x;
       insertMax(heap,x);
       insertMin(heap1,x);
   }
}
void HeapSort::insertMax(int heap[20],int x)
{
   int n;
   n=heap[0];
   heap[n+1]=x;
   heap[0]=n+1;

   buildMax(heap,n+1);
}
void HeapSort::buildMax(int heap[20],int i)
{
    int temp;
    while(i>1&&heap[i]>heap[i/2])
    {
       temp=heap[i];
       heap[i]=heap[i/2];
       heap[i/2]=temp;
       i=i/2;
    }
}
void HeapSort::insertMin(int heap1[20],int x)
{
   int n;
   n=heap1[0];
   heap1[n+1]=x;
   heap1[0]=n+1;
   buildMin(heap1,n+1);
}
void HeapSort::buildMin(int heap1[20],int i)
{
    int temp1;
    while(i>1&&heap1[i]<heap1[i/2])
    {
       temp1=heap1[i];
       heap1[i]=heap1[i/2];
       heap1[i/2]=temp1;
       i=i/2;
    }
}
void HeapSort::minmax()
{
   cout<<"\nMaximum Marks -\n\n ";
   for(i=0;i<=n1;i++)
   {
          cout<<"\n"<<heap[i];
   }
   cout<<"\nMin Marks - \n\n";
   for(i=0;i<=n1;i++)
   {
       cout<<"\n"<<heap1[i];
   }
}
int main()
{
    HeapSort h;
    h.getdata();
    h.minmax();
    return 0;
}

