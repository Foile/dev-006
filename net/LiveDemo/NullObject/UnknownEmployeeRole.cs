using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CodeField2Strategy;

namespace NullObject
{
    class UnknownEmployeeRole : EmployeeType
    {
        public UnknownEmployeeRole() : base(EmployeeType.UNKNOWN.Role)
        {
        }

        public override int GetSalary()
        {
            return -1;
        }

    }
}
