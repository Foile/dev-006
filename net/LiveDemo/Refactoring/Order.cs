using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Refactoring
{
    class Order
    {
        private Customer customer;

        public Order(Customer aCustomer)
        {
            aCustomer = customer;
        }
        public Customer Customer
        {
            get { return customer; }           
        }
    }
}
