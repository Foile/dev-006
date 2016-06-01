using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2Subclass
{
    class Manager : Employee
    {
        public Manager(int aHours) : base(Employee.MANAGER, aHours)
        {
        }

        public override int GetSalary()
        {
            return 300*WorkHours;
        }
    }
}
