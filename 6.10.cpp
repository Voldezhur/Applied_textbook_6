// Вывод чисел из файла с использованием очереди


#include <iostream>
#include <queue>
#include <fstream>


int main()
{
    std::queue<std::string> singleDigit;
    std::queue<std::string> twoDigit;

    // Открытие файлов
    std::ofstream queueOutput("queueOutput.txt");
    std::ifstream queueInput("queueInput.txt");

    // Считывание строки
    std::string line;
    getline(queueInput, line);

    // Цикл прохода по файлу
    std::string num = "";
    for(int i = 0; i < line.length(); i++)
    {
        if(isdigit(line[i])) num += line[i];
        
        // Добавление элементов строки в разные очереди, смотря сколько цифр в числе
        else
        {
            if(num.length() == 1) singleDigit.emplace(num);

            else twoDigit.emplace(num);

            num = "";
        }
    }

    // Окончательное добавление в очереди
    if(num.length() == 1) singleDigit.emplace(num);
    else twoDigit.emplace(num);
    num = "";


    // Вывод и удаление элементов из первой очереди
    int n = singleDigit.size();
    for(int i = 0; i < n; i++)
    {
        queueOutput << singleDigit.front() << ' ';
        singleDigit.pop();
    }
    
    // Вывод и удаление элементов из второй очереди
    n = twoDigit.size();
    for(int i = 0; i < n; i++)
    {
        queueOutput << twoDigit.front() << ' ';
        twoDigit.pop();
    }

    // Закрытие файлов
    queueInput.close();
    queueInput.close();
}