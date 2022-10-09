//справочная инфа по с++
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime> 
//__________________________________________________________________
// friend дружественные функции и классы

//#include <iostream>
class Test
{   
    private:
        int test1 = 1;
    protected:
        std::string test2 = "test2";
    public:
        Test()
        {
            std::cout << " Cool Friendly Function For Test" << std::endl;
        }
    friend void Test3(Test &value);
};

void Test3(Test &value)
{
    std::cout << "test" << value.test1 << std::endl;
    std::cout << value.test2 << std::endl;
}
int main()
{
    Test test;
    Test3(test);
}
//__________________________________________________________________
