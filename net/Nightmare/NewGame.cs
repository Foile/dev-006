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
            player.SetClass(selectedText);

            stat1.Text = player.Stats[0].ToString();
            stat2.Text = player.Stats[1].ToString();
            stat3.Text = player.Stats[2].ToString();
            stat4.Text = player.Stats[3].ToString();
            stat5.Text = player.Stats[4].ToString();
            stat6.Text = player.Stats[5].ToString();
            stat7.Text = player.Stats[6].ToString();
        }

        private void button1_Click(object sender, EventArgs e) {
            var player = new Player();
            player.SetClass(comboBox1.SelectedItem.ToString());
            form1.MainStatistic = player;
            Close();
        }
    }
}