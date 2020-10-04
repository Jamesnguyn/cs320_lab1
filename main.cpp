#include <iostream>
#include <map>
using namespace std;

bool multiplication_check (int array[], int size) {
    if (size < 3) {
        return false;
    }
        map<int, int> content_count;
        for (int i = 0; i < size; i++) {
            content_count[array[i]] += 1;
        }

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                int mult = array[i] * array[j];
                content_count[array[i]] -= 1;
                content_count[array[j]] -= 1;
                if (content_count[mult] > 0) {
                    cout << "Combination found:" << array[i] << "*" << array[j] << "=" << mult << endl;
                    return true;
                }
                content_count[array[i]] += 1;
                content_count[array[j]] += 1;
            }
        }
        return false;
    }

int main() {
    //int arr[] = {0,1,3,5,15};
    int arr[] = {6,4,-3,-2,0,5};
    //int arr[] = {1,2};
    //int arr[] = {2,-4,-3,10,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    if(!multiplication_check(arr,size)){
        cout<<"Error"<<endl;
    }
}