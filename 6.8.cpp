// Циклический сдвиг списка


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

    // перегрузка функции pushBack для добавления в конец одного списка другой
    void pushBack(list B)
    {
        for(int i = 0; i < B.length; i++)
        {
            Node* p = B[i];

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

    // Перенос первого элемента в последний
    void frontToBack()
    {
        if(isEmpty() || length == 1) return;

        Node* afterFirst = first->next;

        last->next = first;
        last = first;
        last->next = nullptr;
        first = afterFirst;
    }

    // Перенос последнего элемента в первый
    void backToFront()
    {
        if(isEmpty() || length == 1) return;

        Node* secondToLast = first;

        // Нахождение предпоследнего элемента
        while(secondToLast->next != last)
        {
            secondToLast = secondToLast->next;
        }

        last->next = first;
        first = last;
        last = secondToLast;
        secondToLast->next = nullptr;
    }

    // Переворачивание списка
    list reverse()
    {
        list B;

        if(isEmpty()) return B;

        Node* p = first;
        while(p)
        {
            B.pushFront(p->val);
            p = p->next;
        }

        return B;
    }

    void normalise()
    {
        if(isEmpty() || length == 1) return;

        // Цикл прохода по всем элементам списка
        for(Node* p = first; p; p = p->next)
        {
            // Цикл поиска дубликатов
            for(Node* j = p; j->next;)
            {
                if(j->next->val == p->val)
                {
                    Node* t = j->next->next;
                    delete j->next;
                    j->next = t;
                }
                else j = j->next;
            }
        }
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
    // Создание и ввод списка длины N1 и ввод количества сдвигов
    list A;
    int N1;
    int shift;

    std::cout << "Введите размер списка:\n";
    std::cin >> N1;

    std::cout << "\nВведите список:\n";

    // Ввод списка
    for(int i = 0; i < N1; i++)
    {
        int n;
        std::cin >> n;

        A.pushBack(n);
    }
    std::cout << '\n';

    
    std::cout << "\nВведите количество сдвигов:\n";
    std::cin >> shift;


    // Сдвиг списка
    while(shift)
    {
        A.backToFront();
        shift--;
    }

    std::cout << "\nСдвинутый список:\n";
    A.print();
}