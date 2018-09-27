#include<iostream>
using namespace std;

int insertSort(int array[],int range){
  for(int i=1;i<range;i++){
    //对[0...j]进行排序，使该区间有序化
    for(int j=0;j<=i;j++){
			if(array[i]<array[j]){
				int t=array[i];
				array[i]=array[j];
				array[j]=t;
			}
    }
  }
}

int main(){
  
}
