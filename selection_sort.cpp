#include <iostream>
#include <algorithm>
#include <utility>
void SelectionSort(std::vector<int>& array){
    for(int i=0;i<array.size()-1;i++){
        int min_index = i;
        for(int j=1;j<array.size();j++){
            if (array[min_index] > array[j]){

                min_index = j;
            }

        }

        if (min_index != i){
            std::swap(array[i],array[min_index]);
        }
    }
}



int main(){
    std::vector<int> data = {64, 25, 12, 22, 11};
    SelectionSort(data);

    std::cout << "Sorted array: ";
    for (int x : data) std::cout << x << " ";
    return 0;
}
