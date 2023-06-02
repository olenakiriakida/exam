#include <iostream>
using namespace std;

struct Product
{
    char manufacturer[20];
    char name[20];
    char price[20];
    char expiration[20];
    char date[20];
    char group[20];
};

Product* add(Product*& inf, int size, int new_size);
void edit(Product& inf, int size, int ch1);
Product* DeleteProduct(Product*& inf, int size, int newsize, int choise);
void show(Product inf);
void searchname(Product* inf, char nasearch[]);
void searchmanufacturer(Product* inf, char manusearch[]);
void searchprice(Product* inf, char prsearch[]);
void searchgroup(Product* inf, char grsearch[]);
void searchdate(Product* inf, char dasearch[]);
void searchexpiration(Product* inf, char exsearch[]);
void sortgroup(Product* inf, int const size);
void sortprice(Product* inf, int const size);
Product info();

int main()
{
    setlocale(LC_ALL, "");
    int choice, ch2, ch4, amount, ch3;
    char ch[20], na[20];
    cout << "\t\t Склад " << endl << endl;
    do {
        cout << endl;
        cout << "Сколько товаров вы хотите добавить? ";
        cin >> amount;
        int const size = amount;
        Product* inf = new Product[size];
        for (int i = 0; i < size; i++)
        {
            inf[i] = info();
            cout << endl;
        }

        cout << "Выберите ваше действие: " << endl;
        cout << "1 - Добавить товар" << endl;
        cout << "2 - Заменить товар" << endl;
        cout << "3 - Удалить товар" << endl;
        cout << "4 - Поиск товара" << endl;
        cout << "5 - Сортировать за группой товара" << endl;
        cout << "6 - Сортировать по цене" << endl;
        cout << "7 - Вывести все товары" << endl;
        cout << "8 - Выход" << endl;
        cin >> choice;


        if (choice == 1) {
            int new_size = size + 1;
            Product* NewInfo = add(inf, size, new_size);
            NewInfo[new_size] = info();
        }
        if (choice == 2) {
            cout << "Выберите товар, который хотите заменить: ";
            cin >> ch2;
            edit(inf[ch2], size, ch2);
        }

        if (choice == 3) {
            int size2 = size - 1;
            cout << "Введите товар, который хотите удалить: ";
            cin >> ch3;
            Product* NewDelInfo = DeleteProduct(inf, size, size2, ch3);
        }

        if (choice == 4) {
            cout << "Выберите категорию поиска: " << endl;
            cout << "1 - Искать по названию " << endl;
            cout << "2 - Искать по производителю " << endl;
            cout << "3 - Искать по цене " << endl;
            cout << "4 - Искать по группе товара " << endl;
            cout << "5 - Искать по дате поступления на склад " << endl;
            cout << "6 - Искать по сроку годности " << endl;
            cin >> ch4;
            if (ch4 == 1)
            {
                cout << "Введите название: ";
                cin >> ch;
                searchname(inf, ch);
            }
            if (ch4 == 2)
            {
                cout << "Введите производителя: ";
                cin >> ch;
                searchmanufacturer(inf, ch);
            }
            if (ch4 == 3)
            {
                cout << "Введите цену: ";
                cin >> ch;
                searchprice(inf, ch);
            }
            if (ch4 == 4)
            {
                cout << "Введите группу: ";
                cin >> ch;
                searchgroup(inf, ch);
            }
            if (ch4 == 5)
            {
                cout << "Введите дату поступления на склад: ";
                cin >> ch;
                searchdate(inf, ch);
            }
            if (ch4 == 6)
            {
                cout << "Введите срок годности: ";
                cin >> ch;
                searchexpiration(inf, ch);
            }
        }

        if (choice == 5) {
            sortgroup(inf, size);
        }

        if (choice == 6) {
            sortprice(inf, size);
        }

        if (choice == 7) {
            for (int i = 0; i < size; i++)
            {
                show(inf[i]);
            }
        }
        if (choice == 8) {
            return 0;
        }
    } while (choice != 8);
    delete[] 'inf';
} 

