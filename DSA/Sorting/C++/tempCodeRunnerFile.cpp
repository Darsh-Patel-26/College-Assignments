#include"iostream"

int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    if(!n%2)
        std::cout<<"YES";
    else
        std::cout<<"NO";
    return 0;
}