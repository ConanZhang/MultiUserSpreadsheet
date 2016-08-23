using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CustomNetworking;
using System.Net.Sockets;

namespace SS
{
    public class SSClientModel
    {
        private StringSocket socket;
        public event Action<String> IncomingErrorEvent;
        public event Action<String> CellChangeEvent;
        public event Action<String> Connection;
        private Queue<String> updates;
        public String filename;
        public Object o = new Object();
        private bool proccessingQ = false;


        public SSClientModel()
        {
            socket = null;
            updates = new Queue<string>();
        }

        public void reset()
        {
            socket = null;
        }
        private void LineRecieved(string s, Exception e, object payload)
        {
            lock (o)
            { 
                updates.Enqueue(s);
                if(!proccessingQ)
                    processQ();
            }

        }

        private void processQ()
        {

            String c;
            if (updates.Count == 0)
            {
                proccessingQ = false;
                return;
            }
            else
            {

                proccessingQ = true;
                c = updates.Dequeue();
                command(c);
                processQ();
            }
            
        }

        private void command(String s)
        {
            if (!ReferenceEquals(s, null))
            {
                if (s.StartsWith("connected") && Connection != null)
                {
                    Connection(s);
                }
                else if (s.StartsWith("cell") && CellChangeEvent != null)
                {
                    CellChangeEvent(s);
                }
                else if (s.StartsWith("error") && IncomingErrorEvent != null)
                {
                    IncomingErrorEvent(s);
                }

                socket.BeginReceive(LineRecieved, null);
            }
            else
            {
                IncomingErrorEvent("error 0 Server is dead");
                socket.Close();
            }

        }
        public void Connect(string host, int port, String name, String spreadName)
        {
            if (socket == null)
            {
                try
                {
                    // host.Trim();
                    TcpClient client = new TcpClient(host.Trim(), port);
                    socket = new StringSocket(client.Client, Encoding.ASCII);
                    filename = spreadName;
                    socket.BeginReceive(LineRecieved, null);
                }
                catch (SocketException s)
                {
                    throw new SocketException();
                }
            }
                String message = "connect " + name + " " + spreadName + "\n";
                Console.WriteLine(message);
                socket.BeginSend(message, (e, p) => { }, null);
                socket.BeginReceive(LineRecieved, null);
            
        }

        public void Register(String name)
        {
            if (socket != null)
            {
                String message = "register " + name + "\n";
                Console.WriteLine(message);
                socket.BeginSend(message, (e, p) => { }, null);
                socket.BeginReceive(LineRecieved, null);
            }

        }

        public void Cell(string cellName, string cellContent)
        {
            if (socket != null)
            {
                String message = "cell " + cellName + " " + cellContent + "\n";
                Console.WriteLine(message);
                socket.BeginSend(message, (e, p) => { }, null);
                socket.BeginReceive(LineRecieved, null);
            }
        }

        public void Undo()
        {
            if (socket != null)
            {
                Console.WriteLine("UNDO");
                socket.BeginSend("undo\n", (e, p) => { }, null);
                socket.BeginReceive(LineRecieved, null);
            }
        }

    }
}
