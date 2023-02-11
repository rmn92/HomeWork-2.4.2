#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

class Addresses
{
private:
    string cityName;
    string streetName;
    int houseNum;
    int apartmentNum;
public:
    Addresses() {}

    Addresses(string cityName, string streetName, int houseNum, int apartmentNum)
    {
        this->cityName = cityName;
        this->streetName = streetName;
        this->houseNum = houseNum;
        this->apartmentNum = apartmentNum;
    }

    string getOutputAddress()
    {
        string result;
        result = cityName + ", " + streetName + ", " + to_string(houseNum) + ", " + to_string(apartmentNum);
        return result;
    }

    string getCityName()
    {
        return cityName;
    }
};

void sort(Addresses* addresses, int size);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int size = 0;

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> size;
            Addresses* arr = new Addresses[size];

            string cityName;
            string streetName;
            int houseNum;
            int apartmentNum;

            for (int i = 0; i < size; i++)
            {
                fin >> cityName;
                fin >> streetName;
                fin >> houseNum;
                fin >> apartmentNum;

                arr[i] = Addresses(cityName, streetName, houseNum, apartmentNum);
            }

            sort(arr, size);
            
            cout << size << endl;
            fout << size << endl;
            for (int i = 0; i < size; i++)
            {
                cout << arr[i].getOutputAddress() << endl;
                fout << arr[i].getOutputAddress() << endl;
            }
            delete[] arr;
        }
        fin.close();
    }
    else
    {
        cout << "Не удалось открыть файл";
    }
}

void sort(Addresses* arr, int size)
{
    bool swapped = false;
    do
    {
        swapped = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i].getCityName()[0] > arr[i + 1].getCityName()[0])
            {
                Addresses temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}