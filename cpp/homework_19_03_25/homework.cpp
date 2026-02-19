#include<iostream>
#include<set>
#include<unordered_set>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<algorithm>
int main(){
	//For rand
	srand(time(0));	
	
	int question_index = 1;
	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 1
	
	int n_q1;
	int number_q1;
	std::set<int> sorted_numbers_q1;
	
	std::cout<<"How many numbers do you want to give me.";
	std::cin>>n_q1;

	for(int i = 0; i < n_q1; i++){
		std::cout<<"Give me a number. " << n_q1-i <<" numbers left.";
		std::cin>>number_q1;
		sorted_numbers_q1.insert(number_q1);	
	}

	for(auto number : sorted_numbers_q1){
		std::cout<< number << " ";
	}
	std::cout<<std::endl;
	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 2
	
	int n_q2;
	int user_guess_q2;
	std::string answer_q2 = "Not Found" ;

	std::unordered_set<int> random_numbers_q2;

	std::cout<<"How many numbers do you want to have? ";
	std::cin>>n_q2;

	for(int i = 0; i< n_q2; i++){
		random_numbers_q2.insert(rand()%100+1);
	}
	
	std::cout<<"Give a number between 1 and 100 to see if the set has it ";
	std::cin>>user_guess_q2;

	if(random_numbers_q2.find(user_guess_q2) != random_numbers_q2.end()){
		answer_q2 = "Found";
	}
	
	std::cout<< answer_q2 << std::endl;

	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 3
	
	std::vector<int> vector_q3 = {1,22,4,4,4,-10,-10,123,22,44,10};

	std::set<int> set_q3;

	for(auto it = vector_q3.begin(); it!=vector_q3.end(); it++){
		set_q3.insert(*it);
	}

	for(auto number : set_q3){
		std::cout<< number << " ";
	}
	std::cout<<std::endl;
	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 4
	
	std::set<int> set_q4 = {1,3,5,7,9};

	int number_to_remove_q4;

	std::cout<<"What number do you want to remove.";
	std::cin>>number_to_remove_q4;
	
	auto it_q4 = set_q4.find(number_to_remove_q4);

	if(it_q4 != set_q4.end()){
		set_q4.erase(it_q4);
	}

	for(auto number : set_q4){
		std::cout<<number<< " ";
	}
	std::cout<<std::endl;
	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 5
	
	std::unordered_set<int> set1_q5 = {1,2,3,4,5};
	std::unordered_set<int> set2_q5 = {3,4,5,6,7};

	std::unordered_set<int> union_q5;
	std::unordered_set<int> intersection_q5;
	
	for(auto number : set1_q5){
		union_q5.insert(number);
		
		if(set2_q5.find(number)!=set2_q5.end()){
			intersection_q5.insert(number);
		}
	}

	for(auto number : set2_q5){
		union_q5.insert(number);
	}

	std::cout<<"Union"<<std::endl;

	for(auto number : union_q5){
		std::cout<< number << " ";
	}
	
	std::cout<<std::endl<<"Intersection"<<std::endl;
	
	for(auto number : intersection_q5){
		std::cout<< number << " ";
	}

	std::cout<<std::endl;
	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 6
	
	int n_q6;
	int user_input_q6;
	std::vector<int> vector_q6;

	std::cout<<"How many numbers do you want to give";
	std::cin>>n_q6;

	for(int i = 0 ; i < n_q6; i++){
		std::cout<<"Give me numbers."<< n_q6-i << " numbers left.";
		std::cin>>user_input_q6;
		vector_q6.push_back(user_input_q6);
	}
	
	for(int i = 0; i < vector_q6.size()/2 ; i++){
		int mirror_index = vector_q6.size()-1-i;
		vector_q6[i] += vector_q6[mirror_index];
		vector_q6[mirror_index] = vector_q6[i]-vector_q6[mirror_index];
		vector_q6[i] -= vector_q6[mirror_index];
	}

	for(auto number : vector_q6){
		std::cout<<number<< " ";
	}
	std::cout<<std::endl;
	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 7
	
	int n_q7;
	int user_input_q7;
	std::vector<int> vector_q7;
	std::set<int> bootleg_sorter_q7;

	std::cout<<"How many numbers do you want to give";
	std::cin>>n_q7;

	for(int i = 0 ; i < n_q7; i++){
		std::cout<<"Give me numbers."<< n_q7-i << " numbers left.";
		std::cin>>user_input_q7;
		vector_q7.push_back(user_input_q7);
		bootleg_sorter_q7.insert(user_input_q7);
	}

	std::vector<int> ascending_q7;
	std::vector<int> descending_q7;

	auto it_asc_q7 = bootleg_sorter_q7.begin();
	auto it_des_q7 = bootleg_sorter_q7.end();
	it_des_q7--;
	for(int i = 0 ; i < bootleg_sorter_q7.size() ; i++){

		ascending_q7.push_back(*it_asc_q7);
		it_asc_q7++;
		descending_q7.push_back(*it_des_q7);
		it_des_q7--;
	}
	
	std::cout<<"Ascending\n";
	for(auto number : ascending_q7){
		std::cout<<number << " ";
	}

	std::cout<<"\nDescending\n"; 
	
	for(auto number : descending_q7){
		std::cout<<number << " ";
	}
	std::cout<<std::endl;
	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 8
	
	std::vector<int> vector_q8 = {-12,40,2,14,50,88,36,-230};

	auto result_q8 = std::minmax_element(vector_q8.begin(), vector_q8.end());

	std::cout<<"Min is "<< *result_q8.first<<std::endl;
	std::cout<<"Max is "<< *result_q8.second<<std::endl;
	
	std::cout<<"Question " << question_index++<<std::endl;
	//Question 9 
	
	std::string string_q9;

	std::cout<<"Give me a word. ";
	std::cin>>string_q9;

	std::stack<char> stack_q9;
	
	for(auto character : string_q9){
		stack_q9.push(character);
	}	

	int stack_size_q9 = stack_q9.size();
	for(int i = 0; i< stack_size_q9 ; i++){
		std::cout<<stack_q9.top();
		stack_q9.pop();
	}


	return 0;
}
