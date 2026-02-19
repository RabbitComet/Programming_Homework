#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
//Question_1 O(nlog(n)), because making new elements for a map is O(log(n))

std::map<std::string, int> word_occurences(std::string paragraph){
	std::map<std::string, int>words;
	std::string word = "";
	paragraph +=" ";//To fix not picking up final word of the paragraph, if there is no punctuation.
	for(auto character : paragraph){
		if(!(character == ' ' || character == '!' || character == '.' || character == ',' || character == '?' )){
			word+=character;	
			continue;
		}
		if(word!=""){		
			words[word]++;
			word = "";
		}
	}

	return words;


}

//Question_2, is O(n).

std::string first_non_repeating(std::string word){
	std::unordered_map<char, int> letters;
	for(auto character : word){
		letters[character]++;
	}
	for(auto character : word){
		if(letters[character] == 1){
			std::string str{ character};
			return  str;
		}
	}

	return "-1";

}

//Question_3, is O(1)


void int_swap(int& num1, int& num2){
	int intermediary = num1;
	num1 = num2;
	num2 = intermediary;
}

int main(){
	//Question_1
	
	std::string paragraph;

	std::cout<<"Give me a paragraph!";

	std::getline(std::cin,paragraph);
	

	for(auto word : word_occurences(paragraph)){
		std::cout<< word.first << ": " << word.second<< std::endl;
	}

	//Question_2

	std::string word;

	std::cout<<"Give me a word!";

	std::getline(std::cin,word);

	std::cout<<"First non repeating character is: " << first_non_repeating(word)<<std::endl;
	
	//Question_3
	
	int num1,num2;

	std::cout<<"Give me 2 numbers";

	std::cin>>num1;
	std::cin>>num2;

	int_swap(num1,num2);

	std::cout<<"Num1 is now : "<<num1 << "\nNum2 is now : " << num2;
	
	
	return 0;

}
