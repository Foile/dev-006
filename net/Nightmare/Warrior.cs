using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nightmare
{
    class Warrior: Profession
    {
        public Warrior() : base(new Stats(8, 6, 7, 9, 7, 9, 8), 1, 1)
        { }

        public override bool CanWear(Item item)
        {
            return true;
        }
    }
}
