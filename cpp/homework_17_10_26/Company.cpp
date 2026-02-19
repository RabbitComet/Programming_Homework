#include<iostream>
#include<vector>

class Employee {
protected:
    std::string name;
    int salary;
private:
    void validate(int salary) {
        if (salary < 0) {
            throw(std::string("Pay is too low, must be >=0"));
        }
    }
public:
    Employee(const std::string& name,const int& salary) {
        validate(salary);
        this->salary = salary;
        this->name = name;

    }
    virtual void work() = 0;
    std::string getName() {
        return name;
    }

    virtual ~Employee() {};

};

class Developer : public Employee {
    public:
        Developer(const std::string& name,const int& salary) : Employee(name, salary) {};

        void work() override {
            std::cout << "Developer " << name << " is writing code\n";
        }

        ~Developer() override {
            std::cout << "Developer " << name << " has been fired.\n";
        }

};

class Intern : public Employee {
    public:
        Intern(const std::string& name, const int& salary) : Employee(name, salary) {};

        void work() override {
            std::cout << "Intern " << name << " is learning and assisting\n";
        }

        ~Intern() override {
            std::cout << "Intern " << name << " has been fired.\n";
        }

};

class Manager : public Employee {
    public:
        Manager(const std::string& name, const int& salary) : Employee(name, salary) {};

        void work() override {
            std::cout << "Manager " << name << " is planning the project\n";
        }

        ~Manager() override {
            std::cout << "Manager " << name <<" has been fired.\n";
        }

};

class Company {
    private:
        std::vector<Employee*> employees;
    public:
        void hire(Employee*& employee) {
            employees.push_back(employee);
        }

        void showWork() {
            for (const auto& employee : employees) {
                employee->work();
            }
        }

        void fireAll() {
            for (const auto & employee : employees) {
                delete employee;
            }
            employees.clear();
        }

        ~Company() {
            fireAll();
        }
};


int main() {
    try {
        Company company;
        std::string name;
        int salary;
        Employee* employee;
        std::cout << "Whats the name of the Manager?\n";
        std::cin >> name;
        std::cout << "Whats the salary of the Manager.\n";
        std::cin >> salary;
        employee = new Manager(name, salary);
        company.hire(employee);
        std::cout << "Whats the name of the Developer?\n";
        std::cin >> name;
        std::cout << "Whats the salary of the Developer.\n";
        std::cin >> salary;
        employee = new Developer(name, salary);
        company.hire(employee);
        std::cout << "Whats the name of the Intern?\n";
        std::cin >> name;
        std::cout << "Whats the salary of the Intern.\n";
        std::cin >> salary;
        employee = new Intern(name, salary);
        company.hire(employee);
        company.showWork();

    }
    catch (std::string errorMsg) {
        std::cout << errorMsg;
    }



    return 0;
}