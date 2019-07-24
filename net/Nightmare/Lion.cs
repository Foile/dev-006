﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nightmare
{
    public class Lion : Enemy
    {
        public Lion()
        {
            BaseAttack = 36;
            Defence = 45;
        }
        public override int OrdinalAttack()
        {
            return BaseAttack;
        }

        public override int AirAttack()
        {
            return 0;
        }

        public override int SpecialAttack()
        {
            return 0;
        }

        public override int StunAttack()
        {
            return 0;
        }

        public override int BonusAttack()
        {
            return (int)(BaseAttack * 0.5m);
        }

        public override int OrdinalDefence()
        {
            return Defence;
        }

        public override int SpecialDefence()
        {
            return 0;
        }
    }
}
