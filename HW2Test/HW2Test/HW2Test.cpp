#include <vector>
#include <iostream>
#include <ostream>

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
template <typename T>
class Chart
{
	typedef int size_type;
	friend class Iterator;
public:
	class Iterator
	{
	public:
		typedef Iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_Iterator_tag Iterator_category;
		typedef int difference_type;
		Iterator() {};
		Iterator(Iterator* ptr) { point = ptr; };
		~Iterator() { delete point; };
		Iterator& operator!=(const self_type& comp) { return point != comp; }
		self_type operator++() { self_type i = *this; point++; return i; }
		self_type Iterator& operator++() { point++; return *this; }; //prefix increment
		void setCont(Chart toset) { container = &toset; }
	private:
		Chart* container;
		Iterator *point = nullptr;
		friend class Chart;
	};
	Chart() {};
	virtual void add(int item) { data.push_back(item); }
	void Chart::draw() const
	{
		Iterator x;
		x.setCont(*this);
		for (x = begin(); x != end(); ++x)
		{
			std::cout << &x;
			for (int i = 0; i < x; i++)
			{
				std::cout << "*";
			}
			std::cout << '\n';
		}
		//for (int x = 0; x != data.size(); ++x)
		//{
		//	std::cout << data[x];
		//	for (int i = 0; i < data[x]; i++)
		//	{
		//		std::cout << "*";
		//	}
		//	std::cout << '\n';
		//}
	}
	Iterator begin() {
		return Iterator(data.begin());
	};
	Iterator end() {
		return Iterator(data.end());
	};
protected:
	//T* stored;
	std::vector <int> data;
};

class BarChart : public Chart
{
public:
	virtual void draw() const { this->Chart::draw(); };
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