Product* add(Product*& inf, int size, int new_size)
{
    Product* new_inf = new Product[new_size];
    for (int i = 0; i < size; i++)
    {
        new_inf[i] = inf[i];
    }
    return new_inf;
}

void edit(Product& inf, int size, int ch1)
{
    for (int i = 0; i < size; i++)
    {
        if (i + 1 == ch1)
        {
            cout << "Введите название товара: ";
            cin >> inf.name;
            cout << "Укажите производителя: ";
            cin >> inf.manufacturer;
            cout << "Укажите цену: ";
            cin >> inf.price;
            cout << "Срок годности: ";
            cin >> inf.expiration;
            cout << "Дата поступления на склад: ";
            cin >> inf.date;
            cout << "Введите группу товара: ";
            cin >> inf.group;
        }
    }
}

Product* DeleteProduct(Product*& inf, int size, int newsize, int choise)
{
    Product* new_dl_inf = new Product[size];
    for (int i = 0; i < newsize; i++)
    {
        if (i < choise)
        {
            new_dl_inf[i] = inf[i];
        }
        if (i == choise)
        {
            new_dl_inf[choise] = inf[choise + 1];
        }
        if (i > choise)
        {
            new_dl_inf[i] = inf[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        show(inf[i]);
    }
    return new_dl_inf;
}

void show(Product inf)
{
    cout << "Имя продукта: " << inf.name << endl;
    cout << "Производитель: " << inf.manufacturer << endl;
    cout << "Цена: " << inf.price << endl;
    cout << "Срок годности: " << inf.expiration << endl;
    cout << "Дата поступления на склад: " << inf.date << endl;
    cout << "Группа товара: " << inf.group << endl;
    cout << endl;
}

void searchname(Product* inf, char nasearch[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(inf[i].name, nasearch) == 0)
        {
            show(inf[i]);
            return;
        }
    }
    cout << "Такого названия нет" << endl;
}

void searchmanufacturer(Product* inf, char manusearch[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(inf[i].manufacturer, manusearch) == 0)
        {
            show(inf[i]);
            return;
        }
    }
    cout << "Такого производителя нет" << endl;
}

void searchprice(Product* inf, char prsearch[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(inf[i].price, prsearch) == 0)
        {
            show(inf[i]);
            return;
        }
    }
    cout << "Такой цены нет" << endl;
}

void searchgroup(Product* inf, char grsearch[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(inf[i].group, grsearch) == 0)
        {
            show(inf[i]);
            return;
        }
    }
    cout << "Такой группы нет" << endl;
}

void searchdate(Product* inf, char dasearch[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(inf[i].date, dasearch) == 0)
        {
            show(inf[i]);
            return;
        }
    }
    cout << "На эту дату товара нет" << endl;
}

void searchexpiration(Product* inf, char exsearch[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(inf[i].expiration, exsearch) == 0)
        {
            show(inf[i]);
            return;
        }
    }
    cout << "Нет товара с таким сроком годности" << endl;
}

void sortgroup(Product* inf, int const size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (strcmp(inf[j].group, inf[j - 1].group) == -1)
            {
                swap(inf[j], inf[j - 1]);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        show(inf[i]);
    }
}

void sortprice(Product* inf, int const size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (strcmp(inf[j].price, inf[j - 1].price) == -1)
            {
                swap(inf[j], inf[j - 1]);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        show(inf[i]);
    }
}

Product info()
{
    Product inf;
    cout << "Введите название товара: ";
    cin >> inf.name;
    cout << "Укажите производителя: ";
    cin >> inf.manufacturer;
    cout << "Укажите цену: ";
    cin >> inf.price;
    cout << "Срок годности: ";
    cin >> inf.expiration;
    cout << "Дата поступления на склад: ";
    cin >> inf.date;
    cout << "Введите группу товара: ";
    cin >> inf.group;
    return inf;
}