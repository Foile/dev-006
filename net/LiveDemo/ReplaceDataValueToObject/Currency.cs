using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ReplaceDataValueToObject
{
    class Currency
    {
        
        public String Code { get; private set; }
        public int Number { get; private set; }
        public Currency(String aCode,int aNumber)
        {
            Code = aCode;
            Number = aNumber;
        }

        public override bool Equals(object obj)
        {
            if (! (obj is Currency)) return false;
            Currency secondObject = (Currency) obj;
            return (Code.Equals(secondObject.Code) &&
                 Number == secondObject.Number);
            
        }

        public override int GetHashCode()
        {
            return Number.GetHashCode();
        }

        public static bool operator !=(Currency op1, Currency op2 )
        {
            return !(op1.Equals(op2));
        }
        public static bool operator ==(Currency op1, Currency op2)
        {
            return op1.Equals(op2);
        }
    }
}
