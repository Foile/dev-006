namespace Nightmare {
    public class Wear : Item {
        public int Id;
        public int Attack;
        public int Defence;

        public bool Equiped;

        public Wear() {
            Type = "Wr";
        }

        public bool CanWearFor(Player player) {
            return true;
        }
    }
}