namespace Nightmare {
    public class Eagle : Flying {
        public Eagle() {
            BaseAttack = 10;
            Defence = 50;
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