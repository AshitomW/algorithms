#include <iostream>



void BubbleSort(std::vector<int>& array){
    int N = array.size();
    for (int i = 0; i < N ; i++){
        for (int j = 0; j< N -i-1;j++){
            if(array[j]> array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}



int main(){
    std::vector<int> array = {10,8,5,0,2};
        BubbleSort(array);

    for(int item: array){
        std::cout << item << std::endl;
    }
}

