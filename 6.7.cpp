// Связные списки 2


#include <iostream>


// Узел списка
struct Node
{
public:
    int val;
    Node* next;

    Node(int _val) : val(_val), next(nullptr){}
};

// Список
struct list
{
    Node* first;
    Node* last;

    int length = 0;

    list() : first(nullptr), last(nullptr){}

    
    // Проверка, пустой ли список
    bool isEmpty()
    {
        return first == nullptr;
    }    

    // Перегрузка оператора [] для доступа к элементам списка по индексу
    Node* operator[] (const int index)
    {
        if(isEmpty()) return nullptr;
        Node* p = first;

        // Цикл поиска
        for(int i = 0; i < index; i++)
        {
            p = p->next;

            if(!p) return nullptr;
        }

        return p;
    }

    // Перегрузка оператора == для сравнения двух списков
    bool operator== (list B)
    {
        if(length != B.length) return false;
        
        bool equal = true;
        Node* p = first;
        for(int i = 0; i < B.length; i++)
        {
            if(p->val != B[i]->val)
            {
                equal = false;
                break;
            }

            p = p->next;
        }

        return equal;
    }

    // Проверка на вхождение одного списка в другой
    bool contains(list B)
    {
        if(B.length > length) return false;

        // Цикл сравнения значений
        for(int i = 0; i < B.length; i++)
        {
            bool cont = false;
            Node* p = first;

            // Цикл поиска значения списка B в списке A
            while(p)
            {
                if(p->val == B[i]->val)
                {
                    cont = true;
                    break;
                }

                p = p->next;
            }

            if(!cont) return false;
        }

        return true;
    }

    // Проверка на повторяющиеся элементы
    bool hasDuplicates()
    {
        Node* p = first;

        // Цикл прохождения по массиву
        while(p)
        {   
            // Цикл подсчета количества одинаковых элементов
            Node* j = first;
            int count = 0;
            while(j)
            {
                if(p->val == j->val)
                {
                    count++;
                }

                if(count > 1) return true;
                j = j->next;
            }

            p = p->next;
        }

        return false;
    }

    // Добавление элементов в конец
    void pushBack(int _val)
    {
        Node* p = new Node(_val);

        if(isEmpty())
        {
            first = p;
            last = p;
            length++;
            return;
        }

        last->next = p;
        last = p;
        length++;
    }

    // Добавление элементов в начало
    void pushFront(int _val)
    {
        Node* p = new Node(_val);

        if(isEmpty())
        {
            first = p;
            last = p;
            length++;
            return;
        }

        Node* t = first;
        
        first = p;
        p->next = t;
        length++;
    }

    // Добавление элемента после указанного индекса
    void push(int index, int _val)
    {
        Node* p = new Node(_val);

        if(isEmpty())
        {
            first = p;
            last = p;
            length++;
            return;
        }

        // Цикл поиска
        Node* prev = first;
        for(int i = 0; i < index; i++)
        {
            prev = prev->next;

            if(!p) return;
        }

        p->next = prev->next;
        prev->next = p;
        length++;
    }

    // Перенос последнего элемента в первый
    void backToFront()
    {
        if(isEmpty()) return;

        Node* secondToLast = first;

        // Нахождение предпоследнего элемента
        while(secondToLast->next != last)
        {
            secondToLast = secondToLast->next;
        }

        last->next = first;
        first = last;
        secondToLast->next = nullptr;
    }

    // Печать всего списка
    void print()
    {
        if(isEmpty()) return;

        // Печать, пока p != nullptr
        Node* p = first;
        while(p)
        {
            std::cout << p->val << ' ';
            p = p->next;
        }

        std::cout << '\n';
    }

    // Список из всех элементов, кроме первого
    int pop()
    {
        if(isEmpty()) return 0;

        Node* p = first;
        first = p->next;
        
        int value = p->val;
        delete p;

        length--;
        return value;
    }
};


int main()
{
    // Создание и ввод связного списка длины N1
    list A;
    int N1;

    std::cout << "Введите размер списка 1:\n";
    std::cin >> N1;

    std::cout << "\nВведите список 1:\n";

    // Ввод списка
    for(int i = 0; i < N1; i++)
    {
        int n;
        std::cin >> n;

        A.pushBack(n);
    }
    std::cout << '\n';

    // Создание и ввод второго списка длины N2
    list B;
    int N2;

    std::cout << "Введите размер списка 2:\n";
    std::cin >> N2;

    std::cout << "\nВведите список 2:\n";

    // Ввод списка
    for(int i = 0; i < N2; i++)
    {
        int n;
        std::cin >> n;

        B.pushBack(n);
    }
    std::cout << "\n\n";

    
    // Сравнение списков
    std::cout << "Списки " << (A == B ? "" : "не ") << "равны\n\n";

    // Проверка на вхождение списка B в A
    std::cout << "Второй список " << (A.contains(B) ? "" : "не ") << "входит в первый\n\n";

    // Проверка персого списка на повторения
    std::cout << "В первом списке " << (A.hasDuplicates() ? "есть повторения" : "нет повторений") << "\n\n";

    // Перенос последнего элемента списка A в начало
    A.backToFront();
    std::cout << "Перенос последнего элемента первого списка в начало:\n";
    A.print();
    std::cout << "\n\n";
}