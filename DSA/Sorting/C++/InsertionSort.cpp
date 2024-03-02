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

void insertionSort(int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (key<arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    setArray(arr);
    insertionSort(arr);
    getArray(arr);
    return 0;
}
