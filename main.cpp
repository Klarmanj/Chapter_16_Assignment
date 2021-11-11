#include <iostream>
#include <vector>

using namespace std;

class OUT_OF_RANGE{
public:
    OUT_OF_RANGE() : message("Index is out of range of array length"){};
    OUT_OF_RANGE(string& str) : message(str){};
    string what(){
        return message;
    }

private:
    string message;
};

void selectionSort(vector<string> &list, int length){
    int index, smallestIndex, location;
    string temp;
    string tempLocationString;
    string tempSmallIndex;

    for(index = 0; index < length - 1; index++){
        smallestIndex = index;

        for(location = index + 1; location < length; location++) {
            if (list[location] < list[smallestIndex])
                smallestIndex = location;
        }
        temp = list[smallestIndex];
        list[smallestIndex] = list[index];
        list[index] = temp;
    }
}


void removeAt(vector<int> &list, int listLength, int index) {
    try {
        if (index - 1 >= listLength) {
            throw OUT_OF_RANGE();
        }
    }
    catch (OUT_OF_RANGE &OutOfRangeObj) {
        cout << OutOfRangeObj.what();
    }


    list.erase(list.begin() + index - 1);
    listLength--;

}


void insertionSort(vector<int> &list, int listLength)  {
    int firstOutOfOrder, location;
    int temp;

    for (firstOutOfOrder = 1; firstOutOfOrder < listLength;  firstOutOfOrder++)
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])  {
            temp = list[firstOutOfOrder];  location = firstOutOfOrder;
            do
            {
                list[location] = list[location - 1];  location--;
            }
            while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
}

int binarySearch(const vector<int> &list, int listLength, int searchItem){
    int first = 0;
    int last = listLength - 1;
    int mid;

    bool found = false;

    while (first <= last && !found){
        mid = (first + last) / 2;

        if(list[mid] == searchItem)
        found = true;
        else if(list[mid] > searchItem)
            last = mid - 1;
        else
            first = mid + 1;
    }
    if(found)
        return mid;
    else
        return -1;
}





int main() {
    const int MAX_ARRAY_SIZE = 5;
    vector<int>list;
    int numbers[MAX_ARRAY_SIZE] = {2, 1, 5, 8, 6};
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
        list.push_back(numbers[i]);
    vector<string>strList;
    insertionSort(list, list.size());
    binarySearch(list,list.size(),8);
    removeAt(list, list.size(), 1);
    for(int i = 0; i < list.size(); i++){
        cout << list[i] << endl;
    }
    cout << endl;
    string names[MAX_ARRAY_SIZE] = {"Bob", "Tom", "Sarah", "John", "Chris"};
    for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        strList.push_back(names[i]);
    }
    selectionSort(strList, MAX_ARRAY_SIZE);
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
        cout << strList[i] << endl;
}
