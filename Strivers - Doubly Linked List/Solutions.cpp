#include <iostream>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *first = nullptr;

void isf()
{
    int ele;
    struct node *p = new node;
    std::cout << "Enter the value to be inserted: ";
    std::cin >> ele;
    p->data = ele;
    p->next = nullptr;
    p->prev = nullptr;
    if (first == nullptr)
    {
        first = p;
        std::cout << first->data << " is inserted\n";
        return;
    }
    p->next = first;
    first->prev = p;
    first = p;
    std::cout << first->data << " is inserted\n";
}

void ise()
{
    int ele;
    struct node *p = new node;
    std::cout << "Enter the value to be inserted: ";
    std::cin >> ele;
    p->data = ele;
    p->next = nullptr;
    p->prev = nullptr;
    if (first == nullptr)
    {
        first = p;
        std::cout << first->data << " is inserted\n";
        return;
    }
    struct node *temp = first;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;
    std::cout << p->data << " is inserted\n";
}

void isp()
{
    int ele, pos;
    struct node *p = new node;
    std::cout << "Enter the value to be inserted: ";
    std::cin >> ele;
    std::cout << "Enter the position: ";
    std::cin >> pos;
    p->data = ele;
    p->next = nullptr;
    p->prev = nullptr;
    if (pos == 0)
    {
        p->next = first;
        first->prev = p;
        first = p;
        std::cout << ele << " is inserted at " << pos << "\n";
        return;
    }
    struct node *temp = first;
    int i = 0;
    while (i < pos - 1)
    {
        temp = temp->next;
        if (temp == nullptr)
        {
            std::cout << "Insert is not possible\n";
            return;
        }
        i++;
    }
    p->next = temp->next;
    temp->next->prev = p;
    temp->next = p;
    p->prev = temp;
    std::cout << ele << " is inserted at " << pos << " pos\n";
}

void def()
{
    if (first == nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }
    if (first->next == nullptr)
    {
        std::cout << first->data << " is deleted\n";
        delete first;
        first = nullptr;
        return;
    }
    struct node *p = first;
    std::cout << p->data << " is deleted\n";
    first = first->next;
    first->prev = nullptr;
    delete p;
}

void dee()
{
    struct node *p, *temp = first, *ptr;
    if (first == nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }
    while (temp->next != nullptr)
    {
        ptr = temp;
        temp = temp->next;
    }
    std::cout << temp->data << " is deleted\n";
    ptr->next = nullptr;
    delete temp;
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
        first = first->next;
        first->prev = nullptr;
        std::cout << p->data << " is deleted at " << pos << "\n";
        delete p;
        return;
    }
    struct node *temp = first;
    int i = 0;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    p = temp->next;
    temp->next = p->next;
    if (p->next == nullptr)
    {
        std::cout << p->data << " is deleted at " << pos << "\n";
        delete p;
        return;
    }
    p->next->prev = temp;
    std::cout << p->data << " is deleted at " << pos << "\n";
    delete p;
}

void displayF()
{
    struct node *temp = first;
    if (first == nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

void displayB()
{
    struct node *temp = first;
    if (first == nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << "\n";
}

int search()
{
    int ele;
    if (first == nullptr)
    {
        std::cout << "List is empty\n";
        return -2;
    }
    std::cout << "Enter the element to be searched\n";
    std::cin >> ele;
    struct node *temp = first;
    int count = 0;
    while (temp != nullptr)
    {
        if (temp->data == ele)
            return count;
        temp = temp->next;
        count = count + 1;
    }
    return -1;
}

void del_aft_pos()
{
    struct node *ptr, *temp;
    int val;
    std::cout << "Enter the value after which you want to delete: ";
    std::cin >> val;
    temp = first;
    while (temp->data != val)
        temp = temp->next;
    if (temp->next == nullptr)
    {
        std::cout << "\nCan't delete\n";
    }
    else if (temp->next->next == nullptr)
    {
        ptr = temp->next;
        temp->next = nullptr;
        std::cout << ptr->data << " is deleted\n";
        delete ptr;
    }
    else
    {
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        std::cout << ptr->data << " is deleted\n";
        delete ptr;
        std::cout << "\nNode Deleted\n";
    }
}

void del_bef_pos()
{
    struct node *ptr, *temp, *p2;
    int val;
    std::cout << "Enter the value before which you want to delete: ";
    std::cin >> val;
    temp = first;
    while (temp->data != val)
        temp = temp->next;
    if (temp->next == nullptr)
    {
        // FOR 2 NODES
        p2 = first;
        first = first->next;
        first->prev = nullptr;
        std::cout << p2->data << " is deleted\n";
        delete p2;
    }
    else
    {
        p2 = temp->prev;
        p2->prev->next = temp;
        temp->prev = p2->prev;
        std::cout << p2->data << " is deleted\n";
        delete p2;
        std::cout << "\nNode Deleted\n";
    }
}

int Srch_del_PandN()
{
    struct node *temp = first, *ptr, *p2;
    int ele, val;
    if (first == nullptr)
    {
        std::cout << "\nList is empty\n";
        return -2;
    }
    std::cout << "\nEnter the element to be searched\n";
    std::cin >> ele;
    int count = 0;
    if (temp != nullptr && temp->data == ele)
    {
        count++;
        temp = temp->next;
        std::cout << "\nElement found at " << count << "\n";
    }
    if (temp == nullptr && temp->data != ele)
    {
        std::cout << "\nElement not found\n";
    }
    while (temp->data != ele)
        temp = temp->next;
    if (temp->next == nullptr)
    {
        std::cout << "\nCan't Delete\n";
    }
    else if (temp->next->next == nullptr || temp->prev->prev == nullptr)
    {
        ptr = temp->next;
        temp->next = nullptr;
        std::cout << "Next node " << ptr->data << " deleted\n";
        delete ptr;
        p2 = temp->prev;
        temp->prev = nullptr;
        std::cout << "Previous node " << p2->data << " deleted\n";
        delete p2;
        first = temp;
    }
    else
    {
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        std::cout << "\nNext node " << ptr->data << " is deleted\n";
        p2 = temp->prev;
        p2->prev->next = temp;
        temp->prev = p2->prev;
        std::cout << "\nPrevious node " << p2->data << " is deleted\n";
        delete p2;
        delete ptr;
    }
}

int main()
{
    int ch, res;
    std::cout << "1.Insert at the top\n 2.Insert at the end\n 3.Insert at a pos\n 4.Delete at the top\n 5.Delete at the end\n6. Delete at a pos\n7.DisplayF\n 8.DisplayB\n9.search\n 10. Del after given pos\n 11. Del before value \n 12. Search ele, del prev & next ele \n 13.Exit\n";

    // DELETE AFTER A GIVEN POS, DELETE BEFORE A GIVEN POSITION

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
            displayF();
            break;
        case 8:
            displayB();
            break;
        case 9:
            res = search();
            if (res > 0)
                std::cout << "Element found at " << res << "\n";
            else if (res == -1)
                std::cout << "Element not found\n";
            break;
        case 10:
            del_aft_pos();
            break;
        case 11:
            del_bef_pos();
            break;
        case 12:
            Srch_del_PandN();
            break;
        case 13:
            exit(0);
        default:
            std::cout << "Invalid position";
        }
    }

    return 0;
}
