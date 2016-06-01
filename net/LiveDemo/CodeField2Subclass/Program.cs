using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2Subclass
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Employee> employees = new List<Employee>();
            employees.Add(Employee.Create(Employee.ENGINEER, 20));
            employees.Add(Employee.Create(Employee.MANAGER, 30));
            employees.Add(Employee.Create(Employee.SALESMAN,100));

            foreach (var employee in employees)
            {
                Console.WriteLine(employee.GetSalary());
            }
        }
    }
}
