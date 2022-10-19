//справочная инфа по с++
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime> 
#include <exception>



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


//#static fields, #статические поля класса, #статик поле, #статик метод, #статический метод, #static method
//__________________________________________________________________
//любое статик поле для всех обьектов класса одно, если поменять значение поля,
//значение поменяется у всех обьектов, это итак очевидно.
//интересная инициализация и поле можно вызвать из класса.

//#include <iostream>

class Boot
{
public:
    std::string color;
    static int getDurability()
    {
        return durability;
    }
    static void setColor(Boot &boot, std::string newColor)
    {
        boot.color = newColor;
    }
private:
    static int durability; //объявление в классе.
                           //можно использовать для подсчета созданных обектов класса
                           // типа static int count;
                           // в конструкторе прибавлять значение count++;
                           // в деконструкторе убавлять count--;
                           // так же можно использовать для генерации id обьекта
                           //count++;id = count; предмета.
};
int Boot::durability = 0;  //обазательно инициализация. два двоеточия - обращение полю класса. это важно!!!


int main()
{
    std::string color = "Brown";
    Boot boot;
    Boot::setColor(boot, color);
    std::cout << "Now boot color is: " << boot.color << std::endl;
    std::cout << Boot::getDurability(); //тот самый вызов из класса, а не из обьекта.
}
//__________________________________________________________________
//__________________________________________________________________


//#Вынос поля, #Вынесенные поля, #Внешние поля данных: Конструкторы, Деструкторы, Методы.
//__________________________________________________________________

//#include <iostream>

class MyClass 
{
public:
    MyClass();  //называется прототип
    ~MyClass(); //т.с.
    void foo(); //т.с
};

MyClass::MyClass() //два двоеточия - обращение полю класса. это важно!!!
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

//#friendly class, #Дружественные классы.

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
void Human::eatApple(Apple& apple) //два двоеточия - обращение полю класса. это важно!!!
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

//#except, #exceptions, #throw, #catch, #исключения, #ошибки
//В этолм классе куча разных типо исключений, использовал в работе 33.throw/catch в store
//#include <iostream>
//#include <exception>
void enterI(int &i)
{
    std::cin >> i;
    if (i == 1)
    {
        throw std::exception();
    }
    if (i > 3 && i < 6)
    {
        throw std::invalid_argument("invalid argument");//одно из тех разных типов исключений
    }
}

int main() {
    int i = 0;
    
    try
    {
        enterI(i);
        std::cout << "i is: " << i;                     //сообщение выведется только если ввод будет правильным
    }                                                   //если будет ошибка то как будто сработает break...
    
    catch (const std::exception& x) 
    {
        std::cout << "Work exception: " << x.what();    //... и выведется сообщение с ошибкой.
    }
}
//__________________________________________________________________
//__________________________________________________________________

//#exception #Наследование исключений. #Переопределение #what(), #Gереопределение метода what(). это оч круто.
//#include<iostream>
//#include<exception>

class MoreThen10 : public std::exception
{
public:                                       //чтобы метод what() было видно из &x в момент catch
    const char* what() const noexcept override//чтобы перегрузить, переопределить what, надо в точности его описать
    {                                         //noexcept - указывает на то что наш метод сам не генерирует исключения
        return "More then 10.\n";
    }
};

void enterI(int& i)
{
    std::cin >> i;
    if (i == 1)
    {
        throw std::exception();
    }else
    if (i > 3 && i < 6)
    {
        throw std::invalid_argument("invalid argument");//одно из тех разных типов исключений
    }else
    if (i > 10)
    {
        throw MoreThen10();//наше новое исключение.
    }else
    if (i == 0) // бросок для catch(...)
    {
        throw i;
    }
}

int main()
{
    int i = 0;
    bool input = true;
    while (input)
    {
        try
        {
            enterI(i);
            std::cout << "i is: " << i;
        }
        catch (const MoreThen10 &x) // можно ловить именно наши исключения в отличии от std::exception ниже
        {
            std::cerr << x.what();  //вызываем соответственно метод what из класса MoreThen10
        }
        catch (const std::exception& x) // ловит все исключения если перед ним нет какит то четко обозначенных.
        {
            std::cerr << "Work exception: " << x.what() << std::endl;
            std::cerr << "program will close now" << std::endl;
            input = false;
        }
        catch (...) // ловит любое исключение, опять же если перед ним не осписано какое либо другое исключение. 
        {
            std::cerr << "Some think wrong" << std::endl;
            input = false;
        }

    }
}
//__________________________________________________________________
//__________________________________________________________________
 

//#end