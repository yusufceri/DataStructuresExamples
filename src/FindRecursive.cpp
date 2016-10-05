//============================================================================
// Name        : FindRecursive.cpp
// Author      : yc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int kSmall(int *arrA, int start, int end, int k);
void swap(int *arrA, int a, int b);

int main() {
	cout << "TEST !!!!" << endl; // prints

	int arrA[] = { 4,7,3,6,8,1,9,2 };
	int a = 7;
	int x = kSmall(arrA, 0, 7, a);

	cout<<a<<"th Smallest element: "<<x<<endl;

	return 0;
}


int kSmall(int *arrA, int start, int end, int k) {

	int pivot = start;
	int startTmp = pivot+1;
	int endTmp = end;

	int counter = 0;

	cout<<endl<<"*********   start = "<<start<<"    end="<<end<<endl;

	if(end > 7){
		cout<<"HATA end="<<end<<" !!!!!!!!!!!!"<<endl;
		return -1;
	}

	while(startTmp <= endTmp)
	{
		endTmp = end;

		if(arrA[startTmp] > arrA[pivot]){ //If number bigger than pivot then change last bigger value with this number
			while(startTmp < endTmp)
			{
				if(arrA[endTmp] < arrA[pivot])
				{
					break;
				}else{
					endTmp--;
				}
			}

			int tmpValue = arrA[startTmp];
			arrA[startTmp] = arrA[endTmp];
			arrA[endTmp] = tmpValue;

		}

		startTmp++;

		//cout<<"=============================================="<<endl;
		int tmp = 0;
		while(tmp <= end){
			cout<<arrA[tmp]<<" ";
			tmp++;
		}
		cout<<endl;
	}

	startTmp = start;
	do{
		startTmp++;
		if(startTmp >= end)
					break;
	}while(arrA[pivot] >= arrA[startTmp] );


	int tmpValue = arrA[startTmp-1];
	arrA[startTmp-1] = arrA[pivot];
	arrA[pivot] = tmpValue;

	pivot = startTmp - 1;

	cout<<"PIVOT = "<<pivot<<endl<<endl;



		if (pivot == k)
			return arrA[pivot];// if pivot is kth element , return
		else if (pivot < k){
			// if pivot is less than k, then kth element will be on the right
			cout<<"Before kSmall    start="<<pivot+1<<"   end"<<end<<endl<<endl;

			return kSmall(arrA, pivot + 1, end, k);
		}else
			// if pivot is greater than k, then kth element will be on the right
			return kSmall(arrA, start, pivot - 1, k);
}



/*int kSmall(int *arrA, int start, int end, int k) {
		int left = start;
		int right = end;
		int pivot = start;

		cout<<"============================================"<<endl;
		int ltmp = left;
		while(ltmp <= right){
			cout<<arrA[ltmp]<<" ";
			ltmp++;
		}

		cout<<endl;
		cout<<"============================================"<<endl;


		while (left <= right) {
			while (left <= right && arrA[left] <= arrA[pivot])
				left++;
			while (left <= right && arrA[right] >= arrA[pivot])
				right--;
			if (left < right) {
				swap(arrA, left, right);
				left++;
				right--;
			}

			cout<<left<<" "<<right<<"     ";
			int t = start;
			while(t <= end){
				cout<<arrA[t]<<" ";
				t++;
			}

			cout<<endl;
		}

		swap(arrA, pivot, right);
		int t = start;
					while(t <= right){
						cout<<arrA[t]<<"- ";
						t++;
					}

					cout<<endl;
		if (pivot == k)
			return arrA[pivot];// if pivot is kth element , return
		else if (pivot < k)
			// if pivot is less than k, then kth element will be on the right
			return kSmall(arrA, pivot + 1, end, k);
		else
			// if pivot is greater than k, then kth element will be on the right
			return kSmall(arrA, start, pivot - 1, k);
	}*/

void swap(int *arrA, int a, int b) {
	int x = arrA[a];
	arrA[a] = arrA[b];
	arrA[b] = x;
}
