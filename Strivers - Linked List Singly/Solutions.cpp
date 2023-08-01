#include <iostream>

struct node
{
    int info;
    struct node *link;
};

struct node *first = nullptr, *last = nullptr;

void isf()
{
    int ele;
    struct node *p = new node;
    std::cout << "Enter the item to be inserted: ";
    std::cin >> ele;
    p->info = ele;
    p->link = nullptr;
    if (first == nullptr)
    {
        first = p;
        std::cout << first->info << " is inserted\n";
        return;
    }
    p->link = first;
    first = p;
    std::cout << first->info << " is inserted\n";
}

void ise()
{
    int ele;
    struct node *p = new node;
    std::cout << "Enter the value to be inserted: ";
    std::cin >> ele;
    p->info = ele;
    p->link = nullptr;
    if (first == nullptr)
    {
        first = p;
        std::cout << first->info << " is inserted\n";
        return;
    }

    struct node *temp = first;
    while (temp->link != nullptr)
    {
        temp = temp->link;
    }
    temp->link = p;
    std::cout << p->info << " is inserted\n";
}

void isp()
{
    int ele, pos;
    struct node *p = new node;
    std::cout << "Enter the value to be inserted: ";
    std::cin >> ele;
    std::cout << "Enter the position: ";
    std::cin >> pos;
    p->info = ele;
    p->link = nullptr;
    if (pos == 0)
    {
        p->link = first;
        first = p;
        std::cout << ele << " is inserted at " << pos << "\n";
        return;
    }
    struct node *temp = first;
    int i = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    p->link = temp->link;
    temp->link = p;
    std::cout << ele << " is inserted at " << pos << " pos\n";
}

void def()
{
    if (first == nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }
    struct node *p = first;
    std::cout << p->info << " is deleted\n";
    first = first->link;
    delete p;
}

void dee()
{
    struct node *temp, *p;
    if (first == nullptr)
    {
        std::cout << "\nlist is empty";
    }
    else if (first->link == nullptr)
    {
        std::cout << "Deleted element: " << first->info << "\n";
        delete first;
        first = nullptr;
        std::cout << "\nOnly node of the list deleted\n";
    }
    else
    {
        temp = first;
        while (temp->link != nullptr)
        {
            p = temp;
            temp = temp->link;
        }
        p->link = nullptr;
        std::cout << "Deleted element: " << temp->info << "\n";
        delete temp;
        std::cout << "\nDeleted Node from the last\n";
    }
}

void dep()
{
    int pos;
    struct node *p;
    std::cout << "Enter the position to be deleted: ";
    std::cin >> pos;
    if (pos == 0)
    {
        p = first;
        first = first->link;
        std::cout << p->info << " is deleted at " << pos << "\n";
        delete p;
        return;
    }
    struct node *temp = first;
    int i = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    p = temp->link;
    temp->link = p->link;
    std::cout << p->info << " is deleted at " << pos << "\n";
    delete p;
}

void display()
{
    struct node *temp = first;
    if (first == nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }
    while (temp != nullptr)
    {
        std::cout << temp->info << " ";
        temp = temp->link;
    }
    std::cout << "\n";
}

int main()
{
    int ch;
    std::cout << "SINGLY LINKED LIST \n";
    std::cout << "\n 1.Insert at the top\n 2.Insert at the end\n 3.Insert at a pos\n 4.Delete at the top\n 5.Delete at the end \n 6.Delete at a pos\n 7.Display\n 8.Exit\n";
    while (1)
    {
        std::cout << "Enter your choice: ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            isf();
            break;

        case 2:
            ise();
            break;

        case 3:
            isp();
            break;

        case 4:
            def();
            break;

        case 5:
            dee();
            break;

        case 6:
            dep();
            break;

        case 7:
            display();
            break;

        case 8:
            return 0;

        default:
            std::cout << "Invalid position\n";
        }
    }
}
