namespace Nightmare {
    public class Shield : Item {
        public int Id;
        public int Defence;

        public bool Equiped;

        public Shield() {
            Type = "S";
        }

        public bool CanWearFor(Player player) {
            return true;
        }
    }
}