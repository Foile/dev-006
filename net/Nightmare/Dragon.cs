using System.Collections.Generic;
using System.Linq;

namespace Nightmare {
    public class Dragon : Flying {
        public Dragon() {
            BaseAttack = 100;
            Defence = 900;
        }

        public override int OrdinalAttack() {
            return BaseAttack;
        }

        public override int AirAttack() {
             return (int) (BaseAttack * 0.4m);
        }

        public override int SpecialAttack() {
             return (int) (Level * 70);
        }

        public override int StunAttack() {
            return 0;
        }

        public override int BonusAttack() {
            return 0;
        }

        public override int OrdinalDefence() {
            return Defence;
        }

        public override int SpecialDefence() {
            return 0;
        }
    }
}