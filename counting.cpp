#include <iostream>
#include <vector>
#include <algorithm>

using DArray = std::vector<int>;


void countingSort(DArray& array){
    if(array.empty()) return;


    // first find the maximum value

    int maxValue = *std::max_element(array.begin(),array.end());
    int minValue = *std::min_element(array.begin(),array.end());
    
    int range = maxValue - minValue + 1;

    DArray count(range,0);
    DArray output(array.size());


    // count the occurence
    for(int num: array){
        count[num - minValue]++;
    }

    // updating the count[i] so it contains actual position in output

    for (int i=1;i<range;i++){
        count[i] += count[i-1];
    }
    // Buidling the output

    for (int i = array.size()-1;i>=0;i--){
        output[count[array[i]-minValue]] = array[i];
        count[array[i]-minValue]--;
    }
   
    array = output;

}


int main(){
    std::vector<int> data = {4,2,2,8,3,3,1};
    countingSort(data);

    std::cout << "Sorted array: ";
    for (int x : data) std::cout << x << " ";
    return 0;
}
