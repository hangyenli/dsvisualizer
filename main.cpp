//
// Created by Honghao Li on 2019-04-28.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int myrandom (int i) { return std::rand()%i;}

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
                tmp=v[j];
                v[j]=v[j+1];
                v[j+1]=tmp;
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
                tmp=v[j];
                v[j]=v[j+1];
                v[j+1]=tmp;
            }
        }
        for (int k = current_max-1; k > current_min+1; --k) {
            if(v[k]<v[k-1]){
                tmp=v[k];
                v[k]=v[k-1];
                v[k-1]=tmp;
            }
        }
        current_max--;
        current_min++;
    }
}
int main(int argc,char** argv){
    //vector<int> myvector
    //init(v)
    //print(v)
    //sort(v)
    //print(v)

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
    cocktail_shake_sort(myvector, vector_size);
    auto stop=chrono::high_resolution_clock::now();

    print(myvector);

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    long time=duration.count();
    int second=time/1000000;
    double left=duration.count()-second*1000000;
    cout<<"sorting: "<<second<<"."<<left<<" seconds"<<endl;

}
