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

void selectionSort(int arr[])
{
    for (int i = 0; i < n-1; i++)
    {
        int small = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[small]>arr[j])
            {
                small = j;
            }
        }
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    setArray(arr);
    selectionSort(arr);
    getArray(arr);
    return 0;
}