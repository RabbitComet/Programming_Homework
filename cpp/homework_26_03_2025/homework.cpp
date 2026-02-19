#include <iostream>

//Question1 time complexity of O(n), n is the length of the given string, actual executions is n/2.
void char_swap(char& x, char& y){

	char middleMan = x;
	x = y;
	y = middleMan;
	return;
}

void reverse_string(std::string& given_string, int incr = 0){
	if(incr >= given_string.size()/2){
		return;
	}
	char_swap(given_string[incr], given_string[given_string.size()-1-incr]);
	reverse_string(given_string, incr+1);
	
}

//Question 2 time complexity is O(n) , n is the number of digits the given number has.
int digit_sum(int number){
	if(number==0){
		return 0;
	}
	if(number<0){
		number*=-1;
	}
	int sum = number - (number/10) *10; 
	return sum + digit_sum(number/10);
}

//Question 3 time complexity of O(n), n is n.
int sum_n(int n){

	if(n == 1){
		return n;
	}
	return n+sum_n(n-1);
}

int main(){
	//Question 1
	std::string user_string;
	
	std::cout<<"What string do you want to reverse. ";
	std::getline(std::cin,user_string);

	reverse_string(user_string);

	std::cout<< user_string << std::endl;

	//Question 2 
	int user_number;
	
	std::cout<<"Give me a number, i will get the sum of its digits. ";

	std::cin>>user_number;

	std::cout<<digit_sum(user_number)<<std::endl;

	//Question 3
	int user_number_2;
	
	do{	

	std::cout<<"Give me a Natural number, and i will give you the sum of natural numbers until that point. ";

	std::cin>>user_number_2;

	}while(user_number_2<=0);

	std::cout<<"Sum of Natural numbers until " << user_number_2 << " is: " << sum_n(user_number_2);

	return 0;
}
