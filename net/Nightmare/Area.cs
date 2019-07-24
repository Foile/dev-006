namespace Nightmare {
    public class Area {
        public bool IsFightArea { get; set; }
        public int DiscoverXp { get; set; }
        public bool IsSecretArea { get; set; }
        public bool IsMerchArea { get; set; }
        public AreaType AreaType { get; set; }
        public string Name { get; set; }

        public void PlayerEnter(Character character) {
            
        }
    }
}