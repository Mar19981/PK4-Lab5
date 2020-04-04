#include "Classroom.h"

Student::Student(const std::string& n, const std::string& sn, const std::string& g) : name(n), surname(sn), gender(g)
{
}

Classroom::Classroom(const std::string& file)
{
	std::ifstream input(file);
	if (input)
	{
		std::string name, surname, gender;
		while (!input.eof())
		{
			input >> name >> surname >> gender;
			students.emplace_back(Student(name, surname, gender));
		}
		input.close();
	}
	else
		throw std::runtime_error("Failed to open a file " + file + '\n');
}

bool Classroom::anyName(const std::string& value)
{
	return std::any_of(students.begin(), students.end(), [value](const Student& st) {return st.name == value; });
}

bool Classroom::anySurname(const std::string& value)
{
	return std::any_of(students.begin(), students.end(), [value](const Student& st) {return st.surname == value; });
}

bool Classroom::anyGender(const std::string& value)
{
	return std::any_of(students.begin(), students.end(), [value](const Student& st) {return st.gender == value; });
}

bool Classroom::noneName(const std::string& value)
{
	return std::none_of(students.begin(), students.end(), [value](const Student& st) {return st.name == value; });
}

bool Classroom::noneSurname(const std::string& value)
{
	return  std::none_of(students.begin(), students.end(), [value](const Student& st) {return st.surname == value; });
}

bool Classroom::noneGender(const std::string& value)
{
	return  std::none_of(students.begin(), students.end(), [value](const Student& st) {return st.gender == value; });
}

bool Classroom::allName(const std::string& value)
{
	return  std::all_of(students.begin(), students.end(), [value](const Student& st) {return st.name == value; });
}

bool Classroom::allSurname(const std::string& value)
{
	return std::all_of(students.begin(), students.end(), [value](const Student& st) {return st.surname == value; });
}

bool Classroom::allGender(const std::string& value)
{
	return std::all_of(students.begin(), students.end(), [value](const Student& st) {return st.gender == value; });
}
