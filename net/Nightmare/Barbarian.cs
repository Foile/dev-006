using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nightmare
{
    class Barbarian: Profession
    {
        public Barbarian() : base(new Stats(11, 5, 6, 3, 5, 6, 5), 1.5m, 0.9m)
        {

        }

        public override bool CanWear(Item item)
        {
            return true;
        }
    }
}
