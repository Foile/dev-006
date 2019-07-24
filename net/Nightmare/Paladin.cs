using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nightmare
{
    class Paladin : Profession
    {
        public Paladin() : base(new Stats(9, 5, 8, 11, 5, 6, 2), 1, 1.2m)
        {
        }

        public override bool CanWear(Item item)
        {
            if (item.Type == "W")
            {
                var w = (Weapon)item;
                if (w.Mace || w.Sword || w.Dagger || w.Bow) return true;
                return false;

            }
            return true;
        }
    }
}
