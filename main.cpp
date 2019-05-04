//
// Created by Honghao Li on 2019-04-28.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include "detail.h"

using namespace std;

int myrandom (int i) { return std::rand()%i;}

int find_min(vector<int>& v){
    int min=v[0];
    for (int i = 1; i < v.size(); ++i) {
        min=min<v[i]?min:v[i];
    }
    return min;
}
int find_max(vector<int>& v){
    int max=v[0];
    for (int i = 1; i < v.size(); ++i) {
        max=max>v[i]?max:v[i];
    }
    return max;
}
void swap(int* p1, int* p2){
    int tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}
void print(vector<int>& v){
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}
void bubble_sort(vector<int>& v, int size){
    int current_max=size;
    int tmp;
    for (int i = 0; i < current_max-1; current_max--) {
        for (int j = 0; j < current_max-1; ++j) {
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}
void random_sort(vector<int>& v, int size){
    while(!is_sorted(v.begin(),v.end())){
        random_shuffle (v.begin(), v.end());
    }
}
void cocktail_shake_sort(vector<int>& v, int size){
    //a improved version of bubble sort
    int current_max=size;
    int current_min=0;
    int tmp;
    for (int i = current_min; i < current_max-1; ++i) {
        for (int j = 0; j < current_max-1; ++j) {
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
        for (int k = current_max-1; k > current_min+1; --k) {
            if(v[k]<v[k-1]){
                swap(v[k],v[k-1]);

            }
        }
        current_max--;
        current_min++;
    }
}
void gnome_sort(vector<int>& v, int size){
    int current_index=0;
    int temp;
    bool need_go_back=false;
    for (int i = current_index; i < size-1; ++i) {
        need_go_back=false;
        if(v[current_index]>v[current_index+1]){
            swap(v[current_index],v[current_index+1]);
            need_go_back=true;
            temp=current_index;
        }
        if(need_go_back){
            for (int j = temp; j > 0; --j) {
                if(v[j-1]>v[j]){
                    swap(v[j-1],v[j]);
                }else{
                    break;
                }
            }
        }
        current_index++;
    }
}
void odd_even_sort(vector<int>& v, int size) {
    while(!is_sorted(v.begin(),v.end())){
        for (int i = 0; i < size-1; i+=2) {
            if(v[i]>v[i+1]){
                swap(v[i],v[i+1]);
            }
        }
        for (int i = 1; i < size-1; i+=2) {
            if(v[i]>v[i+1]){
                swap(v[i],v[i+1]);
            }
        }
    }
    /* 0 1 2 3 4 5 6       length:7
    * -------------
    * 5 1 0 4 3 6 2
    * 1 5 0 4 3 6 2
    * 1 0 5 3 4 2 6
    * 0 1 3 5 2 4 6
    * 0 1 3 2 5 4 6
    * 0 1 2 3 4 5 6
    * */
}
void selection_sort(vector<int>& v, int size){
    int i, j, min_idx;
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted vay
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (v[j] < v[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(v[min_idx], v[i]);
    }
}
void double_selection_sort(vector<int>& v, int size){
    int i, j, min_idx,max_idx,current_max=size-1;
    for (i = 0; i < size-1; i++,current_max--){
        min_idx = i;
        max_idx = current_max;
        for (j = i+1; j < current_max+1; j++){
            if (v[j] < v[min_idx]){
                min_idx = j;
            }
            if(v[j]>v[max_idx]){
                max_idx = j;
            }
        }
        swap(v[min_idx], v[i]);
        swap(v[max_idx], v[current_max]);
    }
}
void insertion_sort(vector<int>& v, int size) {
    int current_index,copy;
    for (current_index = 1; current_index < size; current_index++) {
        copy = current_index;
        while (copy > 0 && v[copy - 1] > v[copy]) {
            swap(v[copy],v[copy-1]);
            copy--;
        }
    }
}

int main(int argc,char** argv){

    int vector_size;
    cout<<"Please enter the size of vector for sorting"<<endl;
    cin>>vector_size;
    if(!vector_size){
        wcerr<<"invalid input\n";
        return 99;
    }
    std::srand (unsigned(time(0)));
    std::vector<int> myvector;
    // set some values:
    for (int i=0; i<vector_size; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
    // using myrandom:
    std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);
    print(myvector);
    cout<<"---------------------------------------\n";
    auto start=chrono::high_resolution_clock::now();

//    bubble_sort(myvector,vector_size);
//    random_sort(myvector,vector_size);
//    cocktail_shake_sort(myvector, vector_size);
//    gnome_sort(myvector,vector_size);
//    odd_even_sort(myvector,vector_size);
//    selection_sort(myvector,vector_size);
//    double_selection_sort(myvector,vector_size);
//    insertion_sort(myvector,vector_size);
    auto stop=chrono::high_resolution_clock::now();
    print(myvector);
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    long time=duration.count();
    int second=time/1000000;
    double left=duration.count()-second*1000000;
    cout<<"sorting: "<<second<<"."<<left<<" seconds"<<endl;

    return 0;
}

