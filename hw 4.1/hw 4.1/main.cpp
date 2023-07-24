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
    for (int i = 0; i < size; i++) {
        fout << arr[size - 1 - i].get_output_address();
    }
    delete[] arr;
}