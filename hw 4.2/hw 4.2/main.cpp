#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
class adress {
private:
    string town;
    string street;
    int house;
    int room;
public:
    adress(string town, string street, int house, int room)
    {
        this->town = town;
        this->street = street;
        this->house = house;
        this->room = room;
    }
    adress() {}
    string get_output_address()
    {
        return town + " " + street + " " + to_string(house) + " " + to_string(room) + "\n";
    }
};
void Sort(adress* adresses, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while (j >= 0 && adresses[j].get_output_address() > adresses[j + 1].get_output_address())
        {
            swap(adresses[j], adresses[j + 1]);
            j--;
        }
    }
}
int main() {
    setlocale(LC_ALL, "RUS");
    ifstream in("in.txt");
    ofstream fout;
    fout.open("out.txt");
    if (!in.is_open())
    {
        cout << "error";
        return 0;
    }
    string size_in;
    string town;
    string street;
    int house;
    int room;
    in >> size_in;
    int size = 0;
    size = stoi(size_in);
    adress* arr = new adress[size]{};
    fout << size << "\n";
    for (int i = 0; i < size; i++)
    {
        in >> town;
        in >> street;
        in >> house;
        in >> room;
        adress person(town, street, house, room);
        arr[i] = { person };
    }
    Sort(arr, size);
    for (int i = 0; i < size; i++) {
        fout << arr[i].get_output_address();
    }
    delete[] arr;
}