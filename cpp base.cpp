//справочная инфа по с++
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime> 


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
    friend void Test3(Test &value); //обьявление в классе,
};

void Test3(Test &value)             //интересная функция которая ссылается на обект класса в котором все поля открыты.
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
//__________________________________________________________________


//static fields, статические поля класса, статик поле
//__________________________________________________________________
//любое статик поле для всех обьектов класса одно, если поменять значение поля,
//значение поменяется у всех обьектов, это итак очевидно.
//интересная инициализация и поле можно вызвать из класса.

//#include <iostream>

class Boot
{
public:
    static int durability; //объявление в классе.

};
int Boot::durability = 0;  //инициализация.


int main()
{
    Boot::durability = 20; //тот самый вызов из класса, а не из обьекта.
    std::cout << Boot::durability;
}
//__________________________________________________________________
//__________________________________________________________________


//Вынос, Вынесенные, Внешние поля данных: Конструкторы, Деструкторы, Методы.
//__________________________________________________________________

//#include <iostream>

class MyClass 
{
public:
    MyClass();
    ~MyClass();
    void foo();
};

MyClass::MyClass()
{
    std::cout << "конструктор класса" << std::endl;
}

MyClass::~MyClass()
{
    std::cout << "деконструктор класса" << std::endl;
}

void MyClass::foo()
{
    std::cout << "функция foo" << std::endl;
}

int main()
{
    MyClass mClass;
    mClass.foo();
}

//__________________________________________________________________
//__________________________________________________________________