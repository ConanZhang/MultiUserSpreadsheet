using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;


namespace SS
{
    public partial class ConnectionScreen : UserControl
    {
        private SSClientModel model;
        private Form1 form;
        public ConnectionScreen()
        {
            InitializeComponent();
        }

        public void setModel(SSClientModel m)
        {
            model = m;
        }

        public void setForm(Form1 f)
        {
            form = f;
        }

        public void getText(out String spName, out String serverIp, out String serverPort)
        {
            //username = UsernameText.Text;
            spName = SpreadsheetNameText.Text;
            serverIp = ServerIpText.Text;
            serverPort = ServerPortText.Text;
        }

        public void setText(String name, String sIP, String SP)
        {
            SpreadsheetNameText.Text = name;
            ServerIpText.Text = sIP;
            ServerPortText.Text = SP;
        }
        private void ConnectButton_Click(object sender, EventArgs e)
        {
  
            try
            {
                int port = Convert.ToInt32(ServerPortText.Text);
                model.Connect(ServerIpText.Text, port, UsernameText.Text, SpreadsheetNameText.Text);

            }
            catch(SocketException s)
            {
                StatusMessage.Text = "Connection couldn't be established";
            }

         
        }



    }
}
