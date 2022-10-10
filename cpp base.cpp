//справочная инфа по с++
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime> 


// friendly method дружественные методы

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


//Вынос поля, Вынесенные поля, Внешние поля данных: Конструкторы, Деструкторы, Методы.
//__________________________________________________________________

//#include <iostream>

class MyClass 
{
public:
    MyClass();  //называется прототип
    ~MyClass(); //т.с.
    void foo(); //т.с
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

//friendly class, Дружественные классы.

//есть ситуации когда надо чтобы наш класс мог работать с полями другого класса.
//в этом случае делаем наш класс Friend по отношению к другому классу.

//#include <iostream>
class Human;//!!!!!!!!! возможно не надо.
class Apple;//объявление класса Apple чтобы класс Human его видел.

class Human
{
public:
    //плохой код:
    //void eatApple( );
    
    //хороший код:
    void eatApple(Apple& apple);
};

class Apple 
{
    friend Human; //объявление о том что Human Дружественный к классу Apple.
                  //Human может видеть и работать со всеми полями класса Apple.
private:
    std::string apples[3]={"green apple", "red apple", "yellow apple"};
};


//плохой код для метода Human eatApple:
//void Human::eatApple() 
//{   
//    //Apple apple; <- потом отсюда фиг удалишь если обект класса динамический!!!!!!!!!!!!!
//    //std::cout << "Human can eat a" << apple.apples[0];
//}

//хороший код: вроде, но не точно. вообще должно быть видно в объявлении внутри класса Human ^^^
void Human::eatApple(Apple& apple)
{
    std::cout << "Human eat a" << apple.apples[0];
}

int main()
{
    Apple apple;
    Human human;
    human.eatApple(apple);
}
//__________________________________________________________________
//__________________________________________________________________