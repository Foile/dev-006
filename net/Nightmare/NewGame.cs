using System;
using System.Windows.Forms;

namespace Nightmare {
    public partial class NewGame : Form {
        private readonly Form1 form1;

        public NewGame(Form1 form1) {
            this.form1 = form1;
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e) {
            var selectedText = comboBox1.SelectedItem.ToString();
            var player = new Player();
            player.SetClass(GetClassByName(selectedText));

            stat1.Text = player.Stats.Strength.ToString();
            stat2.Text = player.Stats.Perception.ToString();
            stat3.Text = player.Stats.Endurance.ToString();
            stat4.Text = player.Stats.Charisma.ToString();
            stat5.Text = player.Stats.Intelligence.ToString();
            stat6.Text = player.Stats.Agility.ToString();
            stat7.Text = player.Stats.Luck.ToString();
        }

        private Profession GetClassByName(string className)
        {
            switch (className) {
                case "Warrior": return new Warrior();
            }
            return null;
        }

        private void button1_Click(object sender, EventArgs e) {
            var player = new Player();
            player.SetClass(GetClassByName(comboBox1.SelectedItem.ToString()));
            form1.MainStatistic = player;
            Close();
        }
    }
}