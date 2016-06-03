using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NullObject;

namespace CodeField2State
{
    class Employee
    {
        public  const int ENGINEER = 1;
        public const int SALESMAN = 0;
        public const int MANAGER = 2;

        public EmployeeType Role { get; private set; }

      

        private Employee(EmployeeType role)
        {
            Role = role;
           
        }

        public void Promotion()
        {
            //if(Role == EmployeeType.SALESMAN)
            //    Role = new Engineer();
            //else if(Role == EmployeeType.ENGINEER)
            //     Role = new Manager();
            Role = Role.Promotion();
        }
        public int GetSalary()
        {
            return Role.GetSalary();
            //switch (Role.Role)
            //{
            //    case ENGINEER:
            //        return 20*WorkHours;
            //    case SALESMAN:
            //        return 30*WorkHours;
            //    case MANAGER:
            //        return 100*WorkHours;
            //    default:
            //        throw new NotImplementedException();
            //}
        }

        public static Employee Create(EmployeeType role)
        {
            if(role == EmployeeType.ENGINEER)
            return new Employee(new Engineer());
            else if(role == EmployeeType.MANAGER)
                return new Employee(new Manager());
            else if(role == EmployeeType.SALESMAN)
                return new Employee(new SalesMan());
            else if(role == EmployeeType.DIRECTOR)
                return new Employee(new Director());
            else return new Employee(new UnknownEmployeeRole());

            
        }
    }
}
