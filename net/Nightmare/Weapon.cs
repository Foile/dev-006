namespace Nightmare {
    public class Weapon : Item {
        public int Id;

        public bool Mace;
        public bool Sword;
        public bool Dagger;
        public bool Staff;
        public bool Bow;

        public int Attack;

        public bool Equiped;

        public Weapon() {
            Type = "W";
        }

        public bool CanWearFor(Player player) {
            if (!player.Class.CanWear(this))
            {
                return false;
            }

            Equiped = true;
            return true;
        }
    }
}