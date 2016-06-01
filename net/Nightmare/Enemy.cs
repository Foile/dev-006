using System.Collections.Generic;

namespace Nightmare {
    public abstract class Enemy {
        public int Life = 10;
        public int Stamina = 10;
        public int Xp = 3;
        public int Level = 1;
        public int BaseAttack = 1;
        public int Defence = 0;
        public int Name;

        public virtual List<Attack> Attacks() {
            return new List<Attack> {
                new Attack {
                    Defence = OrdinalDefence() + SpecialDefence(),
                    Power = OrdinalAttack() + AirAttack() + StunAttack(),
                    Special =  SpecialAttack() + BonusAttack()
                }
            };
        }

        public abstract int OrdinalAttack();
        public abstract int AirAttack();
        public abstract int SpecialAttack();
        public abstract int StunAttack();
        public abstract int BonusAttack();
        public abstract int OrdinalDefence();
        public abstract int SpecialDefence();
        
    }
}