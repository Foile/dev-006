using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nightmare
{
    public abstract class Profession
    {
        public Profession(Stats stats, decimal hpModificator, decimal spModificator)
        {
            Stats = stats;
            HpModificator = hpModificator;
            SpModificator = spModificator;
        }

        public Stats Stats { get; }
        public decimal HpModificator { get; }
        public decimal SpModificator { get; }

        public abstract bool CanWear(Item item);
    }
}
