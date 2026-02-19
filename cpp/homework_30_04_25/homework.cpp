#include<iostream>

//Question 3
void doubler(int* arr_ptr, int size){

	for(int i = 0; i<size;i++){
		*(arr_ptr+i) *=2;
	}

}
//Question 4
void min_max(int* arr_ptr, int size, int*& min, int*& max){
	if(size!=0){
		min = arr_ptr;
		max = arr_ptr;
	}
	for(int i = 1; i < size; i++){
		if(*(arr_ptr+i)<*min){
			min = arr_ptr+i;
		}
		else if(*(arr_ptr+i)>*max){
			max = arr_ptr+i;
		}
	}
}
//Question 5
void swap(int* num1, int* num2){
	int num_mid = *num1;
	*num1 = *num2;
	*num2 = num_mid;
}

//Question 6
void show(int* arr_ptr, int size){

	for(int i = 0; i< size; i++){
		std::cout<<*(arr_ptr+i)<< " ";
	}

	std::cout<<std::endl;
}

int main(){
	//Question 1
	int size;

	std::cout<<"How big do you want your array: ";
	std::cin>>size;
	
	int* arr_ptr = new int[size];

	//Question 2
	for(int i = 0; i < size; i++){
		std::cout<<"Number: ";
		std::cin>>*(arr_ptr+i);
	}
	
	//Question 3
	doubler(arr_ptr, size);
	show(arr_ptr,size);


	//Question 4
	
	int* min;
	int* max;
	
	min_max(arr_ptr, size, min, max);
	
	std::cout<<"Smallest number is: "<< *min << " \nLargest number is: "<<  *max << std::endl ;
	
	//Question 5
	swap(min,max);
	
	//Question 6
	show(arr_ptr, size);
	
	//Question 7
	delete[] arr_ptr;



}
