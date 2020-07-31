#include <string>
#include <iostream>
#include <ostream>
#include <vector>

/*
Dacheng Li
I hereby plege that I have not received unauthorized help on this assignment
No collaborators
*/

class Student {	//student class declaration
	private:
		std::string sID;
	public:
		Student(std::string word) { sID = word; };	//constructor with params
		Student();	//default constructor
		std::string get_id() { return sID; };	//returning student ID
		void sChange(std::string tochange) { sID=tochange; };	//changing ID function- not used in current build
	
};
class Employee { 
	private:
		std::string eID;
	public:
		Employee(std::string word) { eID = word; };//constructors 
		Employee();
		std::string get_id() { return eID; };//reading employee ID
		void eChange(std::string tochange) { eID = tochange; };//changing ID function- not used in current build
};

class TeachingAssistant : public Employee, public Student	//extending both student and employee
{
	public:
		TeachingAssistant(std::string student, std::string employee): Student(student), Employee(employee) {};		//constructors- note the declaration must include a call to the respective student and employee classes
		TeachingAssistant();
		std::string get_id() { return Employee::get_id(); }; // Return Employee ID
		std::string student_id() { return Student::get_id(); }; // Return Student ID
};

//string TeachingAssistant::get_id()
//{
//	return Employee::get_id();
//}
//
//string TeachingAssistant::student_id()
////Make student value available by a different name
//{
//	return Student::get_id();
//}

int main()
{
	Student* fred = new Student("fred");
	Employee* jane = new Employee("jane");
	std::cout << "id for fred " << fred->get_id() << "\n";
	std::cout << "id for jane " << jane->get_id() << "\n";
	TeachingAssistant* beth = new TeachingAssistant("beth_Sid", "beth_Eid");
	std::cout << "id for Employee beth " << beth->get_id() << "\n";
	std::cout << "id for Student beth " << beth->student_id() << "\n";
	std::vector<Student*> students;
	students.push_back(fred);
	students.push_back(beth);
	for (int i = 0; i < students.size(); i++)
		std::cout << "student " << students[i]->get_id() << "\n";
	std::vector<Employee*> employees;
	employees.push_back(jane);
	employees.push_back(beth);
	for (int i = 0; i < employees.size(); i++)
		std::cout<< "employee " << employees[i]->get_id() << "\n";
	return 0;
}
