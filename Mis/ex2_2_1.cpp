#include "convention.h"

vi vec{7,6,5,4,3,2,1,0};

void q4()
{
    std::sort(vec.begin(), vec.end()); //nlogn
    for (auto& n: vec)
    {
        if (n >= 2 && n <= 5)
        {
            printf("%d ", n);
        }
    }
}

void q2()
{
    int target = 13;
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        int comp = target - vec[i];
        auto it = lower_bound(vec.begin(), vec.end(), comp); //first_equal_to_or_greater_than
        if (*it == comp)
        {
            printf("%d + %d = %d", vec[i], comp, target);
            return;
        }
    }
}

int main()
{
    q2();
    
}