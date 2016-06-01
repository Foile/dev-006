using System;

namespace NullObject
{
     class EmployeeType
    {
        public static readonly EmployeeType ENGINEER = new EmployeeType(1);
        public static readonly EmployeeType SALESMAN = new EmployeeType(0);
        public static readonly EmployeeType MANAGER = new EmployeeType(2);
         public static readonly EmployeeType DIRECTOR = new EmployeeType(3);
         public static readonly EmployeeType UNKNOWN = new EmployeeType(-1);

        public int WorkHours { get; private set; }

         public virtual int GetSalary()
         {
             throw new NotImplementedException();
         }

        public int Role { get; private set; }
        
        public EmployeeType(int  Code,int aWorkHours = 0)
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
