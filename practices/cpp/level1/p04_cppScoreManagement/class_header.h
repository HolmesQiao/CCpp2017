class Course{
	public:
		Course(int grade = -1, std::string name = "\0"){this->grade = grade; this->name = name;}
		void inputGrade(double grade);
	private:
		double grade;
		std::string name;
};

class Student{
	public:
		Student(long studentNumber, std::string name, int courseNum = 0){this->studentNumber = studentNumber; this->name = name; this->courseNum = courseNum;}
		friend class Course;
	private:
		int courseNum;
		long studentNumber;
		std::string name;
		Course *course;
};
