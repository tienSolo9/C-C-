/*******************************************************************************
************ Bài tập lập trình C++ cơ bản - Bài 10.3 ****************************
********************** vunguyencoder.com **************************************
1. In ra tên người ko thích một ai.
2. In ra người đang yêu đơn phương.
Người đơn phương là người đi thích người khác mà ko có chiều ngược lại
3. In ra tên của các cặp đôi khác giới yêu nhau
Hai người yêu nhau là 2 người đều thích đối phương.
4. In ra tên người đa tình - là người được 2 người thích trở lên
* ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person(string ht, int gt)
    {
        ho_ten = ht;
        gioi_tinh = gt;
        crush = NULL;
    }

    string ho_ten;
    int gioi_tinh; // 1: Nam / -1: Nu
    Person* crush;
};

int main()
{
    const int MAX = 9;

    // Tạo mảng thông tin 
    Person* list[MAX];
    list[0] = new Person("Nguyen Anh Vu", 1);
    list[1] = new Person("Truong Anh Tuan", 1);
    list[2] = new Person("Pham Dinh Hung", 1);
    list[3] = new Person("Bach Van Thang", -1);
    list[4] = new Person("Tran Mai Anh", -1);
    list[5] = new Person("Eimi Fukada", -1);
    list[6] = new Person("Khac Tiep", 1);
    list[7] = new Person("Ngoc Trinh", -1);
    list[8] = new Person("Midu", -1);

    // Tạo mối quan hệ tình cảm 
    list[0]->crush = list[5];
    list[1]->crush = list[5];
    list[2]->crush = list[4];
    list[3]->crush = list[7];
    list[4]->crush = list[2];
    list[5]->crush = NULL;
    list[6]->crush = list[7];
    list[7]->crush = NULL;
    list[8]->crush = NULL;

    {
        cout << "Ket qua 1:";
        for (int i = 0; i < 9; i++) {
            if (list[i]->crush == NULL) cout << list[i]->ho_ten << ", ";
        }
    }

    {
        cout << "\nKet qua 2:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (list[i]->crush == list[j] && list[j]->crush != list[i])
                    cout << "\t(" << list[i]->ho_ten << " --> " << list[j]->ho_ten << ")\n";
            }
        }
    }

    {
        cout << "Ket qua 3:\n\t";
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (list[i]->crush == list[j] && list[j]->crush == list[i]
                    && list[i]->gioi_tinh != list[j]->gioi_tinh)
                    cout << "(" << list[i]->ho_ten << " <--> " << list[j]->ho_ten << ")\n";
            }
        }
    }

    {
        cout << "Ket qua 4: ";
        for (int i = 0; i < 9; i++) {
            int count = 0;
            for (int j = 0; j < 9; j++) {
                if (list[i] == (list[j]->crush)) count++;
            }
            if (count >= 2) cout << list[i]->ho_ten << ", ";
        }
    }

}




