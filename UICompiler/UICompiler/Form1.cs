using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UICompiler
{
    public partial class Form1 : Form
    {
        Compiler.Manager m_manager;
        // File
        public Form1()
        {
            InitializeComponent();
            m_manager = new Compiler.Manager();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void openAsToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }

        // Compile
        private void compileToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            String[] compResult = m_manager.compile(SourceCode.Text);
            Output.Lines = compResult;
            //for (int i = 0; i < )
            //Tokens.Rows.Add()
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
