using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Refactoring
{
    class Customer
    {
        private String name;

        public String Name
        {
            get; private set;

        }

        public Customer(String aName)
        {
            name = aName;
        }
    }
}
