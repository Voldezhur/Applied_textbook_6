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
    bool ans = true;    
    for (int i = 0; i < N - 1; i++)
    {
        if(A[i] < A[i + 1])
        {   
            ans = false;
            break;
        }
    }
    
    cout << '\n' << (ans ? "Массив упорядочен по возрастанию" : "Массив не упорядочен");
    cout << '\n';


    delete[] A;
}