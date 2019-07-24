using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nightmare
{
    class Rouge : Profession
    {
        public Rouge() : base(new Stats(6, 11, 8, 4, 8, 9, 6), 0.7m, 1.7m)
        {
        }

        public override bool CanWear(Item item)
        {
            if (item.Type == "W")
            {
                var w = (Weapon)item;
                if (w.Dagger || w.Bow) return true;
                return false;

            }
            return true;
        }
    }
}
