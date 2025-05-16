#include<iostream>
using namespace std;
class initarray
{
public:
int n,arr[50];
int initial()
{
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The initialised array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    return 0;
}
};
class Insertarray:public initarray
{
    public:
    int insnum,insertpos,insertval;
    int insert(){
    cout<<"-------------------INSERT-INTO-ARRAY-------------------"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"The element "<<arr[i]<<" with position "<<i+1<<endl;
    }
    cout<<"Enter how many element do you want to insert:";
    cin>>insnum;
    for(int i=0;i<insnum;i++){
        cout<<"Enter the position of the element to  be insert";
        cin>>insertpos;
        cout<<"Enter the value of the element to be insert:";
        cin>>insertval;
        for(int i=n;i>insertpos;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[insertpos]=insertval;
    }
    cout<<"The Modified array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"The element "<<arr[i]<<" with position "<<i+1<<endl;
    }
   return 0; 
    }
};
class Removearray:public Insertarray
{
    public:
    int rempos;
    int remove()
    {
        cout<<"-------------------DELETE-OF-ARRAY-------------------"<<endl;

        for(int i=0;i<n;i++)
    {
        cout<<"The element "<<arr[i]<<"with position "<<i+1<<endl;
    }
    cout<<"Element the position of the element to be delete";
    cin>>rempos;
    for(int i=rempos;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    cout<<"The Modified array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"The element "<<arr[i]<<"with position "<<i+1<<endl;
    }
   return 0; 

    }
};
class multiarray:public Removearray
{
    public:
    int arr1[50],x;
    int multi()   
    {
        cout<<"-------------------MULTIPLICATION-OF-ARRAY-------------------"<<endl;
        for(int i=0;i<n;i++)
    {
        cout<<"The element "<<arr[i]<<"with position "<<i+1<<endl;
    }
        cout<<"By which number do you want to multiple with:";
        cin>>x;
        for(int i=0;i<n;i++)
        {
            arr1[i] = x*arr[i];

        }
        
        cout<<"The modified array:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"The element "<<arr1[i]<<"with position "<<i+1<<endl;
        }
        return 0;
    }
    
};
class Reversearray:public multiarray
{
    public:
    int arr2[50];
    int reverse()
    {

        cout<<"-------------------REVERSE-OF-ARRAY-------------------"<<endl;
        for(int j=0,i=0;i>=0;i--)
        {
           arr2[j]=arr[i]; 
           j++;
        }
        cout<<"The reversed array:"<<endl;
        return 0;
        cout<<"modified array:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<arr2[i]<<endl;
        }

    }
    
};
class Searcharray:public Reversearray
{
    public:
    int searchval,o=0;
    int search()
    {
        cout<<"-------------------SEARCH-OF-ARRAY-------------------"<<endl;
        cout<<"Enter the value of the element to be searched:";
        cin>>searchval;
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==searchval)
            {
                cout<<"Element "<<arr[i]<<"is at the "<<i+1<<"position";
                o=1;
            }
            
        }
        if(o==1)
            cout<<"element do not found ";
    return 0;
    }
};
int main()
{
    Searcharray a1;
    int choice;
    do
    {
        cout<<"------------------------WELCOME------------------------"<<endl;
        cout<<"1-INITIAL"<<endl;
        cout<<"2-INSERT"<<endl;
        cout<<"3-DELETE"<<endl;
        cout<<"4-MULTIPLY"<<endl;
        cout<<"5-REVERSE"<<endl;
        cout<<"6-SEARCH"<<endl;
        cout<<"7-EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            a1.initial();
            break;
        case 2:
            a1.insert();
            break;
        case 3:
            a1.remove();
            break;
        case 4:
            a1.multi();
            break;
        case 5:
            a1.reverse();
            break;
        case 6:
            a1.search();
            break;
        case 7:
            cout<<"----------THANK-YOU--------"<<endl;
            break;
        
        default:
            cout<<"invalid choice!";
        }
    } while (choice!=7);
    return 0;
    
}