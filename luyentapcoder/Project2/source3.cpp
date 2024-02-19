/*#include <iostream>
#include <string>

using namespace std;

const int MAX_OF_CHILDREN = 3;

struct Person
{
    Person(string name)
    {
        fullname = name;
        for (int i = 0; i < MAX_OF_CHILDREN; i++)
        {
            children[i] = NULL;
        }
    }

    string fullname;
    Person* children[MAX_OF_CHILDREN];
};

void print_children(Person* person)
{
    int count = 0;
    for (int i = 0; i < MAX_OF_CHILDREN; i++) {
        if (person->children[i] == NULL)
            break;
        else {
            count++;
        }
    }
    if (count == 1) cout << person->fullname << " co con la : " << person->children[0]->fullname << "\n";
    if (count == 2) cout << person->fullname << " co con la : "
        << person->children[0]->fullname << ", " << person->children[1]->fullname << "\n";
    if (count == 0) cout << person->fullname << " khong co con\n ";
}

bool check_shared_children(Person* person_1, Person* person_2)
{
    bool check = false;
    for (int i = 0; i < MAX_OF_CHILDREN; i++) {
        if (person_1->children[i] != person_2->children[i]) {
            break;
        }
        else check = true;
    }
    return check;
}

void print_grandchildren(Person* person)
{
    Person* test = person;
    person = person->children[0];
    int count = 0;

    if (person != NULL) {
        for (int i = 0; i < 2; i++) {
            if (person->children[i] == NULL) count++;
        }
        if (count == 2) cout << test->fullname << " chua co chau.\n";
        else {
            cout << test->fullname << " co chau la : ";
            for (int i = 0; i < 3; i++) {
                if (person->children[i] != NULL) 
                    cout << person->children[i]->fullname << ", ";              
            }
            cout << "\n";
        }
    }
    else cout << test->fullname << " chua co chau.\n";
}

int main()
{
    Person* vu = new Person("Anh Vu");
    Person* yen = new Person("Thi Yen");
    Person* mtp = new Person("Son Tung MTP");
    Person* bao_tram = new Person("Thieu Bao Tram");
    Person* ngoc_trinh = new Person("Ngoc Trinh");
    Person* khac_tiep = new Person("Khac Tiep");
    Person* ozawa = new Person("Ozawa");
    Person* tokuda = new Person("Tokuda");

    {
        vu->children[0] = mtp;
        yen->children[0] = mtp;

        ngoc_trinh->children[0] = bao_tram;
        khac_tiep->children[0] = bao_tram;

        //chau
        mtp->children[0] = tokuda;
        mtp->children[1] = ozawa;
        bao_tram->children[0] = tokuda;
        bao_tram->children[1] = ozawa;

    }

    {
        cout << "Test 1 - In ten con: \n";
        cout << "\t"; print_children(vu);
        cout << "\t"; print_children(mtp);
        cout << "\t"; print_children(ozawa);
    }

    {
        cout << "Test 2 - Kiem tra con chung: \n";
        cout << "\tTest 2.1: " << (check_shared_children(vu, yen) == true ? "Pass" : "Failed") << "\n";
        cout << "\tTest 2.2: " << (check_shared_children(vu, ngoc_trinh) == false ? "Pass" : "Failed") << "\n";
        cout << "\tTest 2.3: " << (check_shared_children(mtp, bao_tram) == true ? "Pass" : "Failed") << "\n";
    }
    {
        cout << "Test 3 - In ten chau: \n";
        cout << "\t"; print_grandchildren(vu);
        cout << "\t"; print_grandchildren(ngoc_trinh);
        cout << "\t"; print_grandchildren(bao_tram);
        cout << "\t"; print_grandchildren(ozawa);
    }
}*/