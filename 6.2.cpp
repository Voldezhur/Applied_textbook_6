// Подсчет количества натуральных чисел из массива по условию 2


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


    // Цикл подсчета
    int t = 0, sum = 0;
    for(int i = 0; i < N; i++)
    {
        if(A[i] % 5 == 0 && A[i] % 7 != 0)
        {
            t++;
            sum += A[i];
        }
    }

    cout << "\nКоличество подходящих чисел: " << t;
    cout << "\nСумма подходящих чисел: " << sum;
    cout << '\n';


    delete[] A;
}