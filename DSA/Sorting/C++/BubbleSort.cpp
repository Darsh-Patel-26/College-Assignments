#include"iostream"

using namespace std;

int n;

void setArray(int arr[])
{
    cout<<"Enter "<<n<<" no. :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

void getArray(int arr[])
{
    cout<<"Array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int arr[])
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    setArray(arr);
    bubbleSort(arr);
    getArray(arr);
    return 0;
}
