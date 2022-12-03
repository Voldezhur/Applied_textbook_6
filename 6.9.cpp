// Обратный вывод содержимого файла


#include <iostream>
#include <stack>
#include <fstream>


int main()
{
    std::stack<char> A;

    // Открытие файлов
    std::ofstream outputFile("outputFile.txt");
    std::ifstream inputFile("inputFile.txt");

    // Считывание строки
    std::string line;
    getline(inputFile, line);

    // Добавление элементов строки в стек
    for(int i = 0; i < line.length(); i++)
    {
        A.push(line[i]);
    }

    // Вывод и удаление элементов строки из стека
    for(int i = 0; i < line.length(); i++)
    {
        outputFile << A.top();
        A.pop();
    }

    // Закрытие файлов
    inputFile.close();
    outputFile.close();
}