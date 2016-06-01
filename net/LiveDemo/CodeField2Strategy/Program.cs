using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2Strategy
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Employee> employees = new List<Employee>();
            employees.Add(Employee.Create(EmployeeType.ENGINEER));
            employees.Add(Employee.Create(EmployeeType.MANAGER));
            employees.Add(Employee.Create(EmployeeType.SALESMAN));

            foreach (var employee in employees)
            {
                Console.WriteLine(employee.GetSalary());
            }
        }
    }
}
