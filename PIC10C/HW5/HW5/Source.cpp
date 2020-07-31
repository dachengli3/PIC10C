#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
#include <sstream> 
#include <functional>

//bool greaterThanVal(std::string test, int value)
//{
//	return (test.length() > value);
//}

void show(std::vector<std::string> words, int length)
{
	std::sort(words.begin(), words.end(), std::greater<std::string>());// std::greater<std::vector<std::string>>());
	//stl sort function 
	std::vector<std::string>::iterator holder;
	//creation of own iterator for vector
	holder = std::stable_partition(words.begin(), words.end(), [length](std::string i) {return i.length() >= length; });
	//creating partition with words larger than or equal to desiered size
	int greaterCount = std::count_if(words.begin(), words.end(), [length](std::string test) {return test.length()>=length; });
	//auto greaterCount = std::count_if(words.begin(), words.end(), greaterThanVal);
	std::cout<<greaterCount<< " words found with size greater than/equal to "<< length<< " and they are:\n";
	//printing
	for (std::vector<std::string>::iterator it = words.begin(); it != holder; ++it)
		std::cout << *it <<" ";
};

int main()
{	//main test code provided by professor
	std::vector < std::string > words;
	std::string word;
	int word_length;
	std::cout << "Words = ";
	std::getline(std::cin, word);
	std::stringstream sentence(word);
	while (sentence >> word)
	{
		words.push_back(word);
	}
	std::cout << std::endl;
	std::cout << "Word length = ";
	std::cin >> word_length;
	std::cout << std::endl;
	show(words, word_length);
	return 0;
}
