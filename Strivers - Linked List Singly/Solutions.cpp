// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// struct node
// {
//     int info;
//     struct node *next;
// };

// struct node *first = nullptr, *last = nullptr;

// void isf()
// {
//     int ele;
//     struct node *p = new node;
//     std::cout << "Enter the item to be inserted: ";
//     std::cin >> ele;
//     p->info = ele;
//     p->next = nullptr;
//     if (first == nullptr)
//     {
//         first = p;
//         std::cout << first->info << " is inserted\n";
//         return;
//     }
//     p->next = first;
//     first = p;
//     std::cout << first->info << " is inserted\n";
// }

// void ise()
// {
//     int ele;
//     struct node *p = new node;
//     std::cout << "Enter the value to be inserted: ";
//     std::cin >> ele;
//     p->info = ele;
//     p->next = nullptr;
//     if (first == nullptr)
//     {
//         first = p;
//         std::cout << first->info << " is inserted\n";
//         return;
//     }

//     struct node *temp = first;
//     while (temp->next != nullptr)
//     {
//         temp = temp->next;
//     }
//     temp->next = p;
//     std::cout << p->info << " is inserted\n";
// }

// void isp()
// {
//     int ele, pos;
//     struct node *p = new node;
//     std::cout << "Enter the value to be inserted: ";
//     std::cin >> ele;
//     std::cout << "Enter the position: ";
//     std::cin >> pos;
//     p->info = ele;
//     p->next = nullptr;
//     if (pos == 0)
//     {
//         p->next = first;
//         first = p;
//         std::cout << ele << " is inserted at " << pos << "\n";
//         return;
//     }
//     struct node *temp = first;
//     int i = 0;
//     while (i < pos - 1)
//     {
//         temp = temp->next;
//         i++;
//     }
//     p->next = temp->next;   //  1 2 3 5 6
//     temp->next = p;
//     std::cout << ele << " is inserted at " << pos << " pos\n";
// }

// void def()
// {
//     if (first == nullptr)
//     {
//         std::cout << "List is empty\n";
//         return;
//     }
//     struct node *p = first;
//     std::cout << p->info << " is deleted\n";
//     first = first->next;
//     delete p;
// }

// void dee()
// {
//     struct node *temp, *p;
//     if (first == nullptr)
//     {
//         std::cout << "\nlist is empty";
//     }
//     else if (first->next == nullptr)
//     {
//         std::cout << "Deleted element: " << first->info << "\n";
//         delete first;
//         first = nullptr;
//         std::cout << "\nOnly node of the list deleted\n";
//     }
//     else
//     {
//         temp = first;
//         while (temp->next != nullptr)
//         {
//             p = temp;
//             temp = temp->next;
//         }
//         p->next = nullptr;
//         std::cout << "Deleted element: " << temp->info << "\n";
//         delete temp;
//         std::cout << "\nDeleted Node from the last\n";
//     }
// }

// void dep()
// {
//     int pos;
//     struct node *p;
//     std::cout << "Enter the position to be deleted: ";
//     std::cin >> pos;
//     if (pos == 0)
//     {
//         p = first;
//         first = first->next;
//         std::cout << p->info << " is deleted at " << pos << "\n";
//         delete p;
//         return;
//     }
//     struct node *temp = first;
//     int i = 0;
//     while (i < pos - 1)
//     {
//         temp = temp->next;
//         i++;
//     }
//     p = temp->next;
//     temp->next = p->next;
//     std::cout << p->info << " is deleted at " << pos << "\n";
//     delete p;
// }
// /*  STRIVERS
// The slow_ptr moves one step at a time, while the fast_ptr moves two steps at a time. When the fast_ptr reaches the end of the list, 
// the slow_ptr will be at the middle element (or the first middle element in case of an even number of elements).

// The first while loop continues until the fast_ptr reaches the end of the list or goes beyond it (i.e becomes nullptr).
// The second while loop is used to display the middle element(s) found by the first loop. 
// It continues until the slow_ptr reaches the end of the list (i.e becomes nullptr).

// The slow_ptr starts from the middle element and traverses the list until it reaches the end

