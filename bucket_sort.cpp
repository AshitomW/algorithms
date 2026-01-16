#include <iostream>
#include <vector>
#include <algorithm>



void BucketSort(std::vector<float>& arr){
    int n = arr.size();
    std::vector<float> buckets[n];


    for (int i=0;i<n;i++){
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }


    // sortring individually

    for (int i=0;i<n;i++){
        std::sort(buckets[i].begin(),buckets[i].end());
    }


    int index = 0;
    for (int i = 0;i<n;i++){
        for(size_t j=0;j<buckets[i].size();j++){
            arr[index++] = buckets[i][j];
        }
    }

}


int main() {
    std::vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    BucketSort(arr);

    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
