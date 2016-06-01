using System;
using System.Data.SqlServerCe;
using System.Windows.Forms;

namespace Nightmare {
    public partial class LoginForm : Form {
        private readonly Form1 form1;
        private bool ok = false;
        public Users CurrentUser;

        public LoginForm(Form1 form1) {
            this.form1 = form1;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e) {
            var con = new SqlCeConnection("DataSource=|DataDirectory|\\Database.sdf");
            var sqlCommand = new SqlCeCommand("select * from users", con);
            con.Open();
            var set = sqlCommand.ExecuteResultSet(ResultSetOptions.None);


            while (set.Read()) {
                var o = set["UserId"];
                var o1 = set["Login"];
                var o2 = set["Password"];

                if (o1.ToString() == textBox1.Text
                    && o2.ToString() == textBox2.Text) {
                    con.Close();
                    ok = true;
                    form1.User = new Users {
                        Login = o1.ToString(),
                        Password = o2.ToString()
                    };
                    Close();

                    return;
                }
            }


            con.Close();

            label3.Text = "Пароль или имя не верны";
        }

        private void LoginForm_FormClosing(object sender, FormClosingEventArgs e) {
            if (!ok) {
                e.Cancel = true;
            }
        }
    }
}