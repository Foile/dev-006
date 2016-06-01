using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace CodeField2Subclass
{
    class Engineer : Employee
    {
        public Engineer(int aHours) : base(Employee.ENGINEER, aHours)
        {
           
        }

        public override int GetSalary()
        {
            return 200 * WorkHours;
        }
    }
}
