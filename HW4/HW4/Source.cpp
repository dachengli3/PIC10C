#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
/*
Dacheng Li- 305009522
I have not received help on this assign.
No collaborators
*/

template<typename T, typename TComp = std::less<T>>

class more {	//define more type
public:
	bool operator()(T lhs, T rhs) {
		return lhs > rhs;
	}
};

template<typename T, typename TComp = std::less<T>>
class less {	//define less type
public:
	bool operator()(T lhs, T rhs) {
		return rhs > lhs;
	}
};


template<typename T, typename TComp = more<T>>
int binary_search(std::vector<T>& vec, int start, int end, const T& toFind, TComp comp)
{
	//sorting from most to least- bubble sort
	
		bool swap = true;	//if we want to swap
		while (swap == true) {
			swap = false;
			for (size_t i = 1; i < vec.size(); ++i) {
				if (comp(vec[i], vec[i - 1])) {
					swap = true;
					T tmp = vec[i];	//swapping lesser value with greater value
					vec[i] = vec[i - 1];
					vec[i - 1] = tmp;
				}
			}
		}
	// Error- Termination condition: start index greater than end index
	if (start > end)
	{
		return -1;
	}
	// Find the middle element of the vector and use that for splitting
	// the array into two pieces.
	const int middle = start + ((end - start) / 2);	//finding middle index
	if (abs(vec[middle]-toFind)<=0.0001)	//double value keeps changing unexpectedly
	{
		return middle;
	}
	else if (vec[middle] < toFind)
	{
		return binary_search(vec, start, middle-1 , toFind, comp);	//find value recursively
	}
	return binary_search(vec, middle+1, end, toFind, comp);
}

//the following function performs exactly the same as the previous one, except accounting for the (default) least->most sort
template<typename T, typename TComp = std::less<T>>
int binary_search(std::vector<T>& vec, int start, int end, const T& toFind)
{
	TComp comp;
	bool made_a_swap = true;
	while (made_a_swap == true) {
		made_a_swap = false;
		for (size_t i = 1; i < vec.size(); ++i) {
			if (comp(vec[i], vec[i - 1])) {
				made_a_swap = true;
				T tmp = vec[i];
				vec[i] = vec[i - 1];
				vec[i - 1] = tmp;
			}
		}
	}
	// Termination condition: start index greater than end index
	if (start > end)
	{
		return -1;
	}
	// Find the middle element of the vector and use that for splitting
	// the array into two pieces.
	const int middle = start + ((end - start) / 2);
	if (vec[middle] == toFind)
	{
		return middle;
	}
	else if (vec[middle] > toFind)
	{
		return binary_search(vec, start, middle - 1, toFind);
	}
	return binary_search(vec, middle + 1, end, toFind);
}


int main()
{
	std::vector<int> vi = { 1, 3, 5,10,19 };
	std::vector<double> vd = { 3.14,2.7,2.54, 0.19 };
	more<double> dd;
	std::vector<std::string> vs = { "one", "two","zero" };
	std::string two = "two";

	//Alt test cases- should get 422

	/*std::vector<int> vi = { 1, 2, 5, 10, 7, 9, 2 };
	std::vector<double> vd = { 3.14, 2.85, 7.6, 1.2, 1.9, 3.0 };
	std::vector<std::string> vs = { "chalk", "dust", "book", "bottle", "bugman" };
	std::string testStr = "bugman";*/

	std::cout << binary_search(vi, 0, vi.size(), 10);
	std::cout << binary_search(vd, 0, vd.size(), 2.7, dd);
	std::cout << binary_search(vs, 0, vs.size(), two);
	//this code should output: 311
	return 0;
}
