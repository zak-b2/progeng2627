#include <iostream>
#include <vector>

int main(){
    std::cout<<"How many elements in the vector : ";
    int n;
    int input;
    std::vector<int> v;
    std::cin>>n;
    for (int i=0; i<n; i++)
    {
    std::cout<<"Enter an element into the vector"<<std::endl;
        std::cin>>input;
        v.push_back(input);
    }
    std::cout<<"Enter the filter value : ";
    int f;
    std::cin>>f;
    
    for(int i=0; i<n; i++)
    {
        if (v[i] < f)
        {
            std::cout<<v[i]<<std::endl;
        }
    }

    std::cout<<"Count occurances of : ";
    int s;
    std::cin>>s;
    int count = 0;

    for(int i=0; i<n; i++)
    {
        count += s == v[i];
        if (s == v[i])
            std::cout<<"Index "<<i<<std::endl;
    }

    std::cout<<"There are "<<count<<" occurances of "<<s<<std::endl;
}