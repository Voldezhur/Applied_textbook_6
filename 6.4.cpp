// Сумма элементов связного списка


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

    list() : first(nullptr), last(nullptr){}

    
    // Проверка, пустой ли список
    bool isEmpty()
    {
        return first == nullptr;
    }    

    // Добавление элементов в конец
    void pushBack(int _val)
    {
        Node* p = new Node(_val);

        if(isEmpty())
        {
            first = p;
            last = p;
            return;
        }

        last->next = p;
        last = p;
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

    // Нахождение суммы элементов списка
    int sum()
    {
        if(isEmpty()) return 0;

        // Суммирование, пока p != nullptr
        Node* p = first;
        int s = 0;

        while(p)
        {
            s += p->val;
            p = p->next;
        }


        return s;
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

    std::cout << "\nСумма элементов списка: " << A.sum() << '\n';
}