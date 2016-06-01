using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2Subclass
{
    class SalesMan : Employee
    {
        public SalesMan(int aHours) : base(Employee.SALESMAN, aHours)
        {
        }

        public override int GetSalary()
        {
            return 100 * WorkHours;
        }
    }
}
