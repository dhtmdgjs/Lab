#include <iostream>
#include <map>
#include <string>

struct Student{
	int middleTest_score;
	int finalTest_score;
};

int main(){
	int student_count;
	std::cout << "How many students? ";
	std::cin >> student_count;
	
	std::map<std::string, Student> studentMap;
	
	for(int i=0; i< student_count; i++) {
		std::string name;
		Student student;
		
		std::cout << "Please enter student information : " << std::endl;
		std::cin >> name >> student.middleTest_score >> student.finalTest_score;
		
		// Add to the map
		auto result = studentMap.insert({name, student});
		
		if (result.second) {
			std::cout <<"\""<< name << "\" has been added to the map." << std::endl;
			} else {
				std::cout << "\"" << name << "\" already exists in the map." << std::endl;
				}
			}
		
		for (const auto& entry : studentMap) {
			std::cout << "student_name = " << entry.first
			<< ", middleTest_score =" <<entry.second.middleTest_score
			<< ", finalTest_score = " <<entry.second.finalTest_score << std::endl;
			}
			return 0;
		}
