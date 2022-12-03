// Связные списки 1


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
    // Создание и ввод связного списка длины N
    list A;
    int N;

    std::cout << "Введите размер списка:\n";
    std::cin >> N;

    std::cout << "\nВведите список:\n";

    // Ввод списка
    for(int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;

        A.pushBack(n);
    }
    std::cout << "\n\n";

    // Добавление в начало
    std::cout << "Добавление в начало единицы\n";
    A.pushFront(1);
    A.print();

    // Длина списка
    std::cout << "\nДлина списка: " << A.length << '\n'; 

    // Убирание первого элемента
    std::cout << "\nУдаление первого элемента\n";
    std::cout << "Первый элемент: " << A.pop() << '\n';
    std::cout << "Список: ";
    A.print();

    // Вставка после элемента по индексу
    std::cout << "\nВставка нуля после четвертого элемента\n";
    A.push(3, 0);
    std::cout << "Список: " << '\n';
    A.print();
}