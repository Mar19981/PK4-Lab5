#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
struct Student {
	std::string name, surname, gender;
	Student(const std::string& n, const std::string& sn, const std::string& g);
};

class Classroom {
	std::vector<Student> students;
public:
	Classroom(const std::string& file);
	bool anyName(const std::string& value);
	bool anySurname(const std::string& value);
	bool anyGender(const std::string& value);
	bool noneName(const std::string& value);
	bool noneSurname(const std::string& value);
	bool noneGender(const std::string& value);
	bool allName(const std::string& value);
	bool allSurname(const std::string& value);
	bool allGender(const std::string& value);
};

#endif // !CLASSROOM_H
