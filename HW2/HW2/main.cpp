#include <vector>
#include <iostream>
#include <ostream>
#include <iterator>

/*
Author- Dacheng Li 305009522
"I pledge that I have neither given nor received unauthorized assistance on this assignment."
Trinh Lang
*/

//range based for loop
//preincrement ++Iterator;
//Iterator !=Iterator; overload not equals
//deref Iterator

//need 2nd Iterator class
//const Iterator (cant change values)
//template <typename T>
class Chart
{
	//typedef int size_type;
	friend class Iterator;
	public:
		class Iterator
		{
			public:
				/*typedef Iterator self_type;
				typedef T value_type;
				typedef T& reference;
				typedef T* pointer;
				typedef std::forward_Iterator_tag Iterator_category;
				typedef int difference_type;*/
				Iterator() {};
				Iterator(Iterator* ptr) { point=ptr; };
				~Iterator() { delete point; };
				Iterator& operator!= (Iterator& comp) { return (*point)!=(comp); }
				Iterator& operator++() { Iterator i = *this; point++; return i; }
				Iterator& operator++(int dummy) { point++; return *this; }; //prefix increment
				void setCont(Chart toset) { container = &toset; }
				int getVal() { return value; };
			private:
				Chart* container;
				int value;
				Iterator *point=nullptr;
				friend class Chart;
		};

	Chart() {};
	virtual void add(int item) { data.push_back(item); }
	void draw() const {}
	std::vector <int> data;
	
	/*Iterator begin() {
		Iterator test=data.begin;
		return test;
	};
	Iterator end() {
		Iterator test = data.begin;
		return test;
	};*/
	protected:
		
};

class BarChart : public Chart
{
	public:
		virtual void draw() const {
			//Iterator x;
			/*std::vector<int>::iterator it;
			
			for ((&it) = (&data.begin());(*it)!=(*data.end()); it++)
			{
				std::cout << *it;
				for (int i = 0; i < *it; i++)
				{
					std::cout << "*";
				}
				std::cout << '\n';
			}*/
			for (int x = 0; x != data.size(); ++x)
			{
				std::cout << data[x];
				for (int i = 0; i < data[x]; i++)
				{
					std::cout << "*";
				}
				std::cout << '\n';
			} 
		}
};


int main()
{
	BarChart bc;
	bc.add(3);
	bc.add(5);
	bc.add(2);
	bc.add(7);
	bc.draw();
}


