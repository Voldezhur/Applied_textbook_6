// Проверка массива на условие


#include <iostream>
#include <math.h>

using std::cin, std::cout;


int main()
{
    int* A = new int;
    int N;

    cout << "Введите размер массива:\n";
    cin >> N;

    cout << "\nВведите массив:\n";

    // Ввод массива
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }


    // Цикл проверки
    bool twoMembers = false, threeMembers = false;
    int t = 0;

    for(int i = 0; i < N; i++)
    {
        // Подсчет количества идущих подряд нулей
        if(A[i] == 0)
        {
            t++;
        }
        else t = 0;

        // Подряд идут два нуля
        if(t == 2)
        {
            twoMembers = true;
        }

        // Подряд идут три нуля - выход из цикла
        if(t == 3)
        {
            threeMembers = true;
            break;
        }
    }

    cout << "\nДва ненулевых числа подряд - " << (twoMembers ? "Истина" : "Ложь") << '\n';
    cout << "\nТри ненулевых числа подряд - " << (threeMembers ? "Истина" : "Ложь") << '\n';

    cout << '\n';


    delete[] A;
}