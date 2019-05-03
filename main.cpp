//
// Created by Honghao Li on 2019-04-28.
//
#include <iostream>
#include <algorithm>
#include <vector>
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
    vector<int> sorted;
    int min;
    for (int i = 0; i < size; ++i) {
        min=find_min(v);
        sorted.push_back(min);
        int current_min_index;
        for (int j = 0; j < v.size(); ++j) {
            if(v[j]==min){
                current_min_index=j;
                break;
            }
        }
        v.erase(v.begin()+current_min_index);
    }
    v=sorted;
}

void double_selection_sort(vector<int>& v, int size){
    vector<int> sorted(size);
    int min,max;
    int bottom=0,top=size-1;
    int current_min_index,current_max_index;
    bool min_found,max_found;
    for (int i = 0; v.size()!=0; ++i) {
        if(top==bottom){
            int temp=v[0];
            sorted[top]=temp;
            v.pop_back();
            break;
        }
        min=find_min(v);
        max=find_max(v);
        for (int j = 0; j < v.size() && !(min_found && max_found); ++j) {
            if(v[j]==min){
                current_min_index=j;
                min_found=true;
            }
            if(v[j]==max){
                current_max_index=j;
                max_found=true;
            }
        }
        min_found=max_found=false;
        sorted[bottom]=v[current_min_index];
        sorted[top]=v[current_max_index];
        if(current_min_index<current_max_index){
            v.erase(v.begin()+current_max_index);
            v.erase(v.begin()+current_min_index);
        }else{
            v.erase(v.begin()+current_min_index);
            v.erase(v.begin()+current_max_index);
        }
        top--;
        bottom++;
    }
    v=sorted;
}

int main(int argc,char** argv){

    int vector_size;
    cout<<"Please enter the size of vector for sorting"<<endl;
    cin>>vector_size;
    if(!vector_size){
        wcerr<<"invalid input\n";
        return 99;
    }
    std::srand ( unsigned ( std::time(0) ) );
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
    double_selection_sort(myvector,vector_size);
    auto stop=chrono::high_resolution_clock::now();
    print(myvector);
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    long time=duration.count();
    int second=time/1000000;
    double left=duration.count()-second*1000000;
    cout<<"sorting: "<<second<<"."<<left<<" seconds"<<endl;

    return 0;
}