// OUTPUT: (for input-> 1,2,3,4,5 & 1,2,3,4,5,6) ->    3,4,5   &   4,5,6 ie take 2nd mid ele if 2 mid ele are present
// */
// void findMiddle()
// {
//     struct node *slow_ptr = first;
//     struct node *fast_ptr = first;
//     if (first != nullptr)
//     {
//         while (fast_ptr != nullptr && fast_ptr->next != nullptr)
//         {
//             fast_ptr = fast_ptr->next->next;
//             slow_ptr = slow_ptr->next;
//         }
//         std::cout << "Middle elements: ";
//         while (slow_ptr != nullptr)
//         {
//             std::cout << slow_ptr->info << " ";
//             slow_ptr = slow_ptr->next;
//         }
//         std::cout << "\n";
//     }
// }

// void reverseLinkedList()
// {
//     if (first == nullptr || first->next == nullptr)
//         return;

//     struct node *prev = nullptr;
//     struct node *current = first;
//     struct node *next = nullptr;

//     while (current != nullptr)
//     {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     first = prev;
// }

// void display()
// {
//     struct node *temp = first;
//     if (first == nullptr)
//     {
//         std::cout << "List is empty\n";
//         return;
//     }
//     while (temp != nullptr)
//     {
//         std::cout << temp->info << " ";
//         temp = temp->next;
//     }
//     std::cout << "\n";
// }

// int main()
// {
//     int ch;
//     std::cout << "SINGLY LINKED LIST \n";
//     std::cout << "\n 1.Insert at the top\n 2.Insert at the end\n 3.Insert at a pos\n 4.Delete at the top\n 5.Delete at the end \n 6.Delete at a pos\n 7.Display\n 8.Find Middle \n9.Reverse the list \n10.Exit\n";
//     while (1)
//     {
//         std::cout << "Enter your choice: ";
//         std::cin >> ch;
//         switch (ch)
//         {
//         case 1:
//             isf();
//             break;

//         case 2:
//             ise();
//             break;

//         case 3:
//             isp();
//             break;

//         case 4:
//             def();
//             break;

//         case 5:
//             dee();
//             break;

//         case 6:
//             dep();
//             break;

//         case 7:
//             display();
//             break;
        
//         case 8:
//             findMiddle();
//             break;

//         case 9:
//             reverseLinkedList();
//             std::cout << "List reversed\n";
//             break;

//         case 10:
//             return 0;

//         default:
//             std::cout << "Invalid position\n";
//         }
//     }
// }
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *first = nullptr, *last = nullptr;
struct node *firstOdd = nullptr, *lastOdd = nullptr;
struct node *firstEven = nullptr, *lastEven = nullptr;

void isf()
{
    int ele;
    struct node *p = new node;
    std::cout << "Enter the item to be inserted: ";
    std::cin >> ele;
    p->info = ele;
    p->next = nullptr;
    if (first == nullptr)
    {
        first = p;
        std::cout << first->info << " is inserted\n";
        return;
    }
    p->next = first;
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
    p->next = nullptr;
    if (first == nullptr)
    {
        first = p;
        std::cout << first->info << " is inserted\n";
        return;
    }

    struct node *temp = first;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = p;
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
    p->next = nullptr;
    if (pos == 0)
    {
        p->next = first;
        first = p;
        std::cout << ele << " is inserted at " << pos << "\n";
        return;
    }
    struct node *temp = first;
    int i = 0;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    p->next = temp->next;   //  1 2 3 5 6
    temp->next = p;
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
    first = first->next;
    delete p;
}

