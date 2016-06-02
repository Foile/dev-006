using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2State
{
    class SalesMan : Employee
    {
        public SalesMan() 
        {
                
        }
        public override int GetSalary()
        {
            return 30*WorkHours;
        }

    }
}
