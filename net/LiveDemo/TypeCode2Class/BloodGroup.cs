using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TypeCode2Class
{
    public class BloodGroup
    {
        public  static readonly BloodGroup O = new BloodGroup(0);
        public static readonly BloodGroup A = new BloodGroup(1);
        public static readonly BloodGroup B = new BloodGroup(2);
        public static readonly BloodGroup AB = new BloodGroup(3);
        private static readonly BloodGroup[] _value = {O, A, B, AB};
        private readonly int _code ;

        private BloodGroup(int aCode)
        {
            _code = aCode;
        }

        private int getCode()
        {
            return _code;
        }

        private static BloodGroup Code(int arg)
        {
            return _value[arg];
        }

    }
}