void dee()
{
    struct node *temp, *p;
    if (first == nullptr)
    {
        std::cout << "\nlist is empty";
    }
    else if (first->next == nullptr)
    {
        std::cout << "Deleted element: " << first->info << "\n";
        delete first;
        first = nullptr;
        std::cout << "\nOnly node of the list deleted\n";
    }
    else
    {
        temp = first;
        while (temp->next != nullptr)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = nullptr;
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
        first = first->next;
        std::cout << p->info << " is deleted at " << pos << "\n";
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
    std::cout << p->info << " is deleted at " << pos << "\n";
    delete p;
}

void findMiddle()
{
    struct node *slow_ptr = first;
    struct node *fast_ptr = first;
    if (first != nullptr)
    {
        while (fast_ptr != nullptr && fast_ptr->next != nullptr)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        std::cout << "Middle elements: ";
        while (slow_ptr != nullptr)
        {
            std::cout << slow_ptr->info << " ";
            slow_ptr = slow_ptr->next;
        }
        std::cout << "\n";
    }
}

void reverseLinkedList()
{
    if (first == nullptr || first->next == nullptr)
        return;

    struct node *prev = nullptr;
    struct node *current = first;
    struct node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}

void segregateOddEven()
{
    struct node* current = first;
    while (current != nullptr) {
        if (current->info % 2 == 0) { // even element
            if (firstEven == nullptr) {
                firstEven = current;
                lastEven = current;
            } else {
                lastEven->next = current;
                lastEven = current;
            }
        } else { // odd element
            if (firstOdd == nullptr) {
                firstOdd = current;
                lastOdd = current;
            } else {
                lastOdd->next = current;
                lastOdd = current;
            }
        }
        current = current->next;
    }
    // Terminate the new lists
    if (lastEven != nullptr) lastEven->next = nullptr;
    if (lastOdd != nullptr) lastOdd->next = nullptr;
}

void bubbleSort() {
    if (first == nullptr)
        return;

    bool swapped;
    struct node* temp;
    struct node* end = nullptr;

    do {
        swapped = false;
        temp = first;

        while (temp->next != end) {
            if (temp->info > temp->next->info) {
                int tempData = temp->info;
                temp->info = temp->next->info;
                temp->next->info = tempData;
                swapped = true;
            }
            temp = temp->next;
        }
        end = temp; // Mark the last sorted element
    } while (swapped);
}


void display(struct node* start)
{
    struct node *temp = start;
    if (temp == nullptr)
    {
        std::cout << "List is empty\n";
        return;
    }
    while (temp != nullptr)
    {
        std::cout << temp->info << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

// int main()
// {
//     int ch;
//     std::cout << "SINGLY LINKED LIST \n";
//     std::cout << "\n 1.Insert at the top\n 2.Insert at the end\n 3.Insert at a pos\n 4.Delete at the top\n 5.Delete at the end \n 6.Delete at a pos\n 7.Display\n 8.Find Middle \n9.Reverse the list \n10.Segregate Odd and Even \n11.Exit\n";
//     while (1)
//     {
//         std::cout << "Enter your choice: ";
//         std::cin >> ch;
//         switch (ch)
//         {
//         case 1:
//             isf();
//             break;

//         case 2:
//             ise();
//             break;

//         case 3:
//             isp();
//             break;

//         case 4:
//             def();
//             break;

//         case 5:
//             dee();
//             break;

//         case 6:
//             dep();
//             break;

//         case 7:
//             display(first);
//             break;
        
//         case 8:
//             findMiddle();
//             break;

//         case 9:
//             reverseLinkedList();
//             std::cout << "List reversed\n";
//             break;

//         case 10:
//             segregateOddEven();
//             std::cout << "List segregated into Odd and Even elements\n";
//             std::cout << "Odd elements: ";
//             display(firstOdd);
//             std::cout << "Even elements: ";
//             display(firstEven);
//             break;

//         case 11:
//             return 0;

//         default:
//             std::cout << "Invalid position\n";
//         }
//     }
// }
int main() {
    int ch;
    std::cout << "SINGLY LINKED LIST \n";
    std::cout << "\n 1.Insert at the top\n 2.Insert at the end\n 3.Insert at a pos\n 4.Delete at the top\n 5.Delete at the end \n 6.Delete at a pos\n 7.Display\n 8.Find Middle \n9.Reverse the list \n10.Segregate Odd and Even\n11.Sort the list\n12.Exit\n";

    while (1) {
        std::cout << "Enter your choice: ";
        std::cin >> ch;
        switch (ch) {
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
                display(first);
                break;

            case 8:
                findMiddle();
                break;

            case 9:
                reverseLinkedList();
                std::cout << "List reversed\n";
                break;

            case 10:
                segregateOddEven();
                std::cout << "List segregated into Odd and Even elements\n";
                std::cout << "Odd elements: ";
                display(firstOdd);
                std::cout << "Even elements: ";
                display(firstEven);
                break;

            case 11:
                bubbleSort();
                std::cout << "List sorted in ascending order\n";
                break;

            case 12:
                return 0;

            default:
                std::cout << "Invalid position\n";
        }
    }
}
