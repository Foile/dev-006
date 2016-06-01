using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TypeCode2Class
{
    class Person
    {
        
        private BloodGroup _bloodGroup;
        public Person(BloodGroup aBloodGroup)
        {
            _bloodGroup = aBloodGroup;
        }

        public BloodGroup bloodGroup
        {
            get { return _bloodGroup; }
        }
    }
}
