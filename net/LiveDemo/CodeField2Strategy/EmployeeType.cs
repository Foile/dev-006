using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2Strategy
{
     class EmployeeType
    {
        public static readonly EmployeeType ENGINEER = new EmployeeType(1,0);
        public static readonly EmployeeType SALESMAN = new EmployeeType(0,0);
        public static readonly EmployeeType MANAGER = new EmployeeType(2,0);
        public static readonly EmployeeType DIRECTOR = new EmployeeType(3,0);

        public int WorkHours { get; private set; }

         public virtual int GetSalary()
         {
             throw new NotImplementedException();
         }

        public int Role { get; private set; }
        
        public EmployeeType(int  Code,int aWorkHours)
        {
            WorkHours = aWorkHours;
            Role = Code;
        }

         public virtual EmployeeType Promotion()
         {
             throw new NotImplementedException();
         }

    }
}
