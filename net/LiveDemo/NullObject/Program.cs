using System;
using System.Collections.Generic;
using CodeField2State;

namespace NullObject
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Employee> employees = new List<Employee>();
            EmployesRepository repository = new EmployesRepository();
            for(int i=0;i<20;i++)
                employees.Add(repository.GetEmployee());

            foreach (var employee in employees)
            {
                Console.WriteLine(employee.GetSalary());
            }
        }
    }
}
