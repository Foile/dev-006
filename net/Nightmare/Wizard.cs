using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nightmare
{
    class Wizard : Profession
    {
        public Wizard() : base(new Stats(3, 9, 4, 6, 11, 5, 5), 0.3m, 0.7m)
        {

        }

        public override bool CanWear(Item item) { 
            if (item.Type == "W")
            {
                var w = (Weapon)item;
                if (!w.Staff) return false;
            }
            return true;
        }
    }
}
        