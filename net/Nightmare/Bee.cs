namespace Nightmare {
    public class Bee : Flying {
        public Bee() {
            BaseAttack = 1;
            Defence = 5;
        }

        public override int OrdinalAttack() {
            return 0;
        }

        public override int AirAttack() {
            return BaseAttack;
        }

        public override int SpecialAttack() {
            return 0;
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