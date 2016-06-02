using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2State
{
    class Engineer : Employee
    {
        public Engineer() 
        {
                
        }
        public override int GetSalary()
        {
            return 20*WorkHours;
        }
    }
}
