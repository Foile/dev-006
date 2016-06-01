using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2Strategy
{
    class SalesMan : EmployeeType
    {
        public SalesMan() : base(EmployeeType.SALESMAN.Role,100)
        {
                
        }
        public override int GetSalary()
        {
            return 30*WorkHours;
        }

        public override EmployeeType Promotion()
        {
            return new Engineer();
        }
    }
}
