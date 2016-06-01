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
            switch (player.Class) {
                case "Warrior":
                    Equiped = true;
                    return true;
                    break;
                case "Paladin":
                    if (Mace || Sword || Dagger || Bow) {
                        Equiped = true;
                        return true;
                    }
                    else {
                        return false;
                    }

                    break;
                case "Wizard":
                    if (!Staff) {
                        return false;
                    }
                    else {
                        Equiped = true;
                        return true;
                    }
                    break;
                case "Rouge":
                    if (Dagger || Bow) {
                        Equiped = true;

                        return true;
                    }
                    else {
                        return false;
                    }
                    break;
                case "Barbarian":
                    Equiped = true;

                    return true;
                    break;
            }

            return true;
        }
    }
}