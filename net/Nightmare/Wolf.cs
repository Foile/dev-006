namespace Nightmare {
    public class Wolf : Enemy {
        public Wolf() {
            BaseAttack = 15;
            Defence = 30;
        }

         public override int OrdinalAttack() {
            return BaseAttack;
        }

        public override int AirAttack() {
            return 0;
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